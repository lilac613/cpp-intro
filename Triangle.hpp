#pragma once
#include "Point.hpp"
class Triangle{
  private:
    Point p_1;
    Point p_2;
    Point p_3;
  public:
    Triangle(Point, Point, Point);
    double area();
    
};