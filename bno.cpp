#include "bno.h"

Bno::Bno()
{
    bnoSensor = Adafruit_BNO055(55);
}

//Obtain an int with the X value of the BNO055.
void Bno::checkAngle()
{
    sensors_event_t event;
    bnoSensor.getEvent(&event);
    bnoSensor.angle = event.orientation.x;
    lcd.clear();
    lcd.print("Angulo: ");
    lcd.setCursor(0, 1);
    lcd.print(angle);
    lcd.setCursor(0, 0);
}

//Check if the robot is on or off the ground.
void Bno::checkLift()
{
    bool lift = 0;
    sensors_event_t event;
    bno.getEvent(&event);
    int height = event.orientation.y;
    if (height > 10)
    {
        bnoSensor.lift = true;
    }
    else
    {
        bnoSensor.lift = false;
    }
}
