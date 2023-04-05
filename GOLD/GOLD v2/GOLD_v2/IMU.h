#ifndef IMU_H
#define IMU_H
#include "Arduino_LSM6DS3.h"
#include "MadgwickAHRS.h"

extern double heading;
extern double init_heading;
void initialise_IMU();

double angle();

#endif