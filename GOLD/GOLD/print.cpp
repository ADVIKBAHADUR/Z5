#include "Print.h"
Coord state(0,0);
double angle = 90;

double ang_error = 20, prev_ang_error = 0;
double time, prev_time = 0;

void turn(Coord target){
  time = millis();
  ang_error = calculate_angle(90, target);

  double kp = -9;
  double ki = -0.0004;
  double kd = -3;
  
  double integral;
  double derivative;

  integral = ang_error*(time - prev_time);
  derivative = (ang_error - prev_ang_error);
  TURNSPEED = kp*ang_error + ki*integral + kd*derivative;

  prev_ang_error = ang_error;
}

void go_to(Coord target){
  error = calculate_dist(state, target);
  ang_diff = calculate_angle(state, target);
}

void print(){
  //FOR TESTING
  for(int i = 0; i < sizeof(az_a); i++){
    target = az_a[i]
    while(ang_error > 1){
      turn(target);
    }
  }
}