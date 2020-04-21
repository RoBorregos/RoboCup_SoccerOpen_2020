#include "movement.h"
#include "pixy.h"

front_left_motor_ = Motor(frontLeftMotorPins[0], frontLeftMotorPins[1], frontLeftPwm);
front_right_motor_ = Motor(frontRightMotorPins[0], frontRightMotorPins[1], frontRightPwm);
back_left_motor_ = Motor(backLeftMotorPins[0], backLeftMotorPins[1], backLeftPwm);
back_Right_motor_ = Motor(backRightMotorPins[0], backRightMotorPins[1], backRightPwm);

void Movements::move0()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.forward();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.forward();
}

void Movements::move45()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.forward();
  front_right_motor_.stop();
  back_left_motor_.stop();
  back_right_motor_.forward();
}

void Movements::move90()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.forward();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.forward();
}

void Movements::move135()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.stop();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.stop();
}

void Movements::move180()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.backward();
  front_right_motor_.backward();
  back_left_motor_.backward();
  back_right_motor_.backward();
}

void Movements::move225()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.backward();
  front_right_motor_.stop();
  back_left_motor_.stop();
  back_right_motor_.backward();
}

void Movements::move270()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.backward();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.backward();
}

void Movements::move315()
{
  front_left_motor_.changePwm(230.0);
  front_right_motor_.changePwm(230.0);
  back_left_motor_.changePwm(230.0);
  back_right_motor_.changePwm(230.0);
  front_left_motor_.stop();
  front_right_motor_.forward();
  back_left_motor_.forward();
  back_right_motor_.stop();
}

