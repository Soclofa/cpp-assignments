//
//  List.cpp
//  List
//
//  Created by Avi Soclof on 3/30/22.
//

#include "List.hpp"

//------------------------------------------------
// class Link implementation
//------------------------------------------------
List::Link::Link( int val, Link* nxt) :
value(val), next(nxt) {}
List::Link::Link(const Link& source) :
value(source.value),next(source.next) {}


//--------------------------------------------
// class List implementation
//--------------------------------------------
List::List(): head(nullptr)
{
    // no further initialization
}

List::List(const List &l)
{
    Link *src, *trg;
    if(l.head== nullptr)
        head= nullptr;
    else
    {
        head= new Link((l.head)->value, nullptr);
        src=l.head;
        trg=head;
        while(src->next!= nullptr)
        {
            trg->next= new Link
            ((src->next)->value, nullptr);
            src=src->next;
            trg=trg->next;
        }
    }
}

List::~List()
{
    clear();
}

void List::clear()
{
    // empty all elements from the List
    Link* next;
    for (Link * p=head; p != nullptr; p=next)
    {
        // delete the element pointed to by p
        next=p->next;
        p->next= nullptr;
        delete p;
    }
    // mark that the List contains no elements
    head= nullptr;
}

bool List::isEmpty() const
{
    // test to see if the List is empty
    // List is empty if the pointer to the head
    // Link is null
    
    return head == nullptr;
    
}

void List::add( int val)
{
    //Add a new value to the front of a Linked List
    head=new Link(val, head);
    if(head== nullptr)
        throw "failed in memory allocation";
}


int List::firstElement() const
{
    // return first value in List
    if (isEmpty())
        throw "the List is empty, no first Element";
    return head->value;
}

bool List::search(const int &val) const
{
    // loop to test each element
    for (Link* p=head; p!= nullptr; p=p->next)
        if (val == p->value)
            return true;
    // not found
    return false;
}


void List::removeFirst()
{
    // make sure there is a first element
    if(isEmpty())
        throw "the List is empty, no Elements to remove";
        // save pointer to the removed node
        Link* p=head;
    // reassign the first node
    head= p->next;
    p->next = nullptr;
    // recover memory used by the first element
    delete p;
}


//move constructor
List::List(List&& list){
    head = list.head;
    list.head = nullptr;
}

//ostream overoload
 ostream& operator<<(ostream& os, List& list){
     //initializes pointer a link 
     List::Link* current;
     
     //itterates through the list and prints out each value
     for ( current = list.head; current != nullptr; current = current->next){
         os << current-> value <<' ';
     }
    
     return os;
}

// istream overload inputs values into list as long as they are non-descending
 istream& operator>>(istream& is, List& list){
    //integers will allow for comparing the values of each key as it is input
     int curr, prev;
     
     //user inputs value of prev 
     is >> prev;
     
     //prev is added to the list
     list.add(prev);
     
     //current is set equal to the head of the list
     List::Link* current = list.head;
     
     // user input sets the next value
     is >> curr;
     
     //continues to take input as long as input remains nondescending
     while (curr < prev){
         //creates a new link that will be the tail using the value that was just input
         current->next = new List::Link(curr, nullptr);
         //current is set equal to the next link 
         current = current-> next;
         
         //prev is set to equal to the current input setting up for the next value to be input and checked
         prev = curr;
         //next value is input 
         is >> curr;
     }
     
     return is;
}


//copy assignment 
List& List::operator=(const List& link){
    
    if (this == &link){
        return *this;
    }
    
    clear();
    
    Link *src, *trg;
    if(link.head== nullptr)
        head= nullptr;
    else
    {
        head= new Link((link.head)->value, nullptr);
        src=link.head;
        trg=head;
        while(src->next!= nullptr)
        {
            trg->next= new Link
            ((src->next)->value, nullptr);
            src=src->next;
            trg=trg->next;
            }
        }
    
    return *this;
    }
    

//move assignment
List& List::operator= (List&& list){
    if (this == &list){
        return *this;
    }
    
    clear();
    
    head = list.head;
    list.head = nullptr;
   
    return *this;
}

//inserts value into sorted array 
void List::insert(int data){
    
    //empty array or data is the largest value, data becomes the head of the list 
    if (isEmpty() || firstElement() < data){
        add(data);
        return;
    }
    
    Link* current = head;
    //itterates through list and inputs data in sorted spot 
    for (current = head; current->next != nullptr; current = current->next ){
        if (current->next->value < data){
            //creates new link and inputs data and pointer to next link
            current->next = new Link(data, current->next);
            
            return;
        }
    }
    
    //if data is smaller than any value in the list, it is placed at the tail
    current->next =  new Link(data, nullptr);
        
}


//removes a value from the list
void List::remove(int data){
    
    //if empty
    if (isEmpty()){
        throw "value not found\n";
    }
    
    //if data is the first element then it is removed using the removeFirst function
    if (firstElement() == data){
        removeFirst();
        return;
    }
    
    Link* current;
    //itterates throught the list and if the value of data is found it is deleted and pointers readjusted  
    for (current = head; current->next != nullptr; current = current->next){
        
        if (current->next->value == data){
            delete current->next;
            current->next = (current->next)->next;
            return; 
        }
    }
//if data is not found
    throw "value not found\n"; 
}



