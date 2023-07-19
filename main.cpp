#include <iostream>
#include "math.h"
#include <vector>
#include <array>
#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include "AUV.hpp"

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

