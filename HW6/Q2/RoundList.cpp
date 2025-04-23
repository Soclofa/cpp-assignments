//
//  RoundList.cpp
//  Homework 6 Question 2
//
//  Created by Avi Soclof on 4/3/22.
//

#include "RoundList.hpp"

//constructor creates an empty list using the parent constructor
RoundList::RoundList(): List() {
}

//copy constructor 
RoundList::RoundList(const RoundList& rl){
 
 //returns if recieved empty list
    if (rl.head == nullptr){
        head = nullptr;
        return;
    }
    
    else {
        //initializes the head of the list to be copied to 
         head = new Link ((rl.head->next->value), nullptr);
        
        //head points to the first element which here is the head
        head->next = head;
        
        //the first elemtent of the list is head
        Link* firstElement = head;
        //initialize the source to be the head of the value of the instance passed in the parameter 
        Link* source = rl.head;
        //current points to the head of the first Element
        Link* current = firstElement;
        
        //itterates through list that was passed in parameter until it reaches the head
        while (source->next != rl.head){
            //copies the value
            current->next = new Link ((source->next)->value, firstElement);
            //increments the source and current pointers to next the elements of the list
            source = source->next;
            current = current->next;
        }
    }
}

//returns if list is empty using parent class 
bool RoundList::isEmpty() {return List::isEmpty();}

//removes first value 
void RoundList::removeFirst()
{
    //make sure list is not empty
    if(isEmpty())
        return;
    
    //deletes head if it is the only value in the list
    if (head->next == head){
        head->next = nullptr; 
        clear();
        return;
    }
    
    //pointer to the first element
    Link* firstElement = head->next;
    
    //head points to the element after the first element
    head->next = firstElement->next;
    
    //first element is set to nullptr and delete it
    firstElement->next = nullptr;
    delete firstElement;
}

//adds link to the first 
void RoundList::add(int val)
{

   //if list is empty, adds new link usint the parent class and has it point to the head
    if (isEmpty()){
        List::add(val);
        head->next = head;
        return;
    }
    Link* firstElement = head->next; 
    //inputs a new first element with the head pointing to it
    head->next = new Link(val,firstElement);
    
}

//add to end add link to after the head but before the first element 
void RoundList::addToEnd(int val){
    
    if (isEmpty()){
        add(val);
        head->next = head;
        return;
    }
    Link* firstElement = head->next; 
    head->next = new Link (val, firstElement);
    head = head->next; 
    
}

//destructor
RoundList::~RoundList(){
    clear();
}

//clears list using parent class
void RoundList::clear()
{
    List::clear();
}


//search continuosly itteraters throught continuos list until it reaches n and prints the value at that index
int RoundList::search(int n){
    int count = 0;
    
    if (head->next == nullptr){
        return -1;
    }
    
    if (n ==0){
        return (head->next)->value; 
    }
    
    Link* current = head;
    while (count <= n){
        current = current->next;
        ++count;
    }
    return current->value;
}


//itterates and prints value of continuos list
ostream& operator << (ostream& os, RoundList& rl){
    
    if (rl.isEmpty()){
        return os;
    }
    else{
    RoundList::Link* current = rl.head->next;
        
        //while loop stops when it reaches rl.head
    while (current != rl.head){
        os << current->value << " ";
        current = current->next; 
    }
}
    os << rl.head ->value; 
    return os;
}
