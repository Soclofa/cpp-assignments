//
//  Employee.hpp
//  Question 2
//
//  Created by Avi Soclof on 2/21/22.
//

#ifndef Employee_h
#define Employee_h
#include <iostream> 
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std; 

//ininitalizes class of employee
class employee {
    
private:
    int SS;
    float HourlyWage;
    char name[21];
    int hoursWorked;
    float moneyCollected;
    
    float CalculateSalary();

    
public:
    
    //Social Security Number
    void setSS(int);
    int getSS();
    
    //Hourly Wage
    void setHourlyWage(float);
    float getHourlyWage();
    
    //Name
    void setName(char*);
    char* getName();
    
    //Hour Worked
    void setHoursWorked(int);
    int getHoursWorked();
    
    // Money Collected
    void setmoneyCollected(float);
    int getMoneyCollected();
    
    float getSalary();
   

};



#endif /* Employee_hpp */
