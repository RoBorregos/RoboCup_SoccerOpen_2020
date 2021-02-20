#include "movement.h"

class Strategy
{
public:
    //Strategy class constructor.
    Strategy();
    //Movements objects inisialization.
    Movements robot_;
    //Function used to follow the ball.
    void followBall();
    //Pseudocode for the first strategy.
    void strategy1();
    //Pseudocode for the second strategy.
    void strategy2();
};
