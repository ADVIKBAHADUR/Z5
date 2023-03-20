#include "Encoder.h"

//pins that allow interrupts: 2, 3, 9, 10, 11, 13, A1, A5 and A7
const int encoder = 11;
volatile int pulses = 0; 
double revs, rpm, buggy_vel, abs_vel, rel_vel, newtime, oldtime = 0, newpulses, oldpulses = 0, newdistance, olddistance = 0;
const double radius = 0.0325 * 100; //in cm (65mm diameter)
const double pulses_per_rev = 4; //8??

double pre_abs = 0.00;
double pre_bug = 0.00;


void StartEncoder() {
  pinMode(encoder, INPUT_PULLUP);
}

void run_encoder() {
  newtime = millis() / 1000;
  newdistance = distance(); // from US header file !!
  newpulses = pulses;
  revs = ((newpulses - oldpulses) / pulses_per_rev);
  rpm = revs / ((newtime - oldtime) / 60);
  buggy_vel = ((rpm * 2 * PI * (radius))/60)/120;
  rel_vel = (newdistance - olddistance) / (newtime - oldtime);
  abs_vel = rel_vel + buggy_vel; //speed of object in front
  oldtime = newtime; 
  olddistance = newdistance;
  oldpulses = newpulses;
  // Serial.println(newpulses);
  // Serial.println(revs);
  // Serial.println(rpm);
  // Serial.println(abs_vel)
  Serial.println(buggy_vel);
  // Serial.println(newtime);
  //Serial.println(rel_vel);

  if(isnan(abs_vel) || isinf(abs_vel)){
    abs_vel = pre_abs;
  }
  else{
    String mystr = "";
    mystr.concat("ABS");
    mystr.concat(abs_vel);
  //Serial.println(abs_vel);
    writeMessages(mystr.c_str());
  }

  if(isnan(buggy_vel || isinf(buggy_vel))){
    buggy_vel = pre_bug;
  }
  else{
    String mystr1 = "";
    mystr1.concat("BUG");
    mystr1.concat(buggy_vel);
    delay(200);
    writeMessages(mystr1.c_str());
  }


}

void doEncoder(){
  pulses++;
}