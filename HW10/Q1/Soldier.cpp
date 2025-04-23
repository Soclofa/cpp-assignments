//
//  Soldier.cpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
//

#include "Soldier.hpp"

//constructors
Soldier::Soldier(): id(0), first(""),last(""), numOperations(0){}

Soldier::Soldier(int i ,string f, string l, int nO) : id(i), first(f), last(l), numOperations(nO){}

//copy constructor
Soldier::Soldier(const Soldier& s): id(s.getId()), first(s.getFirst()), last(s.getLast()), numOperations(s.getNumOperations()){}



//print function
 void Soldier::print() const{
     cout << soldierType() << endl; 
     cout << "ID: " << id << endl;
     cout << "first name: " << first << endl;
     cout << "last name: " << last << endl;
     cout << "num operations: " << numOperations<<endl;
}


//setters
void Soldier::setId(int _id){
    id = _id;
}
void Soldier::setFirst(string fname){
    first = fname;
}
void Soldier::setLast(string lname){
    last = lname;
}
void Soldier::setNumOperations(int num){
    numOperations = num;
}

//getters
int Soldier::getId() const{
    return id;
}
string Soldier::getFirst() const{
    return first;
}
string Soldier::getLast() const{
    return last;
}
int Soldier::getNumOperations() const{
    return numOperations;
}
