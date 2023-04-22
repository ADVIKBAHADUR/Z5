#ifndef ENCODER_H
#define ENCODER_H
#include <math.h>
#include "Ports.h"
#include <Arduino.h>
#include "Ultrasonics.h"
#include <string.h>
#include <string>

//pins that allow interrupts: 2, 3, 9, 10, 11, 13, A1, A5 and A7

extern const int encoder ;
extern volatile int pulses ; 
extern double revs, rpm, buggy_vel, abs_vel, rel_vel, newtime, oldtime, newpulses, oldpulses, newdistance, olddistance;
extern const double radius; //in meters (65mm diameter)
extern const double pulses_per_rev; //8??

void StartEncoder();
void run_encoder();
void doEncoder();

#endif