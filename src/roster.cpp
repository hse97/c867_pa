#include<iostream>
#include<string>
#include<sstream>
#include "roster.h"
#include "degree.h"
using namespace std;

//constructor 
Roster::Roster(){ 
    rosterSize = 0; 
    for (int i = 0; i < 5; i++){
        classRosterArray[i] = nullptr;
    }
}

void Roster::parseAndAdd(string row) {
    stringstream ss(row); //stream with the studentData[] element 
    string  studentID, firstName, lastName, emailAddress; 
    string ageToken, days1Token, days2Token, days3Token, degreeToken; //tokens to hold non-strings
    int age, daysInCourse1, daysInCourse2, daysInCourse3; //ints to hold converted token values 
    DegreeProgram degreeProgram; 

    getline(ss, studentID, ','); //first entry in row, comma as delimeter 
    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, emailAddress, ',');
    
    getline(ss, ageToken, ','); //parseing the string into a token
    age = stoi(ageToken); //converting tokens strings to actual integers 
    getline(ss, days1Token, ',');
    daysInCourse1 = stoi(days1Token);
    getline(ss, days2Token, ',');
    daysInCourse2 = stoi(days2Token);
    getline(ss, days3Token, ',');
    daysInCourse3 = stoi(days3Token);
    
    getline(ss, degreeToken, ','); //token to handle the string 
    if (degreeToken == "SOFTWARE"){ //use token to match actual degree type 
        degreeProgram = SOFTWARE; 
    } else if (degreeToken == "NETWORK"){
        degreeProgram = NETWORK;
    } else if (degreeToken == "SECURITY") {
        degreeProgram = SECURITY;
    } else {
        cout << "Unknown degree program" << endl;
    }

    //passing all parsed values to function to add to Roster 
    addToRoster(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram); 

}

void Roster::addToRoster(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) 
{
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; //condensing the 3 parsed course days into one array 
    classRosterArray[rosterSize] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    rosterSize++; //keeps track of how many students have been added to roster 
}

void Roster::removeFromRoster(string studentID)
{
    bool found = false;
    for (int i = 0; i < rosterSize; i++){
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID){
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            for (int j = i; j < rosterSize - 1; j++){
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[rosterSize - 1] = nullptr;
            rosterSize--;
            found = true; 
            cout << "Student with ID: " << studentID << " removed from roster." << endl;
            break;
        }
    }
    if (!found){
        cout << "ERROR: Student with ID: " << studentID << " not found." << endl;
    }
}


void Roster::printAll() {
    for (int i = 0; i < rosterSize; i++){
        classRosterArray[i]->print();
        cout << endl; 
    }
}

void Roster::printAverage(string studentID) {
    bool found = false;
    for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            int* dayValues = classRosterArray[i]->getDaysInCourse();
            int average = (dayValues[0] + dayValues[1] + dayValues[2]) / 3;
            cout << "Average days in course for student with ID: " << studentID << " is " << average << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID: " << studentID << " not found." << endl;
    }
}


void Roster::printInvalidEmails (){
    for (int i = 0 ; i < rosterSize; i++){
        string foundEmail = classRosterArray[i]->getEmailAddress();
        if (foundEmail.find('@') == string::npos || foundEmail.find('.') == string::npos || foundEmail.find(' ') != string::npos){
            cout << "Invalid Email: " << foundEmail << endl; 
        }
    }
}

void Roster::printDegreeProgram(DegreeProgram degreeProgram)  {
        for (int i = 0; i < rosterSize; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            cout << endl;
        }
    }
}

Roster::~Roster(){
    for (int i = 0; i < rosterSize; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}