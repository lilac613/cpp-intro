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
  /*private:
    double x;
    double y;*/
  public:
    /*Point(double x, double y){
      this->x = x;
      this->y = y;
    }*/
    double x;
    double y;
    double distance_to_origin(){
      double distance = std::pow(std::pow(x,2) + std::pow(y,2),0.5);
      return distance;
    }
    double distance_to_point(Point p){
      double distance = std::abs(std::pow(std::pow(p.x - x,2) + std::pow(p.y - y,2),0.5));
      return distance;
    }
    /*double get_x(){
      return x;
    }
    double get_y(){
      return y;
    }
    void change_x(double amt){
      x+=amt;
    }
    void change_y(double amt){
      y+=amt;
    }*/
};

class Line{
  /*private:
    Point p1;
    Point p2;*/
  public:
    /*Line(Point p1, Point p2){
      this->p1 = p1;
      this->p2 = p2;
    }*/
    Point p1;
    Point p2;
    double length(){
      return p1.distance_to_point(p2);
    }
    double distance_to_point(Point p){
      double numerator = std::abs((p2.x-p1.x)*(p1.y - p.y) - (p1.x - p.x)*(p2.y-p1.y));
      double denominator = std::pow(std::pow(p2.x-p1.x,2)+std::pow(p2.y-p1.y,2),0.5);
      return numerator/denominator;
    }
};

class Triangle{
  /*private:
    Point p1;
    Point p2;
    Point p3;*/
  public:
  /*// p1, p2, and p3 need parameters because there is no null constructor
    Triangle(Point p1, Point p2, Point p3){
      this->p1 = p1;
      this->p2 = p2;
      this->p3 = p3;
    }*/
      Point p1;
      Point p2;
      Point p3;
    double area(){
      /*Line side1 = Line(p1,p2);
      Line side2 = Line(p2,p3);
      Line side3 = Line(p1,p3);*/
      Line side1;
      side1.p1 = p1;
      side1.p2 = p2;
      Line side2;
      side2.p1 = p2;
      side2.p2 = p3;
      Line side3;
      side3.p1 = p1;
      side3.p2 = p3;
      double s = (side1.length() + side2.length() + side3.length()/2);
      double area = std::pow(s*(s-side1.length())*(s-side2.length())*(s-side3.length()),0.5);
      return area;
    }
    
};

class Polygon{
  /*private:
    std::vector<Point> vec;*/
  public:
    std::vector<Point> vec;
    /*Polygon(std::vector<Point> vec){
      this->vec = vec;
    }*/
    double area(){
      double sum = 0.0;
      for(int i =1; i < vec.size()-1; i++){
        Triangle t;
        t.p1 = vec[0];
        t.p2 = vec[i];
        t.p3 = vec[i+1];
        sum += t.area();
      }
      return sum;
    }
    double perimeter(){
      double sum = 0.0;
      for(int i = 0; i < vec.size()-1; i++){
        sum += vec[i].distance_to_point(vec[i+1]);
      }
      sum += vec[0].distance_to_point(vec[vec.size()-1]);
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
    void step(double dt){
      position.x += (speed[0]*dt);
      position.y += (speed[1]*dt);
      depth += speed[2]*dt;
      heading += angular_speed*dt;
    }
    void apply_acceleration(std::array<double,3> lin_accel, double dt){
      speed[0] += lin_accel[0]*dt;
      speed[1] += lin_accel[1]*dt;
      speed[2] += lin_accel[2]*dt;
    }
    void apply_angular_acceleration(double angular_acceleration, double dt){
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

