#ifndef MESSAGE_LISTENER_HPP_
#define MESSAGE_LISTENER_HPP_

#include "protocol/messages.hpp"

// Forward declaration
class Communicator;

/**
 * Overloads callbacks for all message types.
 *
 * To use, override the `on` methods you are interested in.
 */
class MessageListener {
public:
  // TODO: Any way to do this without explicitly overloading for each message
  // type? Can't use templates because they can't be virtual.
  virtual void on(const protocol::message::heartbeat_message_t& m) {}
  virtual void on(const protocol::message::log_message_t& m) {}
  virtual void on(const protocol::message::attitude_message_t& m) {}
  virtual void on(const protocol::message::set_arm_state_message_t& m) {}
  virtual void on(const protocol::message::set_control_mode_message_t& m) {}
  virtual void on(const protocol::message::offboard_attitude_control_message_t& m) {}

protected:
  MessageListener(Communicator& communicator);
};

#endif
