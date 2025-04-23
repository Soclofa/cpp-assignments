//
//  Vector.hpp
//  Question 2
//
//  Created by Avi Soclof on 2/25/22.
//

#ifndef Vector_h
#define Vector_h



#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
class Vector{

private:
    int* data = new int[0];
    int capacity;
    int size;

public:
    //empty
    Vector();
    //constructor
    Vector(int);
    //copy constructor
    Vector(const Vector&);
    //destructor
    ~Vector();
    
    
    
    
    //concatenates the array of integers
    Vector strnewcat(const Vector&);
    void insert();
    
    int getCapacity();
    int getSize();
    void print();
    
    void assign (const Vector&);
    bool isEqual( const Vector&);
    int& at(int);
    int scalmul (const Vector&);
    void clear();
    void delLast();
    void insert(int); 
    
    
};

#endif /* Vector_hpp */
