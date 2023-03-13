#include "Drive.h"

int parked = 1; //Stopped nothing runs until 0
double SPEED = 110;

void straight(){

  if(SPEED <= 0){  
    rightM(2);
    leftM(2);
    SPEED = SPEED *8;
  }  
  else{
    rightM(1);
    leftM(1);
  }
  analogWrite(V_LEFT, abs(SPEED));
  analogWrite(V_RIGHT, abs(SPEED));
}

void reverse(){
  analogWrite(V_LEFT, 150);
  analogWrite(V_RIGHT, 150);
  rightM(2);
  leftM(2);
}

void stop(){
  analogWrite(V_LEFT, 0);
  analogWrite(V_RIGHT, 0);
  rightM(0);
  leftM(0);
}

void left(){
  if (parked != 1){  
  analogWrite(V_RIGHT, R1);
  analogWrite(V_LEFT, L1);
  rightM(1);
  leftM(1);
  }

}

void right(){ 
  if (parked != 1){
  analogWrite(V_LEFT, L2);
  analogWrite(V_RIGHT, R2);
  rightM(1);
  leftM(1);
  }
}
void rightM(int state){
  switch(state){
    case 0:
    digitalWrite(S_RIGHT1, 0);
    digitalWrite(S_RIGHT2, 0);
    break;

    case 1:
    digitalWrite(S_RIGHT1, 0);
    digitalWrite(S_RIGHT2, 1);
    break;

    case 2: 
    digitalWrite(S_RIGHT1, 1);
    digitalWrite(S_RIGHT2, 0);
    break;
  }

}

void leftM(int state){
  switch(state){
    case 0:
    digitalWrite(S_LEFT1, 0);
    digitalWrite(S_LEFT2, 0);
    break;

    case 1:
    digitalWrite(S_LEFT1, 0);
    digitalWrite(S_LEFT2, 1);
    break;

    case 2: 
    digitalWrite(S_LEFT1, 1);
    digitalWrite(S_LEFT2, 0);
    break;
  }
}