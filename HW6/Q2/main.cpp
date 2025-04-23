//
//  main.cpp
//  Homework 6 Question 2
//
//  Created by Avi Soclof on 4/3/22.
// create a child class to list that is a continuos list with the least element of the list being the head.
//continuos list should be able to accomplish all the functions that list can do. such as adding a value to the beginnig and end as well as searching and deleting

#include "RoundList.hpp"
#include <iostream>
using namespace std;

enum CHOICES {
    EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY, PRINT
};

int main() {
    RoundList roundList;
    int choice;
    cout << "Enter your choice: \n";
    cin >> choice;
    while (choice != EXIT) {
        int num;
        switch (choice) {
        case ADD:
            cout << "Enter a number: \n";
            cin >> num;
            roundList.add(num);
            break;
        case ADD_TO_END:
            cout << "Enter a number: \n";
            cin >> num;
            roundList.addToEnd(num);
            break;
        case REMOVE_FIRST:
            roundList.removeFirst();
            break;
        case SEARCH:
            cout << "Enter a number: " <<endl;
            
            cin >> num;
            cout << roundList.search(num) << endl;
            break;
        case CLEAR:
            roundList.clear();
            break;
        case EMPTY:
            if (roundList.isEmpty())
                cout << "Empty" << endl;
            else
                cout << "Not empty" << endl;
            break;
        case PRINT:
            cout << roundList << endl;
            break;
        default: cout << "ERROR!" << endl;
        }
        cout << "Enter your choice: \n";
        cin >> choice;
    }
    return 0;
}

/*
Enter your choice:
1                                                            
Enter a number:
 10 
Enter your choice:
 1                                                            
Enter a number:
 11       
Enter your choice:
7
11 10
Enter your choice:
2                                                            
Enter a number:
 20   
Enter your choice:
2                                                            
Enter a number:
 21                                                                                                         
Enter your choice:
7
20 21 11 10
Enter your choice:
6
Not empty                                                                       
Enter your choice:
3
Enter your choice:
7
21 11 10




*/


