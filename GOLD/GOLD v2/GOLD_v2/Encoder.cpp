#include "Encoder.h"

const int encoder = 11;
volatile int pulses = 0; 
double revs, rpm, buggy_dist, newtime, oldtime = 0, newpulses, oldpulses = 0, newdistance, olddistance = 0;
const double radius = 0.0325 * 100; //in cm (65mm diameter)
const double pulses_per_rev = 4; //8??
double dist_since_last = 0, new_x, new_y;

void StartEncoder() {
  pinMode(encoder, INPUT_PULLUP);
}
void measure_dist(){
  newtime = millis() / 1000;
  // newdistance = distance(); // from US header file !!
  // newpulses = pulses;
  // revs = ((newpulses - oldpulses) / pulses_per_rev);
  // rpm = revs / ((newtime - oldtime) / 60);
  // buggy_vel = ((rpm * 2 * PI * (radius))/60)/120;
  newpulses = pulses;
  dist_since_last = ((newpulses-oldpulses)/pulses_per_rev)*2*PI*radius;
  new_x = state.getX() + (dist_since_last*cos(heading));
  new_y = state.getY() + (dist_since_last*sin(heading));
  state.setvalx(new_x);
  state.setvaly(new_y);
  oldtime = newtime; 
  oldpulses = newpulses;
}

void doEncoder(){
  pulses++;
}