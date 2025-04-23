//
//  main.cpp
//  List
//
//Abraham Soclof 
//Homework 5 Question 2
//The program has three global functions that can merge sorted lists, create a merged list with no duplicates, and reverse the list

#include <iostream>
using namespace std;
#include "List.hpp"

//merge will return a sorted list with the values of both lists in the parameters
List merge (List& lst1 , List& lst2){
    //intializes two instances with the lists of the paramerters
    List merged(lst1);
    
    List toMerge(lst2);
    
    
    //while  the second list is not empty
    while (!toMerge.isEmpty()){
        
        //inserts value into sorted array in it appropriate spot 
            merged.insert(toMerge.firstElement());
        
        //removes the first value, which has already been input into the merged array 
        toMerge.removeFirst();
    }
    return merged;
}

//deletes duplicates so that there will only be one instance of a number in the list
void makeSet(List& list)
{
    
    int current;
    int previous;
    
    //helper list
    List helper(list);

    //clears the inital list set in the parameter
    list.clear();

    //set previous the value of the first element 
    previous = helper.firstElement();
    
    //and remove the first value 
    helper.removeFirst();

        //add the first value to the new list
       list.add(previous);
       
       
   //itterates until helper is empty 
    while(!helper.isEmpty())
    {
        //looks at first value and sets current to that value 
        current = helper.firstElement();
        
        
    //removes first value from the list
        helper.removeFirst();

    //if they are equal the current value is removed
        if (current == previous)
        {
            
            list.remove(current);
        }
    
    //if a duplicate is not found, the current value is inserted into the new list 
          list.insert(current);
       
       // sets previous to current 
        previous = current;
    }

    return;
}
    
    
    
    
    
    
//reverse revverses input list
void reverse (List& list){
    //helper list
    List helper (list);
    //clears the paramater list
    list.clear();
    
    //itterates through helper list and inputs the values into the empty list. whatever is popped from the top of the list, is ultimately pushed into the bottom of the new list, ultimately reversing the list. 
    while (!helper.isEmpty()){
      
            list.add(helper.firstElement());
       
        helper.removeFirst();
    }
}

int main()
{
    List lst1, lst2, mergedList;
    
    cout<<"enter sorted values for the first list:"<< endl;
    cin>>lst1;
    cout<<"enter sorted values for the second list:"<< endl;
    cin>>lst2;

    mergedList = merge(lst1,lst2);
    cout <<"the new merged list: " << mergedList <<endl;

    makeSet(mergedList);
    cout<<"the new merged set: " << mergedList << endl;

reverse(mergedList);
cout<<"the new merged reverse: " << mergedList << endl;

    
    return 0;
}
