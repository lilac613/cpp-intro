#pragma once
#include <array>
#include <string>
#include "Point.hpp"
#include <vector>

class AUV{
  private:
    std::string name;
    Point position;
    double depth;
    double heading;
    std::array<double,3> speed;
    double angular_speed;
  public:
    AUV(std::string, Point, double, double, std::array<double,3>, double);
    void step(const double &dt);
    void apply_acceleration(std::array<double,3> lin_accel, double dt);
    void apply_angular_acceleration(double angular_acceleration, double dt);
};