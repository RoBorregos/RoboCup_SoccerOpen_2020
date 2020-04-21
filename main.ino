#include "bno.h"
#include "motor.h"
#include "movement.h"
#include "pixy.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

void setup(){

}

void loop(){
    Bno bno_sensor1;
    Movements robot;
    bno_sensor1.checkAngle();
    bno_sensor1.checkLift();
    robot.movement(0);
    delay(100);
    robot.stop();
    delay(100);
    robot.angleMovement(15);
    delay(100);
    robot.stop();
    delay(100);
}