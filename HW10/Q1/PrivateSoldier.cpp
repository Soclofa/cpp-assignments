//
//  PrivateSoldier.cpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#include "PrivateSoldier.hpp"

//constructor 
PrivateSoldier::PrivateSoldier(): Soldier(){
    grades = nullptr;
}

//constructor - allows user to input grades
PrivateSoldier::PrivateSoldier(int _id, string fName, string lName, int numOps): Soldier(_id, fName, lName, numOps){
    
    if (numOperations > 0){
        grades = new int[numOperations];
        
        cout << "enter " << numOperations << " grades" << endl;
        for (int i = 0; i < numOperations; i++){
            cin >> grades[i];
        }
    }
    else grades = nullptr;
}

//copy constructor
PrivateSoldier::PrivateSoldier(const PrivateSoldier& source): Soldier(source){
    if (numOperations > 0){
        grades = new int [source.numOperations];
        for (int i = 0; i < numOperations; i++){
            grades[i] = source.grades[i];
        }
    }
    else (grades = nullptr);
}


//destructor
PrivateSoldier::~PrivateSoldier(){
    if (grades){
        delete grades;
    }
}

//prints privates attributes
void PrivateSoldier::print()const {
    Soldier::print();
    
    if (grades){
        cout << "grades: ";
        for (int i = 0; i < numOperations; i++){
            cout << grades[i] << " ";
        }
    }
    cout << endl;
}

//returns private 
const string PrivateSoldier:: soldierType()const
{
    return "private";
}

//retursn if private is deserving of a mdeal 
bool PrivateSoldier::medal() const{
    
    if (numOperations < 10){
        return false;
    }
    
    int sum = 0;
    
    for (int i = 0; i < numOperations; i++){
        sum+= grades[i];
    }
    
    if (sum/numOperations < 95){
        return false;
    }
    
    return true;

}

