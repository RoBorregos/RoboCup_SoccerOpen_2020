#include "Movement.h"
#include "Pixy.h"

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

//Function used to follow the ball.
void Movements::followBall()
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
        setDirection(90);
        delay(150);
        stop();
        delay(1);
        pixy_.pixyCam(1);
        m++;
      }
      else
      {
        setDirection(270);
        delay(300);
        stop();
        delay(1);
        pixy_.pixyCam(1);
        m = 0;
      }
    }
    break;

  case 0:
    break;

  case 1:
    setDirection(0);
    delay(25);
    stop();
    delay(5);
    break;

  case 2:
    setDirection(315);
    delay(25);
    stop();
    delay(5);
    break;

  case 3:
    setDirection(45);
    delay(25);
    stop();
    delay(5);
    break;

  case 4:
    setDirection(225);
    delay(25);
    stop();
    delay(5);
    break;

  case 5:
    setDirection(135);
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
void Movements::strategy1()
{
  int cases = 1;
  bool ballPossession; //Boolean used to check if the robot has possession of the ball.
  bool onWhiteLine;    //Boolean used to check if the robot is on top of a white line.

  if (ballPossession != false)
  {
    cases = 2;
  }

  switch (cases)
  {

  case 1:
    followBall();
    break;

    case 2;
      if(blueGoalX > 140){ //Goal to the left of the image.
        while(onWhiteLine){
          setDirection(315); //Diagonal forward left.
        }
        setDirection(45); //Diagonal forward right.
      } else{ //Goal to the right of the image.
        while(onWhiteLine){
          movement(45); //Diagonal forward right.
        }
        movement(315);//Diagonal forward left.
      }
  } 
}


/* 
 * 1 = Goal to the right (Robot in the left of the field)
 * 2 = Goal to the right (Robot in the right of the field)
 * 3 = Goal to the front
 */
void Movements::strategy2(){
  
  
  int action = -1;
  bool possession = 0;
  pixyCam(2);

  if(blueGoalX != -1){
    if(blueGoalX < 135){
      action = 1;
    }
    if(blueGoalX > 185){
      action = 2;
    }
    if((blueGoalX > 135) && (blueGoalX < 185)){
      action = 3;
    }
  } else {
    action = 0;
  }
    

  switch(action){

    case 0:
      followBall();
      break;

    case 1:
      while (blueGoalX < 135)
      {
        setDirection(0);
        delay(20);
        stop();
        delay(5);
        angleMovement(15);
        setDirection(0);
        delay(15);
        stop();
        delay(1);
        pixyCam(2);
      }
      break;

    case 2:
      while (blueGoalX > 185)
      {
        setDirection(0);
        delay(20);
        stop();
        delay(5);
        angleMovement(345);
        setDirection(0);
        delay(15);
        stop();
        delay(1);
        pixyCam(2);
      }
      break;

    case 3:
      while ((blueGoalX > 135) && (blueGoalX < 185))
      {
        setDirection(0);
        delay(30);
        stop();
        delay(1);
        pixyCam(2);
      }
      break;
    }
}
