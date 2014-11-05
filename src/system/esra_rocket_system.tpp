EsraRocketSystem::EsraRocketSystem(Accelerometer *accelerometer, Gyroscope *gyroscope)
  : accelerometer(accelerometer),
    gyroscope(gyroscope) {
}

void EsraRocketSystem::init() {
  RocketSystem::init();

  motorMapper.init();
}

void EsraRocketSystem::update() {
  RocketSystem::update();
}

Accelerometer *EsraRocketSystem::getAccelerometer() {
  return accelerometer;
}

Gyroscope *EsraRocketSystem::getGyroscope() {
  return gyroscope;
}

AttitudeEstimator *EsraRocketSystem::getAttitudeEstimator() {
  return &estimator;
}

InputSource *EsraRocketSystem::getInputSource() {
  return &inputSource;
}

MotorMapper *EsraRocketSystem::getMotorMapper() {
  return &motorMapper;
}

actuator_setpoint_t EsraRocketSystem::runController(attitude_estimate_t &estimate, angular_position_setpoint_t& setpoint) {
  return pipeline.run(estimate, setpoint, attPosController, attVelController);
}
