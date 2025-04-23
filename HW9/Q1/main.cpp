//
//  main.cpp
//  BST
//
//  Created by Avi Soclof on 6/01/22.
//This code creates several functons for a bst tree such as reflect, breadthscan, and height
//This code also creates a child of  tree which is a bst searchtree which can remove nodes, find a nodes successor, and delete duplciates 

#include <iostream>
using namespace std;
#include "SearchTree.hpp"
#include "QueueVector.hpp"
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
    SearchTree<int> T1;
    cout << "enter 10 numbers:\n";
    int x, y, z;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        T1.add(x);
    }
    cout << "inorder: ";
    T1.inOrder();
    cout << "\nenter 0-8:\n";
    cin >> x;
    while (x != END)
    {
        switch (x)
        {
        case ADD: cout << "enter a number: ";
            cin >> y;
            T1.add(y);
            cout << "after adding " << y << ": ";
            T1.inOrder();
            cout << endl;
            break;
        case SEARCH: cout << "enter a number: ";
            cin >> y;
            if (T1.search(y))
                cout << "exist" << endl;
            else
                cout << "does not exist" << endl;
            break;
        case REMOVE:cout << "enter a number: ";
            cin >> y;
            try
            {
                T1.remove(y);
                cout << "after removing " << y << ": ";
                T1.inOrder();
                cout << endl;
            }
            catch (const char* str)
            {
                cout << str << endl;
            }
            break;
        case BREADTHSCAN: cout << "breadth first scan: ";
            T1.breadthScan();
            cout << endl;
            break;
        case HEIGHT:cout << "height of tree: " << T1.height() << endl;
            break;
        case SUCCESSOR:cout << "enter a number: ";
            cin >> y;
            try
            {
                z = T1.Successor(y);
                cout << "successor of " << y << " is: " << z << endl;
}
            catch (const char* str)
            {
                cout << str << endl;
            }
            break;
        case DELETEDUP: cout << "after deleting duplicates: ";
            T1.deleteDuplicates();
            T1.inOrder();
            cout << endl;
            break;
        case REFLECT:T1.reflect();
            cout << "reflected tree: ";
            T1.inOrder();
            T1.reflect();
            cout << endl;
            break;
        }
        cout << "enter 0-8:\n";
        cin >> x;
    }
    return 0;
}

/*
enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
inorder: 1 2 3 4 5 6 7 8 9 10 
enter 0-8:
1
enter a number: 3
after adding 3: 1 2 3 3 4 5 6 7 8 9 10 
enter 0-8:
2
enter a number: 4
exist
enter 0-8:
3
enter a number: 5
after removing 5: 1 2 3 3 4 6 7 8 9 10 
enter 0-8:
4
breadth first scan: 1 2 3 3 4 6 7 8 9 10 
enter 0-8:
5
height of tree: 8
enter 0-8:
6
enter a number: 8
successor of 8 is: 9
enter 0-8:
7
after deleting duplicates: 1 2 3 4 6 7 8 9 10 
enter 0-8:
0
Program ended with exit code: 0
*/
