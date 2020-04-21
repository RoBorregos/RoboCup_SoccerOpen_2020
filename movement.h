#include "motor.h"

class Movements
{
public:
  //Motors inisialization.
  Motor front_right_motor_;
  Motor front_left_motor_;
  Motor back_right_motor_;
  Motor back_left_motor_;

  Movements();
  //Move in 8 standard angles.
  void movement(int angle);
  //Stop the robot.
  void stop();
  //Move in non standard angles.
  void angleMovement(int angle);
  void seguirPelota();

private:
  void move0();
  void move45();
  void move90();
  void move135();
  void move180();
  void move225();
  void move270();
  void move315();
  static constexpr int frontLeftMotorPins[2] = {10, 9};
  static constexpr int frontRightMotorPins[2] = {30, 16};
  static constexpr int backLeftMotorPins[2] = {11, 12};
  static constexpr int backRightMotorPins[2] = {18, 17};
  static constexpr int frontLeftPwm = 5;
  static constexpr int frontRightPwm = 8;
  static constexpr int backLeftPwm = 13;
  static constexpr int backRightPwm = 4;
};
