#include<iostream>
#include "degree.h"
#include "student.h"
using namespace std;

#ifndef ROSTER_H
#define ROSTER_H

class Roster {
    public:
        //array of pointers 
        Student* classRosterArray[5];
        int rosterSize;
        
        //constructor
        Roster();

        //add, remove, print, average, invalid emails, degree program
        void parseAndAdd(string row);
        void addToRoster(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void removeFromRoster(string studentID);
        void printAll();
        void printAverage(string studentID);
        void printInvalidEmails();
        void printDegreeProgram(DegreeProgram degreeProgram);

        //deconstructor 
        ~Roster();
};

#endif 