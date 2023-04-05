#ifndef ENCODER_H
#define ENCODER_H
#include <math.h>
#include "Ports.h"
#include <Arduino.h>
#include "Coord.h"
#include "IMU.h"

extern const int encoder;
extern volatile int pulses; 
extern double revs, rpm, buggy_dist, newtime, oldtime, newpulses, oldpulses, newdistance, olddistance;
extern const double radius; //in cm (65mm diameter)
extern const double pulses_per_rev; //8??


void StartEncoder();
void measure_dist();
void doEncoder();
#endif