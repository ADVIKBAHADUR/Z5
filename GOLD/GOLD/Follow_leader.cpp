#include "Follow_leader.h"

const int DIST_MAINTAIN = 10;
double error, prev_error = 0;
double time, prev_time = 0;

void follow_leader(){
  double distobj = distance();

  time = millis();
  error = DIST_MAINTAIN - distobj;


  double kp = -9;
  double ki = -0.0004;
  double kd = -3;
  
  double integral;
  double derivative;

  integral = error*(time - prev_time);
  derivative = (error - prev_error);

  SPEED = kp*error + ki*integral + kd*derivative;
  prev_error = error;
  prev_time = time;
  if (SPEED > 210){
    SPEED = 210;
  }
  //Serial.println(SPEED);
  check_for_turn();

}