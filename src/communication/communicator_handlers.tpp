namespace msg = protocol::message;

template <typename M>
void Communicator::on(const M& m) {
}

template <>
inline void Communicator::on(const msg::heartbeat_message_t& m) {
  msg::heartbeat_message_t message {
    .seq = m.seq
  };

  send(message);
}

template <>
inline void Communicator::on(const msg::set_control_mode_message_t& m) {
  if(m.mode == msg::set_control_mode_message_t::ControlMode::MANUAL) {
  } else if(m.mode == msg::set_control_mode_message_t::ControlMode::OFFBOARD) {
  }
}
