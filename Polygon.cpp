#include "Point.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include <vector>
#include <cmath>

Polygon::Polygon(std::vector<Point> vec){
      this->vec = vec;
}

double Polygon::area(){
    double sum = 0.0;
    for(int i =1; i < vec.size()-1; i++){
        Triangle t = Triangle(vec[0],vec[i],vec[i+1]);
        sum += t.area();
    }
    return sum;
}
double Polygon::perimeter(){
    double sum = 0.0;
    for(int i = 0; i < vec.size()-1; i++){
        sum += vec[i].distance_to_point(vec[i+1]);
    }
    sum += vec[0].distance_to_point(vec[vec.size()-1]);
    return sum;
}