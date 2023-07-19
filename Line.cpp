#include "Line.hpp"
#include <cmath>
Line::Line(Point pa, Point pb) : p1(pa), p2(pb){
}

double Line::length(){
  return p1.distance_to_point(p2);
}

double Line::distance_to_point(Point p){
  double numerator = std::abs((p2.x()-p1.x())*(p1.y() - p.y()) - (p1.x() - p.x())*(p2.y()-p1.y()));
  double denominator = std::pow(std::pow(p2.x()-p1.x(),2)+std::pow(p2.y()-p1.y(),2),0.5);
  return numerator/denominator;
}