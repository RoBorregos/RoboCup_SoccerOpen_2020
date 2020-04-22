#include "Pixy.h"

Pixy::Pixy()
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
      ballX = -1;
      ballY = -1;
      Serial.println("BALL was not detected");
    }
    if (object == 2)
    { //Blue goal wasn't found.
      blueGoalX = -1;
      blueGoalY = -1;
      Serial.println("BLUE GOAL was not detected");
    }
    if (object == 3)
    { //Yellow goal wasn't found.
      yellGoalX = -1;
      yellGoalY = -1;
      Serial.println("YELLOW GOAL was not detected");
    }
    break;

  case 0: //Ball found, the coordinates will update.
    lastBallX = ballX;
    lastBallY = ballY;
    ballX = int(pixy_.ccc.blocks[j].m_x);
    ballY = int(pixy_.ccc.blocks[j].m_y);
    Serial.print("BALL detected in X: ");
    Serial.print(ballX);
    Serial.print("  Y: ");
    Serial.print(ballY);
    Serial.print("  LastX: ");
    Serial.print(lastBallX);
    Serial.print("  LastY: ");
    Serial.println(lastBallY);
    break;

  case 1: //Blue goal found, updating coordinates.
    blueGoalX = int(pixy_.ccc.blocks[j].m_x);
    blueGoalY = int(pixy_.ccc.blocks[j].m_x);
    Serial.print("BLUE GOAL detected in X: ");
    Serial.print(blueGoalX);
    Serial.print("  Y: ");
    Serial.println(blueGoalY);
    break;

  case 2: //Yellow goal found, updating coordinates.
    yellGoalX = int(pixy_.ccc.blocks[j].m_x);
    yellGoalY = int(pixy_.ccc.blocks[j].m_x);
    Serial.print("YELLOW GOAL detected in X: ");
    Serial.print(yellGoalX);
    Serial.print("  Y: ");
    Serial.println(yellGoalY);
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