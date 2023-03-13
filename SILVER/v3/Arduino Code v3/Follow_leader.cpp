#include "Follow_leader.h"

const int DIST_MAINTAIN = 20;
double error, prev_error = 0;
double time, prev_time = 0;

void follow_leader(){
  double distobj = distance();

  time = millis();
  error = DIST_MAINTAIN - distobj;
  prev_error = 0;

  double kp = -0.6;
  double ki = -0.0001;
  double kd = -0.4;
  
  double integral;
  double derivative;

  integral = error*(time - prev_time);
  derivative = (error - prev_error);

  SPEED = kp*error + ki*integral + kd*derivative;
  prev_error = error;
  prev_time = time;
  if (SPEED > 255){
    SPEED = 255;
  }
  Serial.println(SPEED);
  straight();

}