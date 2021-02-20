#include <Arduino.h>

class Motor
{
public:
    Motor(const int motorBackwards_, const int motorForward_, const int analogPin_);

    void forward();             //Sets motor to spin forward.
    void backward();            //Sets motor to spin backards.
    void stop();                //Makes motor stop spinning.
    void changePwm(int data); //Changes the pwm of the motor.

private:
    int motorBackwards;
    int motorForward;
    int analogPin;
    int pwm = 0;
};
