//
//  Circle.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#define PI 3.14
#include "Circle.hpp"


//this constructor sets the radius which is a parameter
//calls shape constuctor, which dynamically allocates an array of one point, the center and accepts user input to determine the point.
Circle::Circle(int r): radius(r), Shape(1){}

//An instance of a circle is has only one point representing the center
Circle::Circle(Circle& source): radius(source.radius){

    if (source.points != nullptr){
    points[0] = source.points[0];
    }
    
}

//returns true if circle is canonical,(i.e, its center is at (0,0)
bool Circle::isSpecial() {
    if (!points[0].x && !points[0].y){
        return true;
    }
    return false;
}

//prints special messages if isSpecial is true
void Circle::printSpecial() {
    if (isSpecial()){
        cout << "A canonical circle with a radius " << radius;
    }
}

//returns the area of the circle
float Circle::area() {
   return pow(radius,2)*PI;
}


