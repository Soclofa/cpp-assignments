//
//  Employee.hpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Employee {
    
protected:
    string name;
    int id;
    int seniority;
    float pay;
    
public:
    Employee();
    Employee(string, int, int);
    Employee(const Employee&);
    
    string getName() const;
    int getID() const;
    int getSeniority() const;
    float getPay() const;
    
    void setName(string);
    void setID(int);
    void setSeniority(int);
 
    
    float salaryAfterBonus() ;
    
    void print() const;
    
    friend istream& operator>>(istream&,  Employee&);
    friend ostream& operator<< (ostream&, Employee&);
};

#endif /* Employee_hpp */
