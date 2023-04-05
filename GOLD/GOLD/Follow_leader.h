#ifndef FOLLOW_LEADER_H
#define FOLLOW_LEADER_H

#include "Turning.h"
#include "Ultrasonics.h"
#include "Ports.h"
#include "Drive.h"
#include <Arduino.h>

extern WiFiClient client;

extern double error, prev_error;
extern double time, prev_time;

void follow_leader();

#endif