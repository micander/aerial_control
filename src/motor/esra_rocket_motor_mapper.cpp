#include "motor/esra_rocket_motor_mapper.hpp"

#include <array>
#include <cstddef>
#include <cmath>

EsraRocketMotorMapper::EsraRocketMotorMapper(PWMDeviceGroup<1>& motors, Communicator& communicator, Logger& logger)
  : motors(motors),
    throttleStream(communicator, 5),
    logger(logger) {
}

void EsraRocketMotorMapper::run(bool armed, ActuatorSetpoint& input) {
  // Interpret input roll as servo angle
  std::array<float, 1> outputs { input.roll };
  motors.set(armed, outputs);
}
