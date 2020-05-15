#include "strategy.h"
#include "Pixy.h"

//Constructor for the trategy class.
Strategy::Strategy()
{
    robot_ = Movements();
}

//Function used to follow the ball.
void Strategy::followBall()
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
    pixy.pixyCam(1);

    int caso = -1;

    if (((pixy.ballX > 125) && (pixy.ballX < 150)) && pixy.ballY < 25)
    {
        caso = 0;
    }
    else if ((pixy.ballX > 135) && (pixy.ballX < 185))
    {
        caso = 1;
    }
    else if (pixy.ballX > 185)
    {
        if (pixy.ballY > 120)
        {
            caso = 2;
        }
        else if (pixy.ballY < 120)
        {
            caso = 4;
        }
    }
    else if (pixy.ballX < 135)
    {
        if (pixy.ballY > 120)
        {
            caso = 3;
        }
        else if (pixy.ballY < 120)
        {
            caso = 5;
        }
    }

    switch (caso)
    {

    case -1:
        while (pixy.ballX == -1)
        {
            int m = 0;
            if (m <= 1)
            {
                robot_.setDirection(90);
                delay(150);
                robot_.stop();
                delay(1);
                pixy.pixyCam(1);
                m++;
            }
            else
            {
                robot_.setDirection(270);
                delay(300);
                robot_.stop();
                delay(1);
                pixy.pixyCam(1);
                m = 0;
            }
        }
        break;

    case 0:
        break;

    case 1:
        robot_.setDirection(0);
        delay(25);
        robot_.stop();
        delay(5);
        break;

    case 2:
        robot_.setDirection(315);
        delay(25);
        robot_.stop();
        delay(5);
        break;

    case 3:
        robot_.setDirection(45);
        delay(25);
        robot_.stop();
        delay(5);
        break;

    case 4:
        robot_.setDirection(225);
        delay(25);
        robot_.stop();
        delay(5);
        break;

    case 5:
        robot_.setDirection(135);
        delay(25);
        robot_.stop();
        delay(5);
        break;
    }
}

//Function for the first strategy.
void Strategy::strategy1()
{
 /*
 * Cases
 * 1 - The robot doesn't has possession of the ball - 'seguirPelota()' is called
 * 'seguirPelota()' when the robot gains possession of the ball, the next case is called
 * 2 - The robot has posession of the ball - The robot will make diagonal front movements depending on its location
 * on the field. If the goal is to the left of the image, the robot will make a diagonal right movement, and when it reaches
 * the sideline, it will change to a diagonal left movement.
 */
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

    case 2:
        if (pixy.blueGoalX > 140)
        { //Goal to the left of the image.
            while (onWhiteLine)
            {
                robot_.setDirection(315); //Diagonal forward left.
            }
            robot_.setDirection(45); //Diagonal forward right.
        }
        else
        { //Goal to the right of the image.
            while (onWhiteLine)
            {
                robot_.setDirection(45); //Diagonal forward right.
            }
            robot_.angleMovement(315); //Diagonal forward left.
        }
    }
}

//Function for the second strategy.
void Strategy::strategy2()
{
    /* 
 * 1 = Goal to the right (Robot in the left of the field)
 * 2 = Goal to the left (Robot in the right of the field)
 * 3 = Goal to the front
 */
    int action = -1;
    bool possession = 0;
    pixy.pixyCam(2);

    if (pixy.blueGoalX != -1)
    {
        if (pixy.blueGoalX < 135)
        {
            action = 1;
        }
        if (pixy.blueGoalX > 185)
        {
            action = 2;
        }
        if ((pixy.blueGoalX > 135) && (pixy.blueGoalX < 185))
        {
            action = 3;
        }
    }
    else
    {
        action = 0;
    }

    switch (action)
    {

    case 0:
        followBall();
        break;

    case 1:
        while (pixy.blueGoalX < 135)
        {
            robot_.setDirection(0);
            delay(20);
            robot_.stop();
            delay(5);
            robot_.angleMovement(15);
            delay(15);
            robot_.stop();
            delay(1);
            pixy.pixyCam(2);
        }
        break;

    case 2:
        while (pixy.blueGoalX > 185)
        {
            robot_.setDirection(0);
            delay(20);
            robot_.stop();
            delay(5);
            robot_.angleMovement(345);
            delay(15);
            robot_.stop();
            delay(1);
            pixy.pixyCam(2);
        }
        break;

    case 3:
        while ((pixy.blueGoalX > 135) && (pixy.blueGoalX < 185))
        {
            robot_.setDirection(0);
            delay(30);
            robot_.stop();
            delay(1);
            pixy.pixyCam(2);
        }
        break;
    }
}
