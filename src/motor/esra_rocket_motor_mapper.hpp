#ifndef ESRA_ROCKET_MOTOR_MAPPER_HPP_
#define ESRA_ROCKET_MOTOR_MAPPER_HPP_

#include "communication/communicator.hpp"
#include "communication/rate_limited_stream.hpp"
#include "controller/setpoint_types.hpp"
#include "motor/motor_mapper.hpp"
#include "motor/pwm_device_group.hpp"

class EsraRocketMotorMapper : public MotorMapper {
public:
  EsraRocketMotorMapper(PWMDeviceGroup<1>& servos, Communicator& communicator);

  void run(bool armed, ActuatorSetpoint& input) override;

private:
  PWMDeviceGroup<1> servos;
  RateLimitedStream throttleStream;
};

#endif
