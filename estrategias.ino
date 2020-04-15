/*
 * Cases
 * 1 - The robot doesn't has possession of the ball - 'seguirPelota()' is called
 * 'seguirPelota()' when the robot gains possession of the ball, the next case is called
 * 2 - The robot has posession of the ball - The robot will make diagonal front movements depending on its location
 * on the field. If the goal is to the left of the image, the robot will make a diagonal right movement, and when it reaches
 * the sideline, it will change to a diagonal left movement.
 */

/*void estrategia1(){
  int caso = 1;

  if(tienesPelota != false){
    caso = 2;  
  }

  switch (caso){

    case 1:
      seguirPelota();
    break;
    
    case 2;
      if(porteriaRivalX > 140){ //Goal to the left of the camera
        while(notOnWhiteLine){
          movement(6); //Diagonal forward left
        }
        movimiento(7); //Diagonal forward right
      } else{
        while(notOnWhiteLine){
          movement(7);
        }
        movement(6);
      }
  } 
}
*/


/* 
 * 1 = Goal to the right (Robot in the left of the field)
 * 2 = Goal to the right (Robot in the right of the field)
 * 3 = Goal to the front
 */

/*
void ataca(){
  
  
  int accion = -1;
  checaPosesion();
  pixyCam(PorteriaRival)

  if(porteriaRivalX != -1){
    if(porteriaRivalX < 135){
      accion = 1;
    }
    if(porteriaRivalX > 185){
      accion = 2;
    }
  }
    if((porteriaRivalX > 135) && (porteriaRivalX < 185)){
      accion = 3;
    }

  switch(accion){

    case 1:
      while(porteriaAzulX < 135){
        movement(1);
        delay(20);
        movement(9);
        delay(5);
        angleMovement(345);
        movement(1);
        delay(15);
        movimiento(9);
        delay(1);
        pixyCam(PorteriaRival);
      }
      break;

    case 2:
      while(porteriaRivalX > 185){
        movement(1);
        delay(20);
        movement(9);
        delay(5);
        angleMovement(15);
        movement(1);
        delay(15);
        movimiento(11);
        delay(1);
        pixyCam(PorteriaRival);
      }
    break;
    
    case 3:
      while((porteriaRivalX > 135) && (porteriaRivalX < 185)){
        movement(1);
        delay(30);
        movement(9);
        delay(1);
        pixyCam(PorteriaRival);
      }
      break;
  }
  
}
*/