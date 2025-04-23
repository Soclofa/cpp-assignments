//
// Abraham Soclof 674098915
    
// Homework 5 Question 1
// this program adds some functions to the Single Linked List including overloading of the << and >> operators, removing values from the list and inserting and sorting values 
//

#include <iostream>
using namespace std;
#include "List.hpp"
enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };
int main()
{
    List lst;
    List lst2;
    int choice, val;
    cout << "enter the list values\n";
    cin >> lst;
    cout << "choose 0-4\n";
    cin >> choice;
    while (choice != EXIT)
    {
        switch (choice)
        {
        case INSERT:
            cout << "enter a value to insert\n";
            cin >> val;
            lst.insert(val);
            break;
        case REMOVE:
            cout << "enter a value to remove\n";
            cin >> val;
            try {
                lst.remove(val);
            }
            catch (const char* msg)
            {
                cout << msg << endl;
            }
            break;
        case ASSIGN:
            lst2 = lst;
            cout << "list 2: " << lst2;
            cout << endl; 
            cout <<"list 1: ";
        case PRINT:
            cout << lst << endl;
            break;
        default:cout << "ERROR\n";
        }
        cout << "choose 0-4\n";
        cin >> choice;
    }
    return 0;
}


/*enter the list values
25 20 20 15 8 6 10
choose 0-4
4
25 20 20 15 8 6
choose 0-4
1
enter a value to insert
15
choose 0-4
1
enter a value to insert
7
choose 0-4
4
25 20 20 15 15 8 7 6
choose 0-4
2
enter a value to remove
15
choose 0-4
2
enter a value to remove
8
choose 0-4
3
list2: 25 20 20 15 7 6
list1: 25 20 20 15 7 6
choose 0-4
0
*/