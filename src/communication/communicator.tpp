template <typename M>
void Communicator::on(const M& m) {
  for(auto listener : listeners) {
    if(listener != nullptr) {
      listener->on(m);
    }
  }
}

template <typename M>
void Communicator::send(const M& message) {
  std::array<std::uint8_t, 255> encodeBuffer;
  std::uint16_t len = encoder.encode(message, &encodeBuffer);

  // Offload work onto the writer thead.
  writer.append(encodeBuffer, len);
}

template <typename M, std::size_t buffer_size>
static const M& packet_cast(const protocol::decoded_message_t<buffer_size>& decoded) {
  return reinterpret_cast<const M&>(decoded.payload);
}

template <std::size_t buffer_size>
void Communicator::dispatch(const protocol::decoded_message_t<buffer_size>& decoded) {
  // TODO(kyle): Is there a way to do this without a giant switch?
  switch(decoded.id) {
    case protocol::message::heartbeat_message_t::ID:
      on(packet_cast<protocol::message::heartbeat_message_t>(decoded));
      break;
    case protocol::message::log_message_t::ID:
      on(packet_cast<protocol::message::log_message_t>(decoded));
      break;
    case protocol::message::attitude_message_t::ID:
      on(packet_cast<protocol::message::attitude_message_t>(decoded));
      break;
    case protocol::message::set_arm_state_message_t::ID:
      on(packet_cast<protocol::message::set_arm_state_message_t>(decoded));
    case protocol::message::set_control_mode_message_t::ID:
      on(packet_cast<protocol::message::set_control_mode_message_t>(decoded));
      break;
    case protocol::message::offboard_attitude_control_message_t::ID:
      on(packet_cast<protocol::message::offboard_attitude_control_message_t>(decoded));
      break;
  }
}

