#ifndef MULTIROTOR_SYSTEM_HPP_
#define MULTIROTOR_SYSTEM_HPP_

#include "system/vehicle_system.hpp"
#include "util/optional.hpp"

// Communication
#include "communication/communicator.hpp"
#include "communication/message_listener.hpp"

// Control
#include "controller/angular_position_controller.hpp"
#include "controller/angular_velocity_controller.hpp"
#include "controller/angular_acceleration_controller.hpp"
#include "controller/position_controller.hpp"
#include "controller/controller_pipeline.hpp"
#include "controller/setpoint_types.hpp"
#include "controller/zero_controller.hpp"
#include "input/input_source.hpp"
#include "motor/motor_mapper.hpp"
#include "motor/pwm_device_group.hpp"

// World estimation
#include "estimator/world_estimator.hpp"

// Sensors
#include "sensor/accelerometer.hpp"
#include "sensor/gps.hpp"
#include "sensor/gyroscope.hpp"
#include "sensor/magnetometer.hpp"

enum class MultirotorControlMode {
  POSITION,
  VELOCITY,
  ANGULAR_POS,
  ANGULAR_RATE,
};

class MultirotorVehicleSystem : public VehicleSystem, public MessageListener {
public:
  MultirotorVehicleSystem(
      Gyroscope& gyroscope,
      Accelerometer& accelerometer,
      optional<GPS *> gps,
      optional<Magnetometer *> magnetometer, // TODO: Use reference_wrapper?
      WorldEstimator& estimator,
      InputSource& inputSource,
      MotorMapper& motorMapper,
      Communicator& communicator);

  void update() override;
  bool healthy();

  void on(const protocol::message::set_arm_state_message_t& m) override;

private:
  Gyroscope& gyroscope;
  Accelerometer& accelerometer;
  optional<GPS *> gps;
  optional<Magnetometer *> magnetometer;

  WorldEstimator& estimator;
  InputSource& inputSource;

  PositionController posController;
  AngularPositionController attPosController;
  AngularVelocityController attVelController;
  AngularAccelerationController attAccController;
  ControllerPipeline<ActuatorSetpoint> pipeline;

  ZeroController<ActuatorSetpoint> zeroController;

  MotorMapper& motorMapper;

  MultirotorControlMode mode;
};

#endif
