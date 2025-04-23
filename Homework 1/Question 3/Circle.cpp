//
//  Circle.cpp
//  Question3
//
//  Created by Avi Soclof on 2/21/22.
//

#include "Circle.hpp"
#include <cmath>

//setter  center
void Circle::setCenter(int x, int y){

    center.setX(x);
    center.setY(y);
}
//setter radius
void Circle::setRadius(int myRadius){
    
    radius = myRadius;
}

//getter center
Point Circle::getCenter(){
    return center;
}

//getter radius
int Circle::getRadius(){
    return radius;
}

//returns area of circle
float Circle::area(){
    return PI*pow(radius,2);
}

//returns perimeter of circle
float Circle::perimeter(){
    return 2*PI*radius;
    
}

//calculates the distance from center to point
//if distance <= radius it is considred within the circle
int Circle::onInOut(Point p){
    float distance = sqrt(pow(center.getX() - p.getX(),2) + pow(center.getY() - p.getY(),2));
    
    //returns 0
    if (distance == radius)
        return false;
    
    //returns -1
    if (distance < radius){
        return -1;
    }
    
    //returns 1 if point is not within the circle
    return true;
}
