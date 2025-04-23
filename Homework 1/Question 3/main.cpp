//
//  main.cpp
//  Workshop C++
//  Homework Assignment #1
//  Question #2
//
//  Avi Soclof
//  ID 674098915



#include <iostream>
#include "Circle.hpp"
using namespace std;

int main(){
    cout << "enter the center point and radius of 3 circles:" << endl ;
    
    int x, y, radius;
    
    char parent;
    char comma;
    
    Circle A;
    Circle B;
    Circle C;
    
    int a_Counter = 0;
    int b_Counter = 0;
    int c_Counter = 0;
    
    //Set center and radius for circles  A B C
    cin >> parent >>  x >> comma >> y >> parent >> radius;
    A.setCenter(x, y);
    A.setRadius(radius);
    
    cin >> parent >>  x >> comma >> y >> parent >> radius;
    B.setCenter(x, y);
    B.setRadius(radius);
    
    cin >> parent >>  x >> comma >> y >> parent >> radius;
    C.setCenter(x, y);
    C.setRadius(radius);
    
    //Prints out perimeter and areas for  A B C
    cout << "perimeter: A: " << A.perimeter() << " B: " << B.perimeter() << " C: " << C.perimeter() << endl;
    cout << "Area: A: " << A.area() << " B: " << B.area() << " C: " << C.area() << endl;
    
    cout << "enter points until (0,0):" << endl;
    
    Point input;
    
    x= 1; y = 1;
    
    //recieves points until (0,0) is input
    //counts how many times each point is found  on or within all three circles
    while (x || y){
        
        cin >> parent >> x >> comma >> y >> parent;

        if (!x && !y){
            break;
        }

        input.setX(x);
        input.setY(y);
        
        if (A.onInOut(input) == 0 || A.onInOut(input) == -1){
            a_Counter++;
        }
        
        if (B.onInOut(input) == 0 || B.onInOut(input) == -1){
            b_Counter++;
        }
        
        if (C.onInOut(input) == 0 || C.onInOut(input) == -1){
            c_Counter++;
        }
    }
       
        cout << "num of points in circle: A: " << a_Counter << " B: " << b_Counter << " C: " << c_Counter << endl;
        
    
    
    return 0;
}

/*
 Sample Code:
 
 enter the center point and radius of 3 circles:
 (0,0) 3
 (1,1) 2
 (5,5) 2
 perimeter: A: 18.84 B: 12.56 C: 12.56
 Area: A: 28.26 B: 12.56 C: 12.56
 enter points until (0,0):
 (0,1)
 (1,0)
 (0,4)
 (0,0)
 num of points in circle: A: 2 B: 2 C: 0*/
