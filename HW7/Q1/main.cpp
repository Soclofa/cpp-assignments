//
//  main.cpp
//  Shapes
//
//  Created by Avi Soclof on 4/13/22.
//This program contains an abstract parent class Shape which different shapes as its derived classes.
//each derived class is able to calculate area and if they are a special feature of that specific shape.
//The main program allows for the user to choose the amount of shapes and to input the points of the shape and to print out the appropriate attributes of each input shape.

#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include <iostream>
using namespace std;

enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE };
int main() {
    Point p;
    
    int numShapes, choice;
    cout << "How many shapes you would like to define?\n";
    cin >> numShapes;
    Shape** shapes = new Shape * [numShapes];
    
    for (int i = 0; i < numShapes; i++) {
        cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
        cin >> choice;
        switch (choice) {
        case CIRCLE:
            int radius;
            cout << "Enter radius:\n";
            cin >> radius;
            shapes[i] = new Circle(radius);
            break;
        case TRIANGLE:
            shapes[i] = new Triangle();
            break;
        case RECTANGLE:
                shapes[i] = new Rectangle();
            break;
        default:
            cout << "invalid input\n";
            i--;
        }
    }

    for (int i = 0; i < numShapes; i++){
        cout << "points: " <<  *(*(shapes+i)) << "area is: " << shapes[i]->area() << " ";
        if (shapes[i]->isSpecial()){
            cout << endl;
            shapes[i]->printSpecial();
            }
        cout << endl;
        }
        
          //freeing memory allocated for the array of shapes 
        for( int i = 0 ;i < numShapes; ++i){
            delete shapes[i];
        }
            delete [] shapes;
 
    return 0;
    }

/*
 
 
 How many shapes you would like to define?
 3
 Which shape will you choose? Circle - 1, Triangle - 3, Rectangle – 4
 3
 Enter values of  3 points:
 (0,0) (1,0) (1,1)
 Which shape will you choose? Circle - 1, Triangle - 3, Rectangle – 4
 1
 Enter radius:
 4
 Enter values of  1 points:
 (0,0)
 Which shape will you choose? Circle - 1, Triangle - 3, Rectangle – 4
 2
 invalid input
 Which shape will you choose? Circle - 1, Triangle - 3, Rectangle – 4
 4
 Enter values of  4 points:
 (0,0) (1,0) (1,1) (0,1)

 points: (0,0) (1,0) (1,1)  area is: 0.5

 points: (0,0) area is: 50.24
 A canonical circle with a radius 4

 points: (0,0) (1,0) (1,1) (0,1)  area is: 1
 Square with side length 1

 */
