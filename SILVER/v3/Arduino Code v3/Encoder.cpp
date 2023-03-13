#include "Encoder.h"

//pins that allow interrupts: 2, 3, 9, 10, 11, 13, A1, A5 and A7
const int encoder = 11;
volatile int pulses = 0; 
int revs, rpm, buggy_vel, abs_vel, rel_vel, newtime, oldtime = 0, newpulses, oldpulses = 0, newdistance, olddistance = 0;
const int radius = 0.0325; //in meters (65mm diameter)
const int pulses_per_rev = 4; //8??


void StartEncoder() {
  pinMode(encoder, INPUT);
  digitalWrite(encoder, HIGH);
}

void run_encoder() {
  newtime = millis() / 1000;
  newdistance = distance; // from US header file !!
  newpulses = pulses / 120;
  revs = ((newpulses - oldpulses) / pulses_per_rev);
  rpm = revs / ((newtime - oldtime) / 60);
  buggy_vel = (rpm / 60) * 2 * PI * radius;
  rel_vel = (newdistance - olddistance) / (newtime - oldtime);
  abs_vel = rel_vel + buggy_vel; //speed of object in front
  oldtime = newtime; 
  olddistance = newdistance;
  oldpulses = newpulses;
}

void doEncoder(){
  pulses++;
}