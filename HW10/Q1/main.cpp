//
//  main.cpp
//  Homework 10
//
//  Created by Avi Soclof on 5/31/22.
// The purpose of this code is to maintain a record of different classes of soldiers within the army and use stl library functions and lambda functions to manipulate data and view certain attributes


#include <vector>
#include <algorithm>
#include "Soldier.hpp"
#include "PrivateSoldier.hpp"
#include "Commander.hpp"
#include "Officer.hpp"
using namespace std;

enum option {
	EXIT,	//	סיום התוכנית
	ADD_NEW_SOLDIER,	//	הוספת חייל חדש
	DESERVES_MEDAL,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	HIGHEST_SOCIOMETRIC,	//הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	PRIVATE_MEDAL_COUNT,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	NONCOMBAT_COMMANDER,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	REMOVE_OFFICER,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};
void add(vector<Soldier*>& army)
{
	//enum for options
	enum soldiertype { PRIVATE = 1, COMMANDER, OFFICER };

	int id, numOps, select;
	
	string firstName, lastName;
	
	Soldier* soldier;

	//prompt user to select what type of soldier
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";

	cin >> select;

	//input the values and declare a new soldier based on the type the user selected
	cout << "enter id, first name, last name and number of operations\n";
	cin >> id >> firstName >> lastName >> numOps;
	
	switch (select)
	{
	   //create a new instance of the selected soldier type
	case PRIVATE:
		soldier = new PrivateSoldier(id, firstName, lastName, numOps);
		break;
	case COMMANDER:
		soldier = new Commander(id, firstName, lastName, numOps);
		break;
	case OFFICER:
		soldier = new Officer(id, firstName, lastName, numOps);
		break;
	}
    //add the instance of soldier to the vector
	army.push_back(soldier);
	return;

}


//prints the soldier if he deserves a medal
void printMedalList(const vector<Soldier*>& army)
{
    //itterates through the vector and checks for medal
	for_each(army.begin(), army.end(), [](Soldier* s)->void
		{
			if (s->medal())
			{
				s->print();
			}
		}
	);
}


//returns the soldier with the highest sociometric score
Soldier* highestSociometricScore(const vector<Soldier*>& army)
{
	int high = 0;
	Soldier* highest= nullptr;

//itterates through the vector of soldiers and in the instance of an officer records the highest sociometric score 
	for_each(army.begin(), army.end(), [&](Soldier* s)->void //capture the variables within the function as references as we want to update them within the lambda function
		{
			if (s->soldierType() == "officer")
			{
				if (((Officer*)s)->getSocio() > high)
				{
					high = ((Officer*)s)->getSocio();
					highest = s;
				}
			}
		}
	);

	return highest;
}



int main()
{
	Soldier* s;
	vector<Soldier*>army; 
	
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(army);  //הוספת חייל חדש						
			break;
			
		case DESERVES_MEDAL:printMedalList(army);  //הדפסת פרטי הזכאים לצל"ש
			break;
			
		case HIGHEST_SOCIOMETRIC:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
			s = highestSociometricScore(army); // השלם\י פרמטר-וקטור או רשימה
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirst() << ' ' << s->getLast() << endl;
			break;
			
			//counts how many privates in the army have medals 
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			cout<<count_if(army.begin(), army.end(), [](Soldier* s)->bool
				{
					return s->soldierType() == "private" && s->medal();
				});
			cout << endl;
			break;
			
			//prints all the names of the commanders who are in nonCombat positons
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for_each(army.begin(), army.end(), [](Soldier* s)->void
				{
					if (s->soldierType() == "commander" && !((Commander*)s)->getCombat())
					{
						cout << s->getFirst() << ' ' << s->getLast() << ' ';
					}
				});
			cout << endl;
			break;
			
			//returns if there are any soldiers with more than 15 operations
		case SUPER_SOLDIER:

			if (any_of(army.begin(), army.end(), [](Soldier* s)->bool
				{
					return s->getNumOperations() > 15;
				}
			))

				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
			
			
			//removes all officers that do not have any operations from the vector 
		case REMOVE_OFFICER://מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			
			//any officer that has 0 operations is set to a nullptr
			for_each(army.begin(), army.end(), [](Soldier*& s)->void
				{
					if (s->soldierType() == "officer" && s->getNumOperations() <= 0)
					{
						delete s;
						s = nullptr;
					}
				});

            //deletes all instances of nullptr within the vector
			army.erase(remove(army.begin(), army.end(), nullptr), army.end());


            //print the vector post deletion
			for_each(army.begin(), army.end(), [](Soldier* s)
			{
				s->print();
			});
			break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}


/*
 Sample output
 enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
1
enter id, first name, last name and number of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
2
enter id, first name, last name and number of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
3
enter id, first name, last name and number of operations
333 ccc ccc 0
Enter the sociometric score
100
enter 0-7
3
Officer with the highest sociometric score: ccc ccc
enter 0-7
4
number of privates that received medals: 0
enter 0-7
5
list of noncombat commanders :
enter 0-7
6
no soldier did more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
commander
ID: 222
first name: bbb
last name: bbb
num operations: 0
combat: yes
enter 0-7
0
*/


