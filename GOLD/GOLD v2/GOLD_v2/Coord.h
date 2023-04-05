#ifndef COORD_H
#define COORD_H
#include <Arduino.h> 



class Coord{

  private:
    double x_val;
    double y_val;

  public:
    Coord();
    Coord(double x, double y);

    double getX();
    double getY();
    void setvalx(double num);
    void setvaly(double num);
};

extern Coord state;

double calculate_angle(double heading, Coord target);
double calculate_dist(Coord state, Coord target);
#endif