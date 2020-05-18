#include "motor.h"

class Movements
{
public:
  //Motors initialization.
  Motor front_left_motor_;
  Motor front_right_motor_;
  Motor back_left_motor_;
  Motor back_right_motor_;

  Movements();
  //Move in 8 standard angles.
  void setDirection(int angle);
  //Stop the robot.
  void stop();
  //Move in non standard angles.
  void angleMovement(int angle);
  //Set a standard pwm for all motors.
  void setSpeed(int data);

private:
  void move0();
  void move45();
  void move90();
  void move135();
  void move180();
  void move225();
  void move270();
  void move315();
  int frontLeftMotorPins[2] = {10, 9};   //Pins for the front left motor. First backwards, then forward.
  int frontRightMotorPins[2] = {30, 16}; //Pins for the front right motor. First backwards, then forward.
  int backLeftMotorPins[2] = {11, 12};   //Pins for the back left motor. First backwards, then forward.
  int backRightMotorPins[2] = {18, 17};  //Pins for the back right motor. First backwards, then forward.
  int frontLeftPwm = 5;                  //Pin of the front left motor pwm.
  int frontRightPwm = 8;                 //Pin of the front right motor pwm.
  int backLeftPwm = 13;                  //Pin of the back left motor pwm.
  int backRightPwm = 4;                  //Pin of the back right motor pwm.
};
