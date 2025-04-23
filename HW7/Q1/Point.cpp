//
//  Point.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#include "Point.hpp"
#include <cmath>

//empty constructor
Point::Point(): x(0),y(0){}

//constructor
Point::Point (int _x, int _y): x(_x), y(_y) {}

//setters
//sets X
void Point::setX(const int myX){
    x = myX;
    
}
//sets Y
void Point::setY(const int myY){
    y = myY;
}

//getters
//returns x
int Point::getX() const{
    return x;
}
//returns y
int Point::getY() const{
    return y;
}

//distanced between two points using distance formula
float Point::distance(Point& p){
    return sqrt ((pow((x - p.x),2)) + (pow((y - p.y),2)));
}

//istream operator
//allows for user to input point in the form: (x,y)
istream& operator >> (istream& is, Point& p){
    char inputParAndComma;
   
    is >> inputParAndComma >> p.x >> inputParAndComma >> p.y >> inputParAndComma; 
    
    return is;
}
