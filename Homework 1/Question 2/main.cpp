//
//  main.cpp
//  Workshop C++
//  Homework Assignment #1
//  Question #2
//
//  Avi Soclof
//  ID 674098915

#include "Employee.h"


int main (){
    
    char name[21];
    int social_security = 1;
    float hourly_wage;
    int hours_worked;
    int money_collected;
    
    bool counter = 0;
  
    //initalizes object employee called person
    employee person;
    //intializes object employee with highest salary
    employee highestSalary;
    
    //set intital salary to 0
    highestSalary.setmoneyCollected(0);
    
    //intializes object employee with minimum sum collected
    employee minimumSum;
    

    cout << "enter details, to end enter 0:" << endl;
    //loop stops at the input of social security of 0
    while (social_security) {
        
        cin >> social_security;
        
        if (!social_security){
            break;
        }
       
       cin >> name;
       cin >> hourly_wage >> hours_worked >> money_collected;
       
        //tests for valid inputs
       while (social_security < 0 || hourly_wage < 0 || hours_worked < 0 || money_collected < 0){
           cout << "ERROR" << endl;
           
           cin >> social_security;

           if (!social_security){
               break;
           }
           
           else {cin >> name >> hourly_wage >> hours_worked >> money_collected;}
       }
       
        if (!social_security){
            break;
        }
       
        //sets values based on input
        person.setSS(social_security);
        
        person.setName(name);
        
        person.setHourlyWage(hourly_wage);
        
        person.setHoursWorked(hours_worked);
        
        person.setmoneyCollected(money_collected);
        
        //checks for highest salary and for minimum sum collected employee
        if (person.getSalary() > highestSalary.getSalary()){
            highestSalary = person;
        }
        
        if (!counter){
            minimumSum = person;
        }
        else if (person.getMoneyCollected() < minimumSum.getMoneyCollected()){
            minimumSum = person;
        }
        counter = true;
   }
    
    //prints info for highest salary and minimum collected employees
    cout << "minimum collected: ";
       cout << minimumSum.getSS() << " ";
    cout << minimumSum.getName() << " ";
     cout << minimumSum.getMoneyCollected() << endl;
    
    cout << "highest salary: ";
      cout << highestSalary.getSS() << " ";
    cout << highestSalary.getName() << " ";
  cout << highestSalary.getSalary() << endl;
    
   
    
    return 0;
}


/*
Sample Code:
 enter details, to end enter 0:
 123456789    moshe   50  40  2000
 135792468    rivka    120  55  3450
 97531246        sara  35  100   5632
 0
 minimum collected: 123456789 moshe 2000
 highest salary: 135792468 rivka 7140 */
