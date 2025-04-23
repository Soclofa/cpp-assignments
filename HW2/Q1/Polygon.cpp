//
//  Polygon.cpp
//  Homework #2
//
//  Created by Avi Soclof on 2/25/22.
//

#include "Polygon.h"

//empty constructor
polygon::polygon(){
    amountVertices = 0;
    array = nullptr;
    cout << "in empty constructor" << endl;
}

//regular constructor
polygon::polygon(int numPoints){
    amountVertices = numPoints;
    array = new point[numPoints];
    cout << "in one parameter constructor" << endl;
}

//copy constructor
polygon::polygon (const polygon& polygon1){
    amountVertices = polygon1.getAmountVertices();
    array = new point[amountVertices];
    for (int i = 0; i < amountVertices; i++){
        array[i] = polygon1.array[i];
    }
    cout << "in copy constructor" << endl;
}

//destructor
polygon::~polygon(){
    if (array != nullptr && amountVertices > 0){
    delete [] array;
        array = nullptr; 
    cout << "in destructor" << endl;
    }
}

//getter
point* polygon::getPolygon() const{
    return array;
}

int polygon::getAmountVertices() const{
    return amountVertices;
}

void polygon::addPoint(int index, point p1) {
    if (index < amountVertices && index >= 0)
    {
        array[index] = p1;
    }}

//returns the perimeter of the polygon
float polygon::perimeter() const{
    float p = 0;
    p = array[0].distance(array[amountVertices-1]);

    for (int i=0; i < amountVertices-1; i++){
        p += array[i].distance(array[i+1]);
    }
    
    return p;
}

//returns if the vertices of a polygon is equal
bool polygon::equal (polygon polygon1) const{
    bool equals = false;
    if (polygon1.getAmountVertices() != amountVertices){
        return false;
    }
    
   
    for (int i = 0; i < amountVertices; i++ ){
        for (int j = 0; j < amountVertices; j++){
             if (array[i].getX() == polygon1.array[j].getX() && array[i].getY() == polygon1.array[j].getY()){
                equals = true;
                break;
            }
            
        }
        if (!equals){
            return false;
        }
        equals = false;
    }
    
    return true;
}
