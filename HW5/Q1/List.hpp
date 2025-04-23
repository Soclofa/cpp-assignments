//
//  List.hpp
//  List
//
//  Created by Avi Soclof on 3/30/22.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
using namespace std; 


//------------------------------------------------
// class List
// arbitrary size Lists
// permits insertion and removal
// only from the front of the List
//------------------------------------------------
class List
{
protected:
    //--------------------------------------------
    // inner class link
    // a single element for the linked List
    //--------------------------------------------
    class Link
    {
    public:
        // constructor
        Link( int linkValue, Link * nextPtr);
        Link (const Link &);
        // data areas
        int value;
        Link * next;
    }; //end of class Link
public:
    // constructors
    List();
    List(const List&);
    ~List();
    // operations
    void add( int value);
    int firstElement() const;
    bool search(const int &value) const;
    bool isEmpty() const;
    void removeFirst();
    void clear();
    
    //Homework 5 Question 1 additions
    List(List&&);
    friend ostream& operator<<(ostream&, List&);
    friend istream& operator>>(istream&, List&);
    List& operator=(const List&);
    List& operator=(List&&);
    void insert(int key);
    void remove(int key);
    
protected:
    // data field
    Link* head;
    
};
#endif /* List_hpp */
