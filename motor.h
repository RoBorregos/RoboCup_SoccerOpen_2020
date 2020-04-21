class Motor
{
public:
    Motor(const int motorBackwards_, const int motorForward_, const int analogPin_);

    void forward();
    void backward();
    void stop();
    void changePwm(int data);

private:
    int motorBackwards;
    int motorForward;
    int analogPin;
    float pwm = 0;
};