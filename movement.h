class movements{
    public:
    int motores[8];
    int pwm[4];

    movements(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int p1, int p2, int p3, int p4);
    void movement(int direccion);
    void angleMovement(int angle);
    void pwmNormal();
    void pwmAtras();
    void pwmCustom(float f1, float f2, float f3, float f4);
    void seguirPelota();
};

movements::movements(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int p1, int p2, int p3, int p4){
    motores[0] = m1;
    motores[1] = m2;
    motores[2] = m3;
    motores[3] = m4;
    motores[4] = m5;
    motores[5] = m6;
    motores[6] = m7;
    motores[7] = m8;
    pwm[0] = p1;
    pwm[1] = p2;
    pwm[2] = p3;
    pwm[3] = p4;
}

void movements::movement(int direccion){
    /* A switch case is used to determine one of the 9 possible movements that the robot can perform.
    *  An array is used to determine the pins of the motors and the pwms. 
    *  The first two spaces on the 'motores' array should be used for the front left wheel,
    *  the next two for the front right wheel, the next two for the back right wheel and the last two fote the back left wheel. 
    */
  switch(direccion){

    case 1: //FRONT
      pwmNormal();
      for(int i=0; i<8; i++){
        if(i==0 || i==3 || i==5 || i==6){
          digitalWrite(motores[i], HIGH);
        } else {
          digitalWrite(motores[i], LOW);
        }
      }
      break;

   case 2: //BACK
    pwmAtras();
    for(int i=0; i<8; i++){
      if(i==0 || i==3 || i==5 || i==6){
        digitalWrite(motores[i], LOW);
      } else {
        digitalWrite(motores[i], HIGH);  
      }
    }
    break;

   case 3: //RIGHT
     pwmNormal();
     for(int i=0; i<8; i++){
      if(i==0 || i==2 || i==5 || i==7){
        digitalWrite(motores[i], HIGH);
      } else {
        digitalWrite(motores[i], LOW);
      }
    }
    break;


   case 4: //LEFT
     pwmNormal();
     for(int i=0; i<8; i++){
      if(i==0 || i==2 || i==5 || i==7){
        digitalWrite(motores[i], LOW);
      } else {
        digitalWrite(motores[i], HIGH);
      }
    }
    break;

   case 5:  //DIAGONAL BACK RIGHT
     pwmNormal();
     for(int i=0; i<8; i++){
       if(i==2 || i==7){
         digitalWrite(motores[i], HIGH);
       } else {
         digitalWrite(motores[i], LOW);
       }
     }
     break;

   case 6: //DIAGONAL FRONT LEFT
    pwmNormal();
    for(int i=0; i<8; i++){
      if(i==3 || i==6){
        digitalWrite(motores[i], HIGH);
      } else {
        digitalWrite(motores[i], LOW);
      }
    }
    break;

   case 7:  //DIAGONAL FRONT RIGHT
     pwmNormal();
     for(int i=0; i<8; i++){
       if(i==0 || i==5){
         digitalWrite(motores[i], HIGH);
       } else {
         digitalWrite(motores[i], LOW);
       }
     }
     break;

   case 8:  //DIAGONAL BACK LEFT
     pwmNormal();
     for(int i=0; i<8; i++){
       if(i==1 || i==4){
         digitalWrite(motores[i], HIGH); 
       } else {
         digitalWrite(motores[i], LOW); 
       }
     }
     break;

   case 9: //STOP
     for(int i=0; i<8; i++){
       digitalWrite(motores[i], LOW);
     }
     break;  

    
  }
  
}

