//
//  main.cpp
//  Homework #2
// Question 1
//  Created by Avi Soclof on 2/24/22.
//

#include <iostream>
#include "Polygon.h"
using namespace std;

int main(){
    
    
    int vertices;
    int x,y;
    char comma, parent;
    point xy;
    
    cout << "enter number of sides:" << endl;
    cin >>vertices;
    
    polygon poly1(vertices);
    
    cout << "enter the point values:" << endl;
    for (int i = 0; i < vertices; i++){
        cin >> parent >> x >> comma >> y >> parent;
        xy.setX(x);
        xy.setY(y);
        
        poly1.addPoint(i,xy);
    }
    
    cout << "enter number of sides:" << endl;
    cin >> vertices;
    
    polygon poly2(vertices);
    
    cout << "enter the point values:" << endl;

    for (int i = 0; i < vertices; i++){
        cin >> parent >> x >> comma >> y >> parent;
        xy.setX(x);
        xy.setY(y);
        
        poly2.addPoint(i,xy); 
        
    }
    
    
    
    if (poly1.equal(poly2)){
        cout << "equal" << endl;
        cout << "perimeter: " << round(poly1.perimeter()) << endl;
    }
    
    else {
        
    cout << "not equal" << endl;
    cout << "perimeter: " << round(poly1.perimeter()) << endl;
    cout << "perimeter: " << round(poly2.perimeter()) << endl;
    }
    
    return 0;
}

/*

enter number of sides:
4
in one parameter constructor
enter the point values:
(0,0) (0,2) (2,2) (2,0)
enter number of sides:
3
in one parameter constructor
enter the point values:
(1,1) (2,0) (3,1)
in copy constructor
in destructor
not equal
perimeter: 8
perimeter: 5
in destructor
in destructor

*/
