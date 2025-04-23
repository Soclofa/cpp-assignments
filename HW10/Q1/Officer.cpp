//
//  Officer.cpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#include "Officer.hpp"

//constructor 
Officer::Officer(): Soldier(){
    socio = 0;
}

//constructor 
Officer::Officer(int _id, string fName , string lName, int numOps):Soldier(_id, fName, lName, numOps){
    cout << "enter the sociometric score" << endl;
    cin >> socio;
}

//copy constructor 
Officer::Officer(const Officer& source): Soldier(source){
    socio = source.socio;
}

//returns if officer is deserving of a medal 
bool Officer::medal() const {
    if (numOperations <=2 || socio < 92){
        return false;
    }
    
    return true;
}


//returns officer 
const string Officer::soldierType() const {
    return "officer";
}

//prints officer attributes
void Officer::print() const{
    Soldier::print();
    
    cout << "sociometric score: " << socio << endl;
    
}

//getter for the sociometric score 
int Officer::getSocio() const{
    return socio; 
}