void Movements::movement(int angle)
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
  /* This funtcion allows the robot to move in the angle specified, the front of the robot should.
  *  The function simulates a plane, where the front of the robot would the angle 0, it goes
  *  in a clockwise motion, meaning that using a 90 degrees angle, would make the robot go to the right.
  */
  float pi = 3.141592;
  int realAngle = angle + 45;
  if (realAngle > 359)
  {
    realAngle -= 360;
  }
  float gradRadian = (realAngle * pi) / 180;
  float pwm1 = 0, pwm2 = 0;
  bool m1 = 0, m2 = 0;
  float vc = 230;
  pwm1 = vc * sin(gradRadian);
  pwm2 = vc * cos(gradRadian);

  if (pwm1 < 0)
  {
    m1 = true;
    pwm1 *= -1;
  }
  if (pwm2 < 0)
  {
    m2 = true;
    pwm2 *= -1;
  }

  if (m1)
  {
    front_left_motor_.changePwm(pwm1);
    back_right_motor_.changePwm(pwm1);
    front_left_motor_.backward();
    back_right_motor_.backward();
  }
  if (!m1)
  {
    front_left_motor_.changePwm(pwm1);
    back_right_motor_.changePwm(pwm1);
    front_left_motor_.forward();
    back_right_motor_.forward();
  }
  if (m2)
  {
    front_right_motor_.changePwm(pwm2);
    back_left_motor_.changePwm(pwm2);
    front_right_motor_.backward();
    back_left_motor_.backward();
  }
  if (!m2)
  {
    front_right_motor_.changePwm(pwm2);
    back_left_motor_.changePwm(pwm2);
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

//Function used to follow the ball.
void Movements::seguirPelota()
{
  /*  
 *  -1 = Ball wasn't detected
 *  0 = Possession of ball. This case is used to end the function.
 *  1 = Ball in the middle of the image. In this case the robot should only advance straight forward.
 *  2 = Ball in the top left part of the image.
 *  3 = Ball in the top right part of the image.
 *  4 = Ball in the bottom left part of the image.
 *  5 = Ball in the bottom right part of the image.
 */
  pixy_.pixyCam(1);

  int caso = -1;

  if (((pixy_.pelotaX > 125) && (pixy_.pelotaX < 150)) && pixy_.pelotaY < 25)
  {
    caso = 0;
  }
  else if ((pixy_.pelotaX > 135) && (pixy_.pelotaX < 185))
  {
    caso = 1;
  }
  else if (pixy_.pelotaX > 185)
  {
    if (pixy_.pelotaY > 120)
    {
      caso = 2;
    }
    else if (pixy_.pelotaY < 120)
    {
      caso = 4;
    }
  }
  else if (pixy_.pelotaX < 135)
  {
    if (pixy_.pelotaY > 120)
    {
      caso = 3;
    }
    else if (pixy_.pelotaY < 120)
    {
      caso = 5;
    }
  }

  switch (caso)
  {

  case -1:
    while (pixy_.pelotaX == -1)
    {
      int m = 0;
      if (m <= 1)
      {
        movement(90);
        delay(150);
        stop();
        delay(50);
        pixy_.pixyCam(1);
        m++;
      }
      else
      {
        movement(270);
        delay(300);
        stop();
        delay(50);
        pixy_.pixyCam(1);
        m = 0;
      }
    }
    break;

  case 0:
    break;

  case 1:
    movement(0);
    delay(25);
    stop();
    delay(5);
    break;

  case 2:
    movement(315);
    delay(25);
    stop();
    delay(5);
    break;

  case 3:
    movement(45);
    delay(25);
    stop();
    delay(5);
    break;

  case 4:
    movement(225);
    delay(25);
    stop();
    delay(5);
    break;

  case 5:
    movement(135);
    delay(25);
    stop();
    delay(5);
    break;
  }
}

/*
 * Cases
 * 1 - The robot doesn't has possession of the ball - 'seguirPelota()' is called
 * 'seguirPelota()' when the robot gains possession of the ball, the next case is called
 * 2 - The robot has posession of the ball - The robot will make diagonal front movements depending on its location
 * on the field. If the goal is to the left of the image, the robot will make a diagonal right movement, and when it reaches
 * the sideline, it will change to a diagonal left movement.
 */

/*void estrategia1(){
  int caso = 1;

  if(tienesPelota != false){
    caso = 2;  
  }

  switch (caso){

    case 1:
      seguirPelota();
    break;
    
    case 2;
      if(porteriaRivalX > 140){ //Goal to the left of the camera
        while(notOnWhiteLine){
          movement(6); //Diagonal forward left
        }
        movimiento(7); //Diagonal forward right
      } else{
        while(notOnWhiteLine){
          movement(7);
        }
        movement(6);
      }
  } 
}
*/

/* 
 * 1 = Goal to the right (Robot in the left of the field)
 * 2 = Goal to the right (Robot in the right of the field)
 * 3 = Goal to the front
 */

/*
void ataca(){
  
  
  int accion = -1;
  checaPosesion();
  pixyCam(PorteriaRival)

  if(porteriaRivalX != -1){
    if(porteriaRivalX < 135){
      accion = 1;
    }
    if(porteriaRivalX > 185){
      accion = 2;
    }
  }
    if((porteriaRivalX > 135) && (porteriaRivalX < 185)){
      accion = 3;
    }

  switch(accion){

    case 1:
      while(porteriaAzulX < 135){
        movement(1);
        delay(20);
        movement(9);
        delay(5);
        angleMovement(345);
        movement(1);
        delay(15);
        movimiento(9);
        delay(1);
        pixyCam(PorteriaRival);
      }
      break;

    case 2:
      while(porteriaRivalX > 185){
        movement(1);
        delay(20);
        movement(9);
        delay(5);
        angleMovement(15);
        movement(1);
        delay(15);
        movimiento(11);
        delay(1);
        pixyCam(PorteriaRival);
      }
    break;
    
    case 3:
      while((porteriaRivalX > 135) && (porteriaRivalX < 185)){
        movement(1);
        delay(30);
        movement(9);
        delay(1);
        pixyCam(PorteriaRival);
      }
      break;
  }
  
}
*/