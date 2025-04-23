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



List::List(List&& list){
    head = list.head;
    list.head = nullptr;
}

 ostream& operator<<(ostream& os, List& list){
     List::Link* current;
     
     for ( current = list.head; current != nullptr; current = current->next){
         os << current-> value <<' ';
     }
    
     return os;
}

 istream& operator>>(istream& is, List& list){
     int curr, prev;
     
     is >> prev;
     
     list.add(prev);
     
     List::Link* current = list.head;
     
     is >> curr;
     
     while (curr < prev){
         current->next = new List::Link(curr, nullptr);
         
         current = current-> next;
         
         prev = curr;
         
         is >> curr;
     }
     
     return is;
}



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
    


List& List::operator= (List&& list){
    if (this == &list){
        return *this;
    }
    
    clear();
    
    head = list.head;
    list.head = nullptr;
   
    return *this;
}

void List::insert(int data){
    
    if (isEmpty() || firstElement() < data){
        add(data);
        return;
    }
    
    Link* current = head;
    for (current = head; current->next != nullptr; current = current->next ){
        if (current->next->value < data){
            current ->next = new Link(data, current->next);
            
            return;
        }
    }
    
    current->next =  new Link(data, nullptr);
        
}



void List::remove(int data){
    if (isEmpty()){
        throw "value not found\n";
    }
    
    if (firstElement() == data){
        removeFirst();
    }
    
    Link* current;
    
    for (current = head; current->next != nullptr; current = current->next){
        if (current->next->value == data){
            current->next = (current->next)->next;
            delete current->next;
            return;
        }
    }
    throw "value not found\n";
}



