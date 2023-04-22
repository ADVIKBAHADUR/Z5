#include "IMU.h"
Madgwick filter;
const float sensorRate = 104.00;

double heading;
double init_heading, tot_error, calibrate = 0.002;

void initialise_IMU(){
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    // stop here if you can't access the IMU:
    while (true);
  }
  filter.begin(sensorRate);
}

double angle(){
  float xAcc, yAcc, zAcc;
  float xGyro, yGyro, zGyro;
  tot_error = tot_error + calibrate;
  float heading;
  if (IMU.accelerationAvailable() &&
      IMU.gyroscopeAvailable()) {
    // read accelerometer &and gyrometer:
    IMU.readAcceleration(xAcc, yAcc, zAcc);
    IMU.readGyroscope(xGyro, yGyro, zGyro);
    // update the filter, which computes orientation:
    filter.updateIMU(xGyro, yGyro, zGyro, xAcc, yAcc, zAcc);
    heading = filter.getYaw();
    heading = heading + tot_error;
    return(heading);
    heading = heading - init_heading;
  }
}