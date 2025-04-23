//
//  Rectangle.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/14/22.
//

#include "Rectangle.hpp"

//calls shape constuctor, which dynamically allocates an array of four points and accepts user input to determine the points
Rectangle::Rectangle(): Shape(4){}

//The rectangle is considered special if all sides are the same (i.e it is a square).
//isSpecial calss the equalDistance function in the parent class and returns true if all the sides are the same
bool Rectangle::isSpecial()
{
    return Shape::equalDistances();
}

//if isSpecial is true, then printSpecial returns a special message with the distance of the length of one side
void Rectangle::printSpecial() {
    if (isSpecial()){
        cout << "Square with side length: " << points[0].distance(points[1]) << endl;
    }
}

//returns the area of the rectangle
float Rectangle::area(){

    //if all the sides are the same, then we return the distance of a side
    if (isSpecial()){
        return pow(points[0].distance(points[1]),2);
    }
    
    //else we return the value of two adjacent sides multiplied by one an other. 
    return points[0].distance(points[1])*points[3].distance(points[0]);
    
}
