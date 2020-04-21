#include <Pixy2.h>

class Pixy
{
public:
  pixy();
  void pixyCam(int objeto);
  void pixyImage();
  int pelotaX = -1;
  int pelotaY = -1;
  int porteriaAzulX = -1;
  int porteriaAzulY = -1;
  int porteriaAmaX = -1;
  int porteriaAmaY = -1;
  int lastPelotaX = -1;
  int lastPelotaY = -1;

private:
  Pixy2 pixy_;
};
