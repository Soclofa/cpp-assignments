//
//  Polygon.hpp
//  Homework #2
//
//  Created by Avi Soclof on 2/25/22.
//

#ifndef Polygon_h
#define Polygon_h

#include <stdio.h>
#include "Point.h"

class polygon {
    
private:
    point* array = new point[0]; 
    int amountVertices;
    
public:
    
    //empty constructor
    polygon();
    //regular constructor
    polygon(int);
    //copy constructor
    polygon (const polygon&);
    //destructor
    ~polygon();
    
    //getter
    point* getPolygon() const;
    
    int getAmountVertices() const;
    
    void addPoint(int, point);
    
    float perimeter() const;
    
    bool equal(polygon) const;

    
};




#endif /* Polygon_hpp */
