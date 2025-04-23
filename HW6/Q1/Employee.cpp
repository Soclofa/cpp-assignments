//
//  Employee.cpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#include "Employee.hpp"
#include <iostream>
using namespace std;

//constructor
Employee::Employee() : name(""), id(0),seniority(0), pay(0) {}

//constructor with parameters
Employee::Employee(string _name, int _id, int _seniority): pay(0){
    
    name = _name;
    
    //only initializes values of parameters if they are valid and do not throw an exception
    try {
        setID(_id);
    }
    catch (const char*){
        id = 0;
        throw;
    }
    
    try {
        setSeniority(_seniority);
    }
    catch (const char*){
        seniority = 0;
        throw;
    }
}

//copy constructor
Employee::Employee(const Employee& person){
    
    name = person.name;
    id = person.id;
    seniority = person.seniority;
    pay = person.pay;
    
}

//getters
string Employee::getName() const{
    return name;
}
int Employee::getID() const{
    return id;
}
int Employee::getSeniority() const{
    return seniority;
}
float Employee::getPay() const{
    return pay;
}

//setters 
void Employee::setName(string _name){
    name = _name;
}

//checks for valid id input
void Employee::setID(int _id){
    if (_id <= 0){
        throw "ERROR";
    }
    
    id = _id;
}

//checks for valid seniority input
void Employee::setSeniority(int _seniority){
    if (_seniority < 0){
        throw "ERROR";
    }
    seniority = _seniority;
}

//calculates the pay of each employee based on seniroity
float Employee::salaryAfterBonus(){
    if (seniority <= 5){
        return pay + 500;
    }
     
    return pay*1.25;
}

//print function allows for inheritance in the ostream operators
void Employee::print() const{
    
    cout << "Employee: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Years Seniority: " << seniority << endl;
    
}

//input streams, checks for valid input values before inputting into instance of Employee
 istream& operator>>(istream& is, Employee& person){
     cout << "Enter employee details:" << endl;
     int _id;
     int _seniority;
     is >> person.name >> _id >> _seniority;
    
     try {
         person.setID(_id);
     }
     catch (const char*){
         person.id = 0;
         throw;
     }
     
     try {
         person.setSeniority(_seniority);
     }
     catch (const char*){
         person.seniority = 0;
         throw;
     }
     
    return is;
}

//calls print function and values of the instance
 ostream& operator<< (ostream& os, Employee& person){
     person.print();
     return os;
}
