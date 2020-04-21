#include "pixy.h"

Pixy::pixy()
{
  pixy_ = Pixy2 pixy;
}

void Pixy::pixyCam(int objeto)
{
  // 1=Ball   2=Blue Goal   3=Yellow Goal
  pixy_.ccc.getBlocks();
  int j = -1; //A base value is specified.
  if (pixy_.ccc.numBlocks)
  {
    for (int i = 0; i < pixy_.ccc.numBlocks; i++)
    {
      if (int(pixy_.ccc.blocks[i].m_signature) == objeto)
      { //The loop goes through the signatures in the pixy to find the one that is being evaluated.
        j = i;
      }
    }
  }
  Serial.println(j);
  switch (j)
  {

  case -1:
    if (objeto == 1)
    { //The ball wasn't found.
      pixy_.pelotaX = -1;
      pixy_.pelotaY = -1;
      Serial.println("No se ha detectado la PELOTA");
    }
    if (objeto == 2)
    { //Blue goal wasn't found.
      pixy_.porteriaAzulX = -1;
      pixy_.porteriaAzulY = -1;
      Serial.println("No se detecto la PORTERIA AZUL");
    }
    if (objeto == 3)
    { //Yellow goal wasn't found.
      pixy_.porteriaAmaX = -1;
      pixy_.porteriaAmaY = -1;
      Serial.println("No se detecto la PORTERIA AMARILLA");
    }
    break;

  case 0: //Ball found, the coordinates will update.
    pixy_.lastPelotaX = pelotaX;
    pixy_.lastPelotaY = pelotaY;
    pixy_.pelotaX = int(pixy.ccc.blocks[j].m_x);
    pixy_.pelotaY = int(pixy.ccc.blocks[j].m_y);
    Serial.print("Se detecto la pelota en las coordenadas X: ");
    Serial.print(pixy_.pelotaX);
    Serial.print("  Y: ");
    Serial.print(pixy_.pelotaY);
    Serial.print("  LastX: ");
    Serial.print(pixy_.lastPelotaX);
    Serial.print("  LastY: ");
    Serial.println(pixy_.lastPelotaY);
    break;

  case 1: //Blue goal found, updating coordinates.
    pixy_.porteriaAzulX = int(pixy.ccc.blocks[j].m_x);
    pixy_.porteriaAzulY = int(pixy.ccc.blocks[j].m_x);
    Serial.print("Se detecto la PORTERIA AZUL en las coordenadas X: ");
    Serial.print(pixy_.porteriaAzulX);
    Serial.print("  Y: ");
    Serial.println(pixy_.porteriaAzulY);
    break;

  case 2: //Yellow goal found, updating coordinates.
    pixy_.porteriaAmaX = int(pixy.ccc.blocks[j].m_x);
    pixy_.porteriaAmaY = int(pixy.ccc.blocks[j].m_x);
    Serial.print("Se detecto la PORTERIA AMA en las coordenadas X: ");
    Serial.print(porteriaAmaX);
    Serial.print("  Y: ");
    Serial.println(porteriaAmaY);
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