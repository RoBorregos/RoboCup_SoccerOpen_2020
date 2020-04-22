#include "Bno.h"
#include "Motor.h"
#include "Movement.h"
#include "Pixy.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

void setup()
{
    Bno bno;
    Movements robot;
    bno.checkAngle();
    bno.checkLift();
    robot.setDirection(0);
    delay(100);
    robot.stop();
    delay(100);
    robot.angleMovement(15);
    delay(100);
    robot.stop();
    delay(100);
}

void loop()
{
}