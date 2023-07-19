#include "Point.hpp"
#include "AUV.hpp"
#include <array>
#include <cmath>


AUV::AUV(std::string name0, Point position0, double depth0, double heading0, std::array<double,3> speed0, double angular_speed0){
      this->name = name0;
      this->position = position0;
      this->depth = depth0;
      this->heading = heading0;
      this->speed = speed0;
      this->angular_speed = angular_speed0;
}
void AUV::step(const double &dt){
    position.set_x(position.x()+speed[0]*dt);
    position.set_y(position.y()+speed[1]*dt);
    depth += speed[2]*dt;
    heading += angular_speed*dt;
}
void AUV::apply_acceleration(std::array<double,3> lin_accel, double dt){
    speed[0] += lin_accel[0]*dt;
    speed[1] += lin_accel[1]*dt;
    speed[2] += lin_accel[2]*dt;
}
void AUV::apply_angular_acceleration(double angular_acceleration, double dt){
    angular_speed += angular_acceleration*dt;
}