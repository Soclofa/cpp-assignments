//
//  Shape.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//

#include "Shape.hpp"

//empty constructor
Shape::Shape(): numOfPoints(0), points(nullptr){}

//constructor - inputs points based on user input and amount of points in the shape
Shape::Shape(int num): numOfPoints(num), points(new Point[num]) {
    
    //allows for user to input points using the overloaded Point class istream operator
    cout << "Enter values of " <<  num << " points" << endl;
    for (int i = 0; i < num; ++i){
        cin >> points[i];
    }
}

//destructor - virtual destructor
 Shape::~Shape(){
     delete [] points;
 }

//copy constructor
Shape::Shape(Shape& source): numOfPoints(source.numOfPoints){
    if (source.points!= nullptr){
        points = new Point[numOfPoints];
        for (int i = 0; i < numOfPoints; ++i ){
            points[i] = source.points[i];
        }
    }
}


//move constructor
Shape::Shape(Shape&& source):numOfPoints(source.numOfPoints){
    
    
    if (source.points!=nullptr){
        points = new Point[numOfPoints];
        for (int i = 0; i < numOfPoints; ++i ){
            points[i] = source.points[i];
        }
    }
    
    //resets values of r value (source)
    source.points = nullptr;
    source.numOfPoints = 0;
}




//ostream operator
ostream& operator << (ostream& os , Shape& source){
    
    //acesses points and prints the points in the form: (x,y)
    
    for (int i = 0; i < source.numOfPoints; ++i){
        os << "(" << source.points[i].getX() << "," << source.points[i].getY() << ")" << " ";
    }
    return os;
}


//used to determine if all the sides of the shape are equal. Used in triangle and Rectangle
//this assumes the points are input in order
bool Shape::equalDistances(){
    
    //calculates the distance between a and b
    //sets it to previousDistance
    float previousDistance = points[0].distance(points[1]);
    
    float currentDistance;
    
    int i;
    //itterates through the array of points
    for (i = 1; i < numOfPoints-1; ++i){
        //currentDistance is the distance between the next set of points in the array
        currentDistance = points[i].distance(points[i+1]);
        //the previous distance and current distance are compared
        //if they are not equal, then not all the sides are equal
        //returns false
        if (previousDistance != currentDistance){
            return false;
        }
        //sets previous distance to the value of current distance and repeats
        previousDistance = currentDistance;
    }
    
    //all sides have had their distances calculated except for the side that connects the last point and the first point.
    //distance is calculated
    currentDistance = points[i].distance(points[0]);
    //all prior sides have been checked and therefore if the last side is equal then function returns true, otherwise it is false; 
    return currentDistance == previousDistance;
}
