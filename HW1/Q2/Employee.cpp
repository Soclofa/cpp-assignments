//
//  Employee.cpp
//  Question 2
//
//  Created by Avi Soclof on 2/21/22.
//

#include "Employee.h"


//setter Social Security
void employee::setSS(int socialSecurity){
    SS = socialSecurity;
}
//getter Social Security
int employee::getSS(){
    return SS; 
}

// Hourly Wage
//setter
void employee::setHourlyWage(float wage){
    HourlyWage = wage;
}
//getter
float employee::getHourlyWage(){
    return HourlyWage;
}

//Name
//setter
void employee::setName(char* _name){
    strcpy(name, _name);
}
//getter
char* employee::getName(){
    return name;
}

//Hour Worked
//setter
void employee::setHoursWorked(int hrs){
    hoursWorked = hrs;
}
//getter
int employee::getHoursWorked(){
    return hoursWorked;
}


// Money Collected
//setter
void employee::setmoneyCollected(float money){
    moneyCollected = money;
}
//getter
int employee::getMoneyCollected(){
    return moneyCollected; 
}

//salary
//getter
float employee::getSalary(){
    return CalculateSalary();
}

//calculate salary - private
float employee::CalculateSalary(){
    float salary = 0;
    int diff = 0;
    
/* Salary <= 1000 = 10%
   Salary <= 2000 = 15%
   Salary <= 4000 = 20%
   Salary <= 5000 = 30%
   Salary > 5000 = 40%
 */
    

    if (moneyCollected <= 1000){
        salary = moneyCollected*.10;
    }
    
    else if (moneyCollected > 1000 && moneyCollected <= 2000 ){
        
        diff = moneyCollected - 1000;
        
        salary = (1000*.10) + diff*.15;
       
    }
    
    else if (moneyCollected > 2000 && moneyCollected <= 4000 ){
        
        diff = moneyCollected - 2000;
        
        salary = (1000*.10) + (1000*.15) + (diff*.20);
    }
    
    else if (moneyCollected > 4000 && moneyCollected <= 5000 ){
        
        diff = moneyCollected - 4000;
        
        salary = (1000*.10) + (1000*.15) + (2000*.20) + (diff*.30);
    }

    else if(moneyCollected > 5000){
        
        diff = moneyCollected - 5000;
        
        salary = (1000*.10) + (1000*.15) + (2000*.20) + (1000*.30) + (diff*.40);
        
    }
    
    return hoursWorked*HourlyWage + salary;

}


