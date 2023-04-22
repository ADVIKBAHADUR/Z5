#include "Coord.h"
#include "Alpha.h"
#include "Ports.h"
#include "Wifi.h"
#include "Encoder.h"
#include "Drive.h"
#include <string.h>
#include "Arduino_LSM6DS3.h"
#include "MadgwickAHRS.h"
#include "IMU.h"

const float sensorRate = 104.00;

int doWhat = 0;
/*
0 --> Nothing happens, stay there.
1 --> Turning to match angle
2 --> Go to coordinate
*/
int curr_letter= 0, char_drawer= 0, word_drawer = 0;
String printmessage;
char goal_alpha;
double angleerror = 90, disterror;
Coord arr[9];


void setup() {
  parked = 0;
  Serial.begin(9600);
  connect();
  StartEncoder();
  attachInterrupt(digitalPinToInterrupt(encoder), doEncoder, RISING);

  initialise_IMU();

  init_heading = angle();
}

void loop() {
  //IMU
  heading = angle();
  String mymsg = readMessages();

  if (mymsg == "STOP"){
    parked = 1;
  }
  else if (mymsg == "GO"){
    parked = 0;
  }
  else{
    angleerror = calculate_angle(heading, arr[curr_letter]);
    disterror = calculate_dist(state, arr[curr_letter]);
    if(mymsg != "-1"){
      printmessage.concat(mymsg);
    }
    //Serial.println(printmessage);
    const String checkmessage = "You are connected to the server";

    if (printmessage.substring(0, 31) == checkmessage){
      printmessage.remove(0, 31);
    }
    if (printmessage.substring(0,4) == "STOP"){
      parked = 1;
      printmessage.remove(0, 4);
    }
    if (printmessage.substring(0,5) == "START"){
      parked = 0;
      printmessage.remove(0, 5);
    }
    goal_alpha = printmessage[0];
    //Match each variable to each letter array
if(goal_alpha == 'A'){
    //Serial.println("I am printing A now");
    for(int i = 0; i<9; i++){
      arr[i]=az_a[i]; 
    }
  }
if(goal_alpha == 'B'){
  for(int i = 0; i<9; i++){
    arr[i]=az_b[i]; 
  }
}
if(goal_alpha == 'C'){
  for(int i = 0; i<9; i++){
    arr[i]=az_c[i]; 
  }
}
if(goal_alpha == 'D'){
  for(int i = 0; i<9; i++){
    arr[i]=az_d[i]; 
  }
}
if(goal_alpha == 'E'){
  for(int i = 0; i<9; i++){
    arr[i]=az_e[i]; 
  }
}
if(goal_alpha == 'F'){
  for(int i = 0; i<9; i++){
    arr[i]=az_f[i]; 
  }
}
if(goal_alpha == 'G'){
  for(int i = 0; i<9; i++){
    arr[i]=az_g[i]; 
  }
}
if(goal_alpha == 'H'){
  for(int i = 0; i<9; i++){
    arr[i]=az_h[i]; 
  }
}
if(goal_alpha == 'I'){
  for(int i = 0; i<9; i++){
    arr[i]=az_i[i]; 
  }
}
if(goal_alpha == 'J'){
  for(int i = 0; i<9; i++){
    arr[i]=az_j[i]; 
  }
}
if(goal_alpha == 'K'){
  for(int i = 0; i<9; i++){
    arr[i]=az_k[i]; 
  }
}
if(goal_alpha == 'L'){
  for(int i = 0; i<9; i++){
    arr[i]=az_l[i]; 
  }
}
if(goal_alpha == 'M'){
  for(int i = 0; i<9; i++){
    arr[i]=az_m[i]; 
  }
}
if(goal_alpha == 'N'){
  for(int i = 0; i<9; i++){
    arr[i]=az_n[i]; 
  }
}
if(goal_alpha == 'O'){
  for(int i = 0; i<9; i++){
    arr[i]=az_o[i]; 
  }
}
if(goal_alpha == 'P'){
  for(int i = 0; i<9; i++){
    arr[i]=az_p[i]; 
  }
}
if(goal_alpha == 'Q'){
  for(int i = 0; i<9; i++){
    arr[i]=az_q[i]; 
  }
}
if(goal_alpha == 'R'){
  for(int i = 0; i<9; i++){
    arr[i]=az_r[i]; 
  }
}
if(goal_alpha == 'S'){
  for(int i = 0; i<9; i++){
    arr[i]=az_s[i]; 
  }
}
if(goal_alpha == 'T'){
  for(int i = 0; i<9; i++){
    arr[i]=az_t[i]; 
  }
}
if(goal_alpha == 'U'){
  for(int i = 0; i<9; i++){
    arr[i]=az_u[i]; 
  }
}
if(goal_alpha == 'V'){
  for(int i = 0; i<9; i++){
    arr[i]=az_v[i]; 
  }
}
if(goal_alpha == 'W'){
  for(int i = 0; i<9; i++){
    arr[i]=az_w[i]; 
  }
}
// Continue the pattern for the remaining letters
if(goal_alpha == 'X'){
  for(int i = 0; i<9; i++){
    arr[i]=az_x[i]; 
  }
}
if(goal_alpha == 'Y'){
  for(int i = 0; i<9; i++){
    arr[i]=az_y[i]; 
  }
}
if(goal_alpha == 'Z'){
  for(int i = 0; i<9; i++){
    arr[i]=az_z[i]; 
  }
}
      

  if(printmessage.length() > 0){

    //Serial.println(state.getX());
    //Serial.println(state.getY());
    if(abs(angleerror) > 3){
      doWhat = 1;
      //Serial.println(doWhat);
    }

    
    else if(abs(angleerror) < 3){
      doWhat = 2;
      //Serial.println(doWhat);        
    }
    else{
      doWhat = 0;
    }
  }


  Serial.println(angleerror);

  if(doWhat == 1){
    //Serial.println(parked);
    if (angleerror < 0 && parked != 1){
      rightM(1);
      //analogWrite(V_RIGHT, 150);
    }
    else if(angleerror > 0 && parked != 1){
      leftM(1);
      analogWrite(V_LEFT, 150);

    }
  }
  if (doWhat == 2){
    measure_dist();
    if(disterror > abs(7)){
      rightM(1);
      leftM(1);
    }
    if (angleerror > abs(8)){
      doWhat = 1;
    }
    if(disterror < abs(7)){
      Serial.println("Reached to point");
      curr_letter++;
      if(curr_letter = 10){
        printmessage.remove(0,1);
        curr_letter = 0;
      }        
    }

  }
  } 
  delay(20);
}

