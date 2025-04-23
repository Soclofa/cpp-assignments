//
//  FullTime.cpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#include "FullTime.hpp"

//constructor
FullTime::FullTime(): Employee(), salaryPerYear(0){}

//constructor with parameters. Uses parent class to set name, id, and seniority. 
FullTime::FullTime(string _name, int _id, int _seniority, float _salaryPerYear): Employee(_name, _id, _seniority) {
    
    salaryPerYear = _salaryPerYear;
}

//copy constructor. uses copy constructor of parent class 
FullTime::FullTime(FullTime& person) : Employee(person){
    salaryPerYear = person.salaryPerYear;
}

//setters throw exceptions for invalid values
void FullTime::setSalaryPerYear(float _salary){
    if (_salary < 0 ){
        throw "ERROR";
    }
    
    salaryPerYear = _salary;
    salary();
}

float FullTime::getSalaryPerYear() const{
    return salaryPerYear;
}

//calculates monthly salary based on yearly pay
void FullTime::salary() {
    pay = salaryPerYear/12;
}

//prints employee values using parent class
void FullTime::print() const{
    
    Employee::print();
    cout << "Salary Per Month: " << pay << endl; 
}

//inputs values of the instance and checks for valid inputs
istream& operator >> (istream& is, FullTime& person){
    cout << "Enter employee details:" << endl; 
    is >> person.name;
    
    int _id, _seniority;
    float _salary;
    
    is >> _id >> _seniority >> _salary;
    
    try {
        person.setID(_id);
    }
    catch (const char*){
        throw;
    }
    
    try {
        person.setSeniority(_seniority);
    }
    catch (const char*){
        throw;
    }
    
    try {
        person.setSalaryPerYear(_salary);
    }
    catch (const char*){
        throw;
    }
    
    return is;
}

//prints using print function
ostream& operator << (ostream& os, FullTime& person){
    person.print();
    return os;
}
