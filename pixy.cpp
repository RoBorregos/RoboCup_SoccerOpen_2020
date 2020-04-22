#include "Pixy.h"

Pixy::pixy()
{
  pixy_ = Pixy2 pixy;
}

void Pixy::pixyCam(int object)
{
  // 1=Ball   2=Blue Goal   3=Yellow Goal
  pixy_.ccc.getBlocks();
  int j = -1; //A base value is specified.
  if (pixy_.ccc.numBlocks)
  {
    for (int i = 0; i < pixy_.ccc.numBlocks; i++)
    {
      if (int(pixy_.ccc.blocks[i].m_signature) == object)
      { //The loop goes through the signatures in the pixy to find the one that is being evaluated.
        j = i;
      }
    }
  }
  Serial.println(j);
  switch (j)
  {

  case -1:
    if (object == 1)
    { //The ball wasn't found.
      pixy_.ballX = -1;
      pixy_.ballY = -1;
      Serial.println("BALL was not detected");
    }
    if (object == 2)
    { //Blue goal wasn't found.
      pixy_.blueGoalX = -1;
      pixy_.blueGoalY = -1;
      Serial.println("BLUE GOAL was not detected");
    }
    if (object == 3)
    { //Yellow goal wasn't found.
      pixy_.yellGoalX = -1;
      pixy_.yellGoalY = -1;
      Serial.println("YELLOW GOAL was not detected");
    }
    break;

  case 0: //Ball found, the coordinates will update.
    pixy_.lastBallX = pixy_.ballX;
    pixy_.lastBallY = pixy_.ballY;
    pixy_.ballX = int(pixy.ccc.blocks[j].m_x);
    pixy_.ballY = int(pixy.ccc.blocks[j].m_y);
    Serial.print("BALL detected in X: ");
    Serial.print(pixy_.ballX);
    Serial.print("  Y: ");
    Serial.print(pixy_.ballY);
    Serial.print("  LastX: ");
    Serial.print(pixy_.lastBallX);
    Serial.print("  LastY: ");
    Serial.println(pixy_.lastBallY);
    break;

  case 1: //Blue goal found, updating coordinates.
    pixy_.blueGoalX = int(pixy.ccc.blocks[j].m_x);
    pixy_.blueGoalY = int(pixy.ccc.blocks[j].m_x);
    Serial.print("BLUE GOAL detected in X: ");
    Serial.print(pixy_.blueGoalX);
    Serial.print("  Y: ");
    Serial.println(pixy_.blueGoalY);
    break;

  case 2: //Yellow goal found, updating coordinates.
    pixy_.yellGoalX = int(pixy.ccc.blocks[j].m_x);
    pixy_.yellGoalY = int(pixy.ccc.blocks[j].m_x);
    Serial.print("YELLOW GOAL detected in X: ");
    Serial.print(pixy_.yellGoalX);
    Serial.print("  Y: ");
    Serial.println(pixy_.yellGoalY);
    break;
  }
}

//This functions searches and prints the information for every signature in the pixyCam.
void Pixy::pixyImage()
{

  pixy_.ccc.getBlocks();

  if (pixy_.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy_.ccc.numBlocks);
    for (int i = 0; i < pixy_.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy_.ccc.blocks[i].print();
    }
  }
}