class pixy{

    void pixyCam(int objeto);
    void pixyImage();
};

void pixyCam(int objeto){
// 1=Ball   2=Blue Goal   3=Yellow Goal
  pixy.ccc.getBlocks();
  int j = -1; //A base value is specified
    if(pixy.ccc.numBlocks){
      for(int i = 0; i < pixy.ccc.numBlocks; i++){
        if(int(pixy.ccc.blocks[i].m_signature) == objeto){ //the loop goes through the signatures in the pixy to find the one that is being evaluated
          j = i; 
        }  
      }
    }
       Serial.println  (j);
            switch(j){
                
            case -1:
              if(objeto == 1){ //The ball wasn't found
                pelotaX = -1;
                pelotaY = -1;
                Serial.println("No se ha detectado la PELOTA");
              }
              if(objeto == 2){ //Blue goal wasn't found
                porteriaAzulX = -1;
                porteriaAzulY = -1;
                Serial.println("No se detecto la PORTERIA AZUL");  
              }
              if(objeto == 3){ //Yellow goal wasn't found
                porteriaAmaX = -1;
                porteriaAmaY = -1;
                Serial.println("No se detecto la PORTERIA AMARILLA");
              }
              break;
              
            case 0: //Ball found, the coordinates will update
              lastPelotaX = pelotaX;
              lastPelotaY = pelotaY;
              pelotaX = int(pixy.ccc.blocks[j].m_x);
              pelotaY = int(pixy.ccc.blocks[j].m_y);  
              Serial.print("Se detecto la pelota en las coordenadas X: ");
              Serial.print(pelotaX);
              Serial.print("  Y: ");
              Serial.print(pelotaY);
              Serial.print("  LastX: ");
              Serial.print(lastPelotaX);
              Serial.print("  LastY: ");
              Serial.println(lastPelotaY);
              break;
        
            case 1: //Blue goal found, updating coordinates
              porteriaAzulX = int(pixy.ccc.blocks[j].m_x);
              porteriaAzulY = int(pixy.ccc.blocks[j].m_x);
              Serial.print("Se detecto la PORTERIA AZUL en las coordenadas X: ");
              Serial.print(porteriaAzulX);
              Serial.print("  Y: ");
              Serial.println(porteriaAzulY);
              break;
        
            case 2: //Yellow goal found, updating coordinates
              porteriaAmaX = int(pixy.ccc.blocks[j].m_x);
              porteriaAmaY = int(pixy.ccc.blocks[j].m_x);
              Serial.print("Se detecto la PORTERIA AMA en las coordenadas X: ");
              Serial.print(porteriaAmaX);
              Serial.print("  Y: ");
              Serial.println(porteriaAmaY);
              break; 
           }
}

//This functions searches and prints the information for every signature in the pixyCam
void pixyImage(){
  
  pixy.ccc.getBlocks();

  if(pixy.ccc.numBlocks){
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for(int i=0; i<pixy.ccc.numBlocks; i++){
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print(); 
    }  
  }
}

