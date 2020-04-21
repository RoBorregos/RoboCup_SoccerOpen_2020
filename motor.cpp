#include "motor.h"

//The space '0' of the array is used to make the robot go backwards. While the space '1' is front.
Motor::Motor(const int motorBackwards_, const int motorForward_, const int analogPin_)
{
    motor[0] = motorBackwards_;
    motor[1] = motorForward_;
    analogPin = analogPin_;
    pwm = 230.0;
}

void Motor::forward()
{
    analogWrite(analogPin, pwm);
    digitalWrite(motorForward, HIGH);
    digitalWrite(motorBackwards, LOW);
}

void Motor::backward()
{
    analogWrite(analogPin, pwm);
    digitalWrite(motorForward, LOW);
    digitalWrite(motorBackwards, HIGH);
}

void Motor::stop()
{
    digitalWrite(motorForward, LOW);
    digitalWrite(motorBackwards, LOW);
}

void Motor::changePwm(float data)
{
    pwm = data;
}
