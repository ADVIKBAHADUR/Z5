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
char toprint;
double angleerror = 90, disterror;
Coord arr[9];


void setup() {
  parked = 1;
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

  if (mymsg != "-1"){
    if (mymsg == "STOP"){
      parked = 1;
    }
    else if (mymsg == "GO"){
      parked = 0;
    }
    else{
      printmessage.concat(mymsg);
      Serial.println(printmessage);
      toprint = printmessage[0];
      if(toprint == 'A'){
      for(int i = 0; i<9; i++){
        arr[i]=az_a[i]; 
      }
    }
    if(printmessage.length() > 0){
      measure_dist();
      if(angleerror > 3)
        doWhat = 1;
      
      else if(angleerror < 3){
        doWhat = 2;
      }
    }
    else{
      doWhat = 0;
    }
    
    angleerror = calculate_angle(heading, arr[curr_letter]);
    disterror = calculate_dist(state, arr[curr_letter]);

    if(doWhat == 1){
      if (angleerror > 0){
        right();
      }
      else if(angleerror < 0){
        left();
      }
    }
    if (doWhat == 2){
      if(disterror > abs(3)){
        straight();
      }
      else{
        printmessage.remove(0,1);
        curr_letter++;
        if(curr_letter = 10){
          curr_letter = 0;
        }        
      }

    }
    } 
  }

}

