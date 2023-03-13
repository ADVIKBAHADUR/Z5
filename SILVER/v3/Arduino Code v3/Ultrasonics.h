#ifndef ULTRASONICS_H
#define ULTRASONICS_H
#include <Arduino.h>
#include <string>
#include "Drive.h"
#include "Ports.h"
#include "Wifi.h"


int duration(); //Returns duration from obstacle
int distance(); //Returns distance from obstacle
bool stop_for_object(); // Stops for obstacle when at a certain distance

#endif