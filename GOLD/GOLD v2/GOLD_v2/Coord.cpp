#include "Coord.h"
#include "math.h"



Coord::Coord() {
  Coord::x_val = 0;
  Coord::y_val = 0;
}

Coord::Coord(double x, double y) {
  Coord::x_val = x;
  Coord::y_val = y;
}

double Coord::getX() {
  return x_val;
}
double Coord::getY() {
  return y_val;
}

void Coord::setvalx(double num){
  x_val = num;
}

void Coord::setvaly(double num){
  y_val = num;
}

Coord state;



double calculate_angle(double heading, Coord target) {
  double inter1 = atan((target.getY() - state.getY())/(target.getX() - state.getX()))*57.296;
  double angle = heading - inter1;
  // Serial.println(inter1);
  // Serial.println(heading);
  // Serial.println(angle);
  return angle;
}

double calculate_dist(Coord state, Coord target){
  double distance = sqrt(sq(target.getY() - state.getY())+sq(target.getX() - state.getX()));
  Serial.println(distance);
  return distance;
}
