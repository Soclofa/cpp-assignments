//
//  PartTime.cpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
//

#include "PartTime.hpp"

// constructor
PartTime::PartTime(): Employee(), hoursOfWork(0), payPerHour(0){}

//constructor with parameters using parent class 
PartTime::PartTime(string _name, int _id, int _seniority, float hoursWorked, float hourlyWage): Employee(_name, _id, _seniority){
    
    
    try {
        setHoursOfWork(hoursWorked);
    }
    catch (const char*){
        hoursOfWork = 0;
        throw;
    }
    
    try {
        setPayPerHour(hourlyWage);
    }
    catch (const char*){
        payPerHour = 0;
        throw;
    }
    
}
//copy constructor using parent class
PartTime::PartTime(PartTime& person) :Employee(person){
    hoursOfWork = person.hoursOfWork;
    payPerHour = person.payPerHour;
}

//getters
float PartTime::getHoursOfWork() const{
    return hoursOfWork;
}
float PartTime::getPayPerHour() const{
    return payPerHour;
}

//setters check for valid inputs
void PartTime::setHoursOfWork(float workHrs){
    if (workHrs < 0){
        throw "ERROR";
    }
    
    hoursOfWork = workHrs;
    salary();
}


void PartTime::setPayPerHour(float PPH){
    if (PPH < 0){
        throw "ERROR";
    }
    
    payPerHour = PPH;
    
    salary();
}

//print function with parent print function
void PartTime::print() const {
    Employee::print();
    
    cout << "Hours: " << hoursOfWork << endl;
    cout << "Salary Per Month: " << pay << endl;
    
}

//calculates pay based on hours and hourly pay 
void PartTime::salary(){
    
    pay = hoursOfWork*payPerHour;
    
    
}

//input values are checked if valid and set
istream& operator >> (istream& is, PartTime& person){
    
    cout << "Enter employee details:\n";

    int _id;
    int _seniority ;
    int hours;
    float _payPerHour;
    
    is >> person.name >> _id >> _seniority >> hours >> _payPerHour;
    
    try
    {
        person.setID(_id);
        person.setSeniority(_seniority);
        person.setHoursOfWork(hours);
        person.setPayPerHour(_payPerHour);
    }
    
    catch (const char*){
        person.id = 0;
        person.seniority = 0;
        person.hoursOfWork = 0;
        person.payPerHour = 0;
        person.pay = 0;
        throw;
    }
    
    return is;
}

//prints using print function
ostream& operator << (ostream& os, PartTime& person){
    person.print();
    
    return os;
}
