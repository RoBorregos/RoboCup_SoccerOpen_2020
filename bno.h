#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class Bno
{
public:
    Bno();
    void checkAngle();
    void checkLift();

private:
    Adafruit_BNO055 bnoSensor;
    int angle = 0;
    bool lift = 0;
};