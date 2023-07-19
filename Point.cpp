#include "Point.hpp"
#include <cmath>

Point::Point(double x, double y)
{
  this->m_d_x = x;
  this->m_d_y = y;
}

Point::Point(){
    this->m_d_x = 0.0;
    this->m_d_y = 0.0;
}

double Point::distance_to_origin()
{
  return std::sqrt(std::pow(m_d_x, 2)  + std::pow(m_d_y, 2));
}

double Point::distance_to_point(Point p)
{
  return std::sqrt(std::pow(m_d_x - p.x(), 2)  + std::pow(m_d_y - p.y(), 2));
}
void Point::set_x(const double &amt){
    m_d_x = amt;
}
void Point::set_y(const double &amt){
    m_d_y = amt;
}