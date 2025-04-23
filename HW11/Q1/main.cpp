//
//  main.cpp
//  Homework 11
//
//  Created by Avi Soclof on 6/8/22.
// code allows user to input to  and output from a binary file. 
//  the binary file is initially set to have 100 instances of a famliy class
//  based on id we can find a family and update their fields
//  one field is the activites of family which using bitwise operators we can update the activites a family is enrolled
// a queue is used to manage the amount of spots for each activity and create a wiating list
#include <iostream>
#include "Family.hpp"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>
#include "Exceptions.hpp"


using namespace std;

enum { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };

enum ACTIVITY {
   NONE,
   SWIMMING,
   GYMNATSTICS,
   DANCE = 4,
   ART = 8,
   SELF_DEFENSE = 16,
   MUSIC = 32,
   DRAMA = 64,
   BASKETBALL = 128
};

//returns the valid input
char yesOrNo(){
    char input;
    cin >> input;
    while (input != 'Y' && input!='y' && input!= 'n' && input != 'N'){
        cout << "ERROR: Invalid response" << endl;
        cin >> input;
    }
    
    return input;
}

void setFile(fstream& file);
void add(fstream& file);
void del(fstream& file, int id);
int count(fstream& file, int activity);
void update(fstream& file, int id, queue<Family>& waiting_list);
void waiting(queue<Family> wait_list);
void print(fstream& file, int id);


void handleCount(fstream& file) {
    int snum;
    cout << "enter activity number to count:\n";
    cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
    cin >> snum;
    cout << "there are ";
    switch (snum) {
    case 1:
        cout << count(file, SWIMMING);
        break;
    case 2:
            cout << count(file, GYMNATSTICS);
        break;
    case 3:
        cout << count(file, DANCE);
        break;
    case 4:
        cout << count(file, ART);
        break;
    case 5:
        cout << count(file, SELF_DEFENSE);
        break;
    case 6:
        cout << count(file, MUSIC);
        break;
    case 7:
        cout << count(file, DRAMA);
        break;
    case 8:
        cout << count(file, BASKETBALL);
        break;
    }
    cout << " families registered\n";
}


int main()
{
    queue<Family> q;

    queue<Family> jv;
    fstream file;
    file.open("families.txt", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "ERROR: couldn't open file\n";
        return 0;
    }
    setFile(file);
    file.clear();
        
    int choice;
    int snum;
    int cnum;
    cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
    cout << "enter 0-6:\n";
    cin >> choice;
    while (choice)
    {
        try {
            switch (choice)
            {
            case ADD://add to the file
                add(file);
                break;
            case DEL://delete from file
                cout << "enter number of family to delete:\n";
                cin >> snum;
                del(file, snum);
                break;
            case COUNT:
                handleCount(file);
                break;
            case UPDATE://update the list of classes of a family
                cout << "enter number of family to update:\n";
                cin >> snum;
                update(file, snum, jv);
                break;
            case WAITING://update the list of classes of a waiting family
                waiting(jv);
                break;

            case PRINT://print the details of a specific family
                cout << "enter number of family to print:\n";
                cin >> snum;
                print(file, snum);
                break;
            default:
                cout << "ERROR: invalid choice\n";

            }
        }// try
        catch (exception& e) {
            cout << e.what();
        }
        cout << "\nenter 0-6:\n";
        cin >> choice;

    }
    file.close();
    return 0;
}

//sets file
void setFile(fstream& file){
    //create family with values set to 0 
    Family family;
    family.id = 0;
    family.familyMembers = 0;
    family.phoneNumber = 0;
    family.activities = NONE;
    
    //itterate and write 100 instances of family to the file
    for (int i = 0; i < 100; ++i){
        file.write((char*)&family,sizeof(family));
    }
    
    file.clear();
    return;
}

//add an instance of family to the family based on ID
void add(fstream& file){
    
    Family newFamily;
    
    Family family;
    
    //user input for values
    cout << "enter the family's:  id, name, amount of people and a phone number:" << endl;
    
    cin >> newFamily.id >> newFamily.lastName >> newFamily.familyMembers >> newFamily.phoneNumber;
    newFamily.activities = NONE;
    
    if (newFamily.id > 100 || newFamily.id < 1){
        throw efn;
    }

    //get a pointer to the position based on id
    file.seekg((newFamily.id -1) * sizeof(Family), file.beg);

    //reads the instance of family there and inputs into instance of a family 
    file.read((char*)&family, sizeof(Family));
    
    file.clear();
    
    //if the user input family is equal then family already exists - error is throw
    if (family.id == newFamily.id){
        throw edf;
    }
    
    //pointer for input
    file.seekp((newFamily.id -1) * sizeof(Family), file.beg);
    
    //write newfamily to file
    file.write((char*)&newFamily, sizeof(Family));
    
    file.clear();
}

