//
//  main.cpp
//  Homework 6
//
//  Created by Avi Soclof on 4/1/22.
// Create a parent class called Employee that holds the values of the employee. 
//create two children classes. One that represents fulltime employees and one that represents parttime employees
//

#include "Employee.hpp"
#include "FullTime.hpp"
#include "PartTime.hpp"
#include <iostream>
using namespace std;

int main()
{
    FullTime arrF[3];
    for (int i = 0; i < 3; i++)
    {
        try
        {
            cin >> arrF[i];
        }
        catch (const char* str)
        {
            cout << str << endl;
            i--;
        }
    }


    PartTime arrP[3];
    for (int i = 0; i < 3; i++)
    {
        try
        {
            cin >> arrP[i];
        }
        catch (const char* str)
        {
            cout << str << endl;
            i--;
        }
    }


    for (int i = 0; i < 3; i++)
    {
        cout << arrF[i];
        cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
    }


    for (int i = 0; i < 3; i++)
    {
        cout << arrP[i];
        cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
    }
    return 0;
}


/* 
Enter employee details:
moshe  1234 3 36000
Enter employee details:
miriam  4321 8 48000
Enter employee details:
aharon  5678 4 160 35

Employee: moshe 
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000
After Bonus: 3500

Employee: miriam
Employee ID: 4321
Years Seniority: 8
Salary per Month: 4000
After Bonus: 5000

Employee: aharon 
Employee ID: 5678
Years Seniority: 4
Hours: 160
Salary per Month: 5600

*/