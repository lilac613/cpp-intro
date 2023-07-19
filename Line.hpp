#pragma once
#include "Point.hpp"
class Line{
  private:
    Point p1;
    Point p2;
  public:
    Line(Point, Point);
    double length();
    double distance_to_point(Point p);
};