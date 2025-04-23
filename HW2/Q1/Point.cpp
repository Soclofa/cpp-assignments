//
//  Point.cpp
//  Homework #2
//
//  Created by Avi Soclof on 2/24/22.
//

#include "Point.h"

//empty constructor
 point::point(){
    x = 0;
    y = 0; 
}

//regular constructor
point::point(int _x, int _y){
    x = _x;
    y = _y;
}

//copy constructor
point::point (const point& a){
    x = a.x;
    y = a.y;
}
                                                    

void point::setX(int _x){
    x = _x;
}

void point::setY(int _y){
    y = _y;
}

int point::getX(){
    return x;
}
int point::getY(){
    return y;
}
//returns the distance of two points
float point::distance(point& p1){
    return sqrt(pow(x - p1.x,2) + pow(y - p1.y,2));
}
