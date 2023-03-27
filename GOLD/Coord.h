#ifndef COORD_H
#define COORD_H
#include <Arduino.h> 

extern coord state(0,0);
extern double curr_angle = PI/2;

class Coord{

  private:
    double x_val;
    double y_val;

  public:
    Coord();
    Coord(double x, double y);

    double getX();
    double getY();
};

double calculate_angle(Coord state, Coord target);
double calculate_dist(Coord state, Coord target);
void go_to(Coord target)
#endif