void movements::angleMovement(int angle){
    /* This funtcion allows the robot to move in the angle specified, the front of the robot should.
    *  The function simulates a plane, where the front of the robot would the angle 0, it goes
    *  in a clockwise motion, meaning that using a 90 degrees angle, would make the robot go to the right
    */
  int realAngle = angle + 45;
  if(realAngle > 359){
    realAngle -=360;
  }
  float gradRadian = (realAngle * pi) /180;
  float pwm1 = 0, pwm2 = 0, pwm3 = 0, pwm4 = 0;
  bool m1 = 0, m2 = 0, m3 = 0, m4 = 0;
  float vc = 230;
  pwm1 = vc * sin(gradRadian);
  pwm2 = vc * cos(gradRadian);
  
  if(pwm1 < 0){
    m1 = true;
    pwm1 *= -1;
  }
  if(pwm2 < 0){
    m2 = true;
    pwm2 *= -1;
  }

  pwmCustom(pwm1, pwm2, pwm3, pwm4);
 
  for(int i = 0; i<8; i++){
    digitalWrite(motores[i], LOW);
  }
  if(m1){
    digitalWrite(motores[1], HIGH);
    digitalWrite(motores[4], HIGH);
    }
  if(!m1){
    digitalWrite(motores[0], HIGH);
    digitalWrite(motores[5], HIGH);
    }
  if(m2){
    digitalWrite(motores[2], HIGH);
    digitalWrite(motores[7], HIGH);
    }
  if(!m2){
    digitalWrite(motores[3], HIGH);
    digitalWrite(motores[6], HIGH);
    }
}

void movements::pwmNormal(){
  analogWrite(pwm[0], 230);
  analogWrite(pwm[1], 230);
  analogWrite(pwm[2], 230);
  analogWrite(pwm[3], 230);
}

void movements::pwmAtras(){
  analogWrite(pwm[0], 180);
  analogWrite(pwm[1], 180);
  analogWrite(pwm[2], 180);
  analogWrite(pwm[3], 180);
}

void movements::pwmCustom(float f1, float f2, float f3, float f4){
  analogWrite(pwm[0], f1);
  analogWrite(pwm[1], f2);
  analogWrite(pwm[2], f3);
  analogWrite(pwm[3], f4);
}

void movements::seguirPelota(){
  /*  
 *  -1 = Ball wasn't detected
 *  0 = PELOTA COLOCADA. ESTE CASO SE USARA PARA TERMINAR LA FUNCION
 *  1 = Ball in the middle of the image. In this case the robot should only advance straight forward
 *  2 = Ball in the top left part of the image.
 *  3 = Ball in the top right part of the image.
 *  4 = Ball in the bottom left part of the image.
 *  5 = Ball in the bottom right part of the image.
 */  
  pixyCam(1);

  int caso = -1;

  if(((pelotaX > 125) && (pelotaX < 150)) && pelotaY < 25){
    caso = 0; 
  }
  else if((pelotaX > 135) && (pelotaX < 185)){
    caso = 1;
  }
  else if(pelotaX > 185){
    if(pelotaY > 120){
      caso = 2; 
    }
    else if(pelotaY < 120){
      caso = 4;  
    }
  }
  else if(pelotaX < 135){
    if(pelotaY > 120){
      caso = 3;
    }
    else if(pelotaY < 120){
      caso = 5;
    }
  }

  switch(caso){

    case -1:
      while(pelotaX == -1){
          int m = 0;
          if(m <= 1){
            movement(3);
            delay(150);
            movement(11);
            delay(50);
            pixyCam(1);
            m++;
          } else{
            movement(4);
            delay(300);
            movement(9);
            delay(50);
            pixyCam(1);
            m = 0;
          }
        }
      break;

    case 0:
      break;

    case 1:
      movement(1);
      delay(25);
      movement(9);
      delay(5);
      break;

    case 2:
      movement(6);
      delay(25);
      movement(9);
      delay(5);
      break;

    case 3:
      movement(7);
      delay(25);
      movement(9);
      delay(5);
      break;

    case 4:
      movement(8);
      delay(25);
      movement(9);
      delay(5);
      break;

    case 5:
      movement(5);
      delay(25);
      movement(9);
      delay(5);
      break;
  }

}