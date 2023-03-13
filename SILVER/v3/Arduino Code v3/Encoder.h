#ifndef ENCODER_H
#define ENCODER_H
#include "Ports.h"
#include <Arduino.h>
#include "Ultrasonics.h"

//pins that allow interrupts: 2, 3, 9, 10, 11, 13, A1, A5 and A7

extern const int encoder;
extern volatile int pulses; 
extern int revs, rpm, buggy_vel, abs_vel, rel_vel, newtime, oldtime, newpulses, oldpulses, newdistance, olddistance;
extern const int radius; 
extern const int pulses_per_rev; 

void StartEncoder();
void run_encoder();
void doEncoder();

#endif