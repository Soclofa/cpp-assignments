//
//  Commander.cpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#include "Commander.hpp"

//constructor 
Commander::Commander(): PrivateSoldier(){
    isCombat = false;
}

//constructor 
Commander::Commander(int _id, string fName, string lName, int numOps): PrivateSoldier(_id, fName, lName, numOps){
    cout << "enter 1 if the soldier is combat and 0 if not" << endl;
    cin >> isCombat;
    
}

//copy constructor 
Commander::Commander (const Commander& source): PrivateSoldier(source){
    isCombat = source.isCombat;
}

//returns if commander is combat or not
bool Commander::getCombat(){
    return isCombat;
}

// //prints attributes the commander
void Commander::print() const {
    PrivateSoldier::print();
    cout << "combat: ";
    if (isCombat){
        cout << "yes";
    }
    else cout << "no";
    
    cout << endl;
}

//returns if the commander deserves a medal 
bool Commander::medal() const {
    if (!isCombat || numOperations < 7){
        return false;
    }
    
    int sum = 0;
    
    for (int i = 0; i < numOperations; i++){
        sum+= grades[i];
    }
    
    if (sum/numOperations < 90){
        return false;
    }
    
    return true;

    

}
//returns soldier type
const string Commander::soldierType() const {
    return "commander"; 
}
