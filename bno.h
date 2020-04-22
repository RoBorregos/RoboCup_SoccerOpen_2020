#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

class Bno
{
public:
    Bno();
    void checkAngle();
    void checkLift();
    int angle = 0;
    bool lift = 0;
};

private:
Adafruit_BNO055 bnoSensor;
}