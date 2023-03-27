#ifndef PORTS_H
#define PORTS_H
#include <Arduino.h>
#include <string>

extern const int LEYE; 
extern const int REYE; 
extern const int V_RIGHT;
extern const int V_LEFT; 
extern const int S_RIGHT1;
extern const int S_RIGHT2; 
extern const int S_LEFT1; 
extern const int S_LEFT2;
extern const int US_TRIG;
extern const int US_ECHO;
extern const unsigned long EVENT;//unsigned as gets realy long
extern const int STOPPINGDIST;
extern unsigned long prev_event;
extern int L1;
extern int L2;
extern int R1;
extern int R2;
#endif