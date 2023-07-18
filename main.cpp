#include <iostream>
#include "math.h"
#include <vector>
#include <array>

int subtract(int x, int y){
  // returns difference of x and y
  return x-y;
}

int multiply(int x, int y){
  // returns product of x and y 
  return x*y;
}

int divide(int x, int y){
  // returns division of x and y
  return x/y;
}

class Circle{
  private:
  int radius;
  public:
    Circle(int radius){
      this->radius = radius;
    }
    double area(){
      return M_PI*std::pow(radius,2);
    }
};

class Point{
  private:
    double x;
    double y;
  public:
    Point(double x, double y){
      this->x = x;
      this->y = y;
    }
    double distance_to_origin(){
      double distance = std::pow(std::pow(x,2) + std::pow(y,2),0.5);
      return distance;
    }
    double distance_to_point(const Point p){
      double distance = std::abs(std::pow(std::pow(p.x - x,2) + std::pow(p.y - y,2),0.5));
      return distance;
    }
};

class Line{
  private:
    Point p1;
    Point p2;
  public:
    Line(Point p1, Point p2){
      this->p1 = p1;
      this->p2 = p2;
    }
    double length(){
      return p1.distance_to_point(p2);
    }
};

class Triangle{
  private:
    Point p1;
    Point p2;
    Point p3;
  public:
    Triangle(Point p1, Point p2, Point p3){
      this->p1 = p1;
      this->p2 = p2;
      this->p3 = p3;
    }
    double area(){
      Line side1 = Line(p1,p2);
      Line side2 = Line(p2,p3);
      Line side3 = Line(p1,p3);
      double s = (side1.length() + side2.length() + side3.length()/2);
      double area = std::pow(s*(s-side1.length())*(s-side2.length())*(s-side3.length()),0.5);
      return area;
    }
    
};

class Polygon{
  private:
    std::vector<Point> vec;
  public:
    Polygon(std::vector<Point> vec){
      this->vec = vec;
    }
    double area(){
      double sum = 0.0;
      for(int i =1; i < vec.size()-1; i++){
        Triangle t = Triangle(vec[0],vec[i],vec[i+1]);
        sum += t.area();
      }
      return sum;
    }
    double perimeter(){
      double sum = 0.0;
      for(int i = 0; i < vec.size()-1; i++){
        // use distance from points
        Line l = Line(vec[i],vec[i+1]);
        sum += l.length();
      }
      Line k = Line(vec[0],vec[vec.size()-1]);
      sum += k.length();
      return sum;
    }
};

class AUV{
  public:
    std::string name;
    Point position;
    double depth;
    double heading;
    std::array<double,3> speed;
    double angular_speed;
    void step(const double dt){
      position.x += speed[0]*dt;
      position.y += speed[1]*dt;
      depth += speed[2]*dt;
      heading += angular_speed*dt;
    }
    void apply_acceleration(const std::array<double,3> lin_accel, const double dt){
      speed[0] += lin_accel[0]*dt;
      speed[1] += lin_accel[1]*dt;
      speed[2] += lin_accel[2]*dt;
    }
    void apply_angular_acceleration(const double angular_acceleration, const double dt){
      angular_speed += angular_acceleration*dt;
    }
};



int main()
{
  std::cout << "Daniela" << std::endl;
  std:: cout << "24-115" << std::endl;
  std::cout << "Hello, world!" << std::endl;

  int x = 5;
  int y = 7;
  int z = x+y;
  std::cout << x+y << std::endl;
  std::cout << z << std::endl;
  int w = x*y*z;
  std::cout << x*y*z << std::endl;
  std::cout << w << std::endl;
  int v = x/y;
  std::cout << x/y << std::endl;
  std::cout << v << std::endl;
  // Circle c;
  // c.radius = 2;
  // std::cout << c.area() <<std::endl;

  return 0;
}

