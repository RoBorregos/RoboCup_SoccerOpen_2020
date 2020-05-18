#include "Bno.h"

Bno::Bno()
{
    bnoSensor = Adafruit_BNO055(55);
}

//Obtain an int with the X value of the BNO055.
void Bno::checkAngle()
{
    sensors_event_t event;
    bnoSensor.getEvent(&event);
    angle = event.orientation.x;
}

//Check if the robot is on or off the ground.
void Bno::checkLift()
{
    sensors_event_t event;
    bnoSensor.getEvent(&event);
    int height = event.orientation.y;
    if (height > 10)
    {
        lift = true;
    }
    else
    {
        lift = false;
    }
}
