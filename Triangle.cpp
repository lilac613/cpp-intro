#include "Line.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include <cmath>
Triangle::Triangle(Point pa, Point pb, Point pc) : p_1(pa), p_2(pb), p_3(pc){
}

double Triangle::area(){
  Line side1 = Line(p_1,p_2);
  Line side2 = Line(p_2,p_3);
  Line side3 = Line(p_1,p_3);
  double s = (side1.length() + side2.length() + side3.length()/2);
  double area = std::pow(s*(s-side1.length())*(s-side2.length())*(s-side3.length()),0.5);
  return area;
}