//delete will set the id value to 0
void del(fstream& file, int id){
    //id
    int _id;
    
    //checking for valid id input
    if (id < 1 || id > 100){
        throw efn;
    }
    
    //setting pointer to read family based on id 
    file.seekg((id-1)*sizeof(Family),file.beg);
    file.read((char*)&_id, sizeof(int));
    
    //if _id is 0  family does not exist -  exception is thrown
    if (!_id){
        throw efnf;
    }
    
    //set _id to 0 which means its deleted
    _id = 0;
    
    //set pointer and updated id value to 0 in the file
    file.seekp((id-1)*sizeof(Family), file.beg);
    file.write((char*)&_id, sizeof(int));
    
    file.clear();

}

//counts the amount of families who are enrolled int activities in the family where their value is not equal to 0 
int count(fstream& file, int activity){
    Family family;
    int count = 0;
    
    //begginning of file
    file.seekg(file.beg);
    //read the entire family and input it into instance
    file.read((char*)&family, sizeof(Family));
    
    while (!file.eof()){
        //if id is not zero and activites are not 0 
        if (family.id && (family.activities & activity)){
            count++;
        }
        //itterates to next instance of family within the file
        file.read((char*)&family, sizeof(Family));
    }
    
    file.clear();
    //return count
    return count;
}

//allows for user to update the activities of a family 

void update(fstream& file, int id, queue<Family>& WL){
    
    Family family;
    Family waitingList;
    
    char input;

    //throw error if fmaily does not exist
    if (id > 100 || id < 1){
        throw efn;
    }
    
    //read file and copy to instance  
    file.seekg((id-1)* sizeof(Family),file.beg);
    file.read((char*)&family, sizeof(Family));
    
    //throw error if id is 0 
    if (!family.id){
        throw efnf;
    }
    
    //sets waitinglist instance
    waitingList = family;
    waitingList.activities = NONE;
    
    //itterate through all the activites and using or bitwise adds a bit to the activities of the instance 
    //if the activity has 10 participants, instance is placed on the waiting list
    
    //SWIMMING
    cout << "Do you want to register for swimming?" << endl;
    
    input = yesOrNo();
    
    if (input == 'Y' || input == 'y'){
        if (count(file,SWIMMING) < 10){
            family.activities = (family.activities | SWIMMING);
        }
        else {
            waitingList.activities = (waitingList.activities | SWIMMING);
        }
    }
    
    //GYMNASTICS
    cout << "Do you want to register for gymnastics?" << endl;
    input = yesOrNo();
    if (input == 'Y' || input == 'y'){
        if (count(file,GYMNATSTICS) < 10){
            family.activities = (family.activities | GYMNATSTICS);
        }
        else {
            waitingList.activities = (waitingList.activities | GYMNATSTICS);
        }
    }
    
    
    //DANCE
    input = yesOrNo();
    cout << "Do you want to register for dance?" << endl;
    if (input == 'Y' || input == 'y'){
        if (count(file,DANCE) < 10){
            family.activities = (family.activities | DANCE);
        }
        else {
            waitingList.activities = (waitingList.activities | DANCE);
        }
    }
    
    
    //ART
    input = yesOrNo();
    cout << "Do you want to register for art?" << endl;
    if (input == 'Y' || input == 'y'){
        if (count(file,ART) < 10){
            family.activities = (family.activities | ART);
        }
        else {
            waitingList.activities = (waitingList.activities | ART);
        }
    }
    //SELF DEFENSE
    cout << "Do you want to register for self defense?" << endl;
    input = yesOrNo();
    if (input == 'Y' || input == 'y'){
        if (count(file,SELF_DEFENSE) < 10){
            family.activities = (family.activities | SELF_DEFENSE);
        }
        else {
            waitingList.activities = (waitingList.activities | SELF_DEFENSE);
        }
    }
    
    //MUSIC
    cout << "Do you want to register for music?" << endl;
    input = yesOrNo();
    if (input == 'Y' || input == 'y'){
        if (count(file,MUSIC) < 10){
            family.activities = (family.activities | MUSIC);
        }
        else {
            waitingList.activities = (waitingList.activities | MUSIC);
        }
    }
    //DRAMA
    cout << "Do you want to register for drama?" << endl;
    input = yesOrNo();
    if (input == 'Y' || input == 'y'){
        if (count(file,DRAMA) < 10){
            family.activities = (family.activities | DRAMA);
        }
        else {
            waitingList.activities = (waitingList.activities | DRAMA);
        }
    }
    
    //BASKETBALL
    cout << "Do you want to register basketball?" << endl;
    input = yesOrNo();
    if (input == 'Y' || input == 'y'){
        if (count(file,BASKETBALL) < 10){
            family.activities = (family.activities | BASKETBALL);
        }
        else {
            waitingList.activities = (waitingList.activities | BASKETBALL);
        }
    }
    
//if waiting list activites is not equal to 0  push instance to queue

    if (waitingList.activities){
        WL.push(waitingList);
    }
    
    //write updated instance back to file
    file.seekp((family.id-1)*sizeof(Family), file.beg);
    file.write((char*)&family, sizeof(Family));
    
    file.clear();
}

