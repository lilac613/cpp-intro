#pragma once
#include <vector>

class Polygon{
  private:
    std::vector<Point> vec;
  public:
    Polygon(std::vector<Point>);
    double area();
    double perimeter();
};