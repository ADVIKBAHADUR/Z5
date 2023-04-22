#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>
#include <string>
#include "Ports.h"

extern int parked;
extern double SPEED;

void straight();
void reverse();
void stop();
void left();
void right();
void rightM(int state);
void leftM(int state);
#endif