//prints all the activites a family is waiting for in order of teh queue
void waiting(queue<Family> WL){
    //temp queue of instances of family 
    queue<Family> tempQueue;
    
    //itterates through waitlist and prints
    for (int i = 0; i < WL.size(); i++){
        cout << "family name: "  << WL.front().lastName << endl;
        cout << "number of persons: " << WL.front().familyMembers << endl;
        cout << "phone number: " << WL.front().phoneNumber << endl;
        
        if (WL.front().activities & SWIMMING)
        {
            cout << "SWIMMING\n";
        }

        if (WL.front().activities & GYMNATSTICS)
        {
            cout << "GYMNASTICS\n";
        }

        if (WL.front().activities & DANCE)
        {
            cout << "DANCE\n";
        }

        if (WL.front().activities & ART)
        {
            cout << "ART\n";
        }

        if (WL.front().activities & SELF_DEFENSE)
        {
            cout << "SELF DEFENSE\n";
        }

        if (WL.front().activities & MUSIC)
        {
            cout << "MUSIC\n";
        }

        if (WL.front().activities & DRAMA)
        {
            cout << "DRAMA\n";
        }

        if (WL.front().activities & BASKETBALL)
        {
            cout << "BASKETBALL\n";
        }
        //pushes front into temp
        tempQueue.push(WL.front());
        //pops the top value
        WL.pop();
    }
    
    //pushes all the instances from temp back into the waiting list
    for (int i = 0; i < tempQueue.size(); i++){
        WL.push(tempQueue.front());
        tempQueue.pop();
    }
    }
    
    //prints a family based on id 
void print(fstream& file, int id){
    Family family;
    
    //invalid id
    if (id < 1 || id > 100){
        throw efn;
    }
    
    //find and write instance to family 
    file.seekg((id -1)* sizeof(Family), file.beg);
    file.read ((char*)&family, sizeof(Family));
    
    //family not found
    if (!family.id){throw efnf;}
    
    //print info
    cout << "family name: " << family.lastName << endl;
    cout << "number of persons: " << family.familyMembers << endl;
    cout << "phone number: " << family.phoneNumber << endl;
    
    if (family.activities & SWIMMING)
    {
        cout << "SWIMMING" << endl;
    }

    if (family.activities & GYMNATSTICS)
    {
        cout << "GYMNASTICS" << endl;
    }

    if (family.activities & DANCE)
    {
        cout << "DANCE" << endl;
    }

    if (family.activities & ART)
    {
        cout << "ART" <<endl;
    }

    if (family.activities & SELF_DEFENSE){
    
        cout << "SELF DEFENSE" << endl;
    }

    if (family.activities & MUSIC)
    {
        cout << "MUSIC" << endl;
    }

    if (family.activities & DRAMA)
    {
        cout << "DRAMA" <<endl;
    }

    if (family.activities & BASKETBALL)
    {
        cout << "BASKETBALL" << endl;
    }
 
}

/* Choices are:
0 to exit
1 to add a family
2 to delete a family
3 to  count number of families signed up
4 to update the activities of a family
5 print the waiting list
6 to print a family

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
5 aaron 5 0505551235

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
123 brian 7 0505551123

ERROR: Invalid family number

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
5  aaron  5 0505551235

ERROR: Family is already in the file

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
6 carly 8 0505551236

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
7 daniella 9  0505551237

enter 0-6:
2

enter number of family to delete:
6

enter 0-6:
4
enter number of family to update:
6
ERROR: Family is not in the file

enter 0-6:
4

enter number of family to update:
5

Do you want to register for swimming?
Y
Do you want to register for gymnastics?
Y
Do you want to register for dance?
Y
Do you want to register for art?
Y
Do you want to register for self defense?
N
Do you want to register for music?
N
Do you want to register for drama?
N
Do you want to register basketball?
N

enter 0-6:
4
enter number of family to update:
7
Do you want to register for swimming?
Y 
Do you want to register for gymnastics?
N
Do you want to register for dance?
Y
Do you want to register for art?
N
Do you want to register for self defense?
Y
Do you want to register for music?
N
Do you want to register for drama?
Y
Do you want to register basketball?
N

enter 0-6:
3

enter activity number to count:
Choices are:
1 SWIMMING
2 GYMNASTICS
3 DANCE
4 ART
5 SELF DEFENSE
6 MUSIC
7 DRAMA
8 BASKETBALL
1

there are 2 families registered

enter 0-6:
6

enter number of family to print:
5

family name: aaron
number of persons: 5
phone number: 505551235
SWIMMING
GYMNASTICS
DANCE
ART

enter 0-6:
6

enter number of family to print:
6
ERROR: Family is not in the file

enter 0-6:
6

enter number of family to print:
7

family name: Daniella
number of persons: 9
phone number: 505551237
SWIMMING
DANCE
SELF DEFENSE
DRAMA




*/

    
    


