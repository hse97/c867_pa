#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

int main(){
    cout << "Course: C867 Scripting and Programming Applications" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 011370288" << endl;
    cout << "Name: Jaime Lubrani" << endl;
    cout << "----------------------------------------------------\n----------------------------------------------------" << endl;

    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Jaime,Lubrani,blubran@wgu.edu,26,10,20,30,SOFTWARE"};

    Roster classRoster;
    for (int i = 0; i < 5; i++){
        classRoster.parseAndAdd(studentData[i]);
    }

    cout << "All Students in Student Data: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "All invalid emails in Student Data: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Average days in course for students in Student Data: " << endl;
    for (int i = 0; i < classRoster.rosterSize; i++){
        if (classRoster.classRosterArray[i] != nullptr){
            classRoster.printAverage(classRoster.classRosterArray[i]->getStudentID());
        }
    }
    cout << endl;

    cout << "Students in Student Data in SOFTWARE" << endl;
    classRoster.printDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student A3 from Student Data" << endl;
    classRoster.removeFromRoster("A3");
    cout << endl;

    cout << "Printing all students from Student Data" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Testing to see if Student A3 was removed from Student Data" << endl;
    classRoster.removeFromRoster("A3");

    return 0;
}
