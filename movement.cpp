#include "Movement.h"
#include "Pixy.h"

Movements::Movements()
{
  front_left_motor_ = Motor(frontLeftMotorPins[0], frontLeftMotorPins[1], frontLeftPwm);
  front_right_motor_ = Motor(frontRightMotorPins[0], frontRightMotorPins[1], frontRightPwm);
  back_left_motor_ = Motor(backLeftMotorPins[0], backLeftMotorPins[1], backLeftPwm);
  back_Right_motor_ = Motor(backRightMotorPins[0], backRightMotorPins[1], backRightPwm);
}

void Movements::move0()
{
  setSpeed(230.0);
  front_left_motor_.forward();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.forward();
}

void Movements::move45()
{
  setSpeed(180.0);
  front_left_motor_.forward();
  front_right_motor_.stop();
  back_left_motor_.stop();
  back_right_motor_.forward();
}

void Movements::move90()
{
  setSpeed(230.0);
  front_left_motor_.forward();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.forward();
}

void Movements::move135()
{
  setSpeed(180.0);
  front_left_motor_.stop();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.stop();
}

void Movements::move180()
{
  setSpeed(230.0);
  front_left_motor_.backward();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.backward();
}

void Movements::move225()
{
  setSpeed(180.0);
  front_left_motor_.backward();
  front_right_motor_.stop();
  back_left_motor_.stop();
  back_right_motor_.backward();
}

void Movements::move270()
{
  setSpeed(230.0);
  front_left_motor_.backward();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.backward();
}

void Movements::move315()
{
  setSpeed(180.0);
  front_left_motor_.stop();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.stop();
}

void Movements::setSpeed(float data)
{
  front_left_motor_.changePwm(data);
  front_right_motor_.changePwm(data);
  back_left_motor_.changePwm(data);
  back_right_motor_.changePwm(data);
}

void Movements::setDirection(int angle)
{
  switch (angle)
  {
  case 0: //Forward.
    move0();
    break;

  case 45: //Diagonl front right.
    move45();
    break;

  case 90: //Right.
    move90();
    break;

  case 135: //Diagonal back right.
    move135();
    break;

  case 180: //Backwards.
    move180();
    break;

  case 225: //Diagonal back left.
    move225();
    break;

  case 270: //Left.
    move270();
    break;

  case 315: //Diagonal front left.
    move315();
    break;
  }
}

void Movements::angleMovement(int angle)
{
  /* 
  *  This funtcion allows the robot to move in the angle specified, the front of the robot should.
  *  The function simulates a plane, where the front of the robot would the angle 0, it goes
  *  in a clockwise motion, meaning that using a 90 degrees angle, would make the robot go to the right.
  */
  float pi = 3.141592;
  //Add 45 to the angle so it centers eith the front of the robot.
  int realAngle = angle + 45;
  //Check if the value is correct.
  if (realAngle > 359)
  {
    realAngle -= 360;
  }
  //Convert the angle to radians.
  float gradRadian = (realAngle * pi) / 180;
  //Variables for the resulting pwm of the function.
  float pwmM1M3 = 230 * sin(gradRadian);
  float pwmM2M4 = 230 * cos(gradRadian);
  //If the pwm is negative, this bools will be used to tell the motor to go backwards.
  bool orientationM1M3 = 0, orientationM2M4 = 0;

  //If pwm is negative, the value of the bools changes to true, and the pwm is inverted.
  if (pwmM1M3 < 0)
  {
    orientationM1M3 = true;
    pwmM1M3 *= -1;
  }
  if (pwmM2M4 < 0)
  {
    orientationM2M4 = true;
    pwmM2M4 *= -1;
  }

  //Since the value is true, the motors will go backwards.
  if (orientationM1M3)
  {
    front_left_motor_.changePwm(pwmM1M3);
    back_right_motor_.changePwm(pwmM1M3);
    front_left_motor_.backward();
    back_right_motor_.backward();
  }
  //When the value is false, it will go forward.
  if (!orientationM1M3)
  {
    front_left_motor_.changePwm(pwmM1M3);
    back_right_motor_.changePwm(pwmM1M3);
    front_left_motor_.forward();
    back_right_motor_.forward();
  }
  //The same applies for the bool controling de front_right_motor_ and the back_left_motor_.
  if (orientationM2M4)
  {
    front_right_motor_.changePwm(pwmM2M4);
    back_left_motor_.changePwm(pwmM2M4);
    front_right_motor_.backward();
    back_left_motor_.backward();
  }
  if (!orientationM2M4)
  {
    front_right_motor_.changePwm(pwmM2M4);
    back_left_motor_.changePwm(pwmM2M4);
    front_right_motor_.forward();
    back_left_motor_.forward();
  }
}

//Function used to stop the robot.
void Movements::stop()
{
  front_left_motor_.stop();
  front_right_motor_.stop();
  back_left_motor_.stop();
  back_right_motor_.stop();
}
