#include <Pixy2.h>

class Pixy
{
public:
  pixy();
  void pixyCam(int objeto);
  void pixyImage();
  int ballX = -1;
  int ballY = -1;
  int blueGoalX = -1;
  int blueGoalY = -1;
  int yellGoalX = -1;
  int yellGoalY = -1;
  int lastBallX = -1;
  int lastBallY = -1;

private:
  Pixy2 pixy_;
};
