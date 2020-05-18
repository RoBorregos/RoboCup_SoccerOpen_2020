#include "Bno.h"
#include "Motor.h"
#include "Movement.h"
#include "Pixy.h"
#include "Strategy.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

void setup()
{
    Bno bno;
    Strategy robot;
    bno.checkAngle();
    bno.checkLift();
    robot.followBall();
}

void loop()
{
}
