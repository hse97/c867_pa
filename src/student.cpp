#include<iostream>
#include "student.h"
using namespace std;

//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

//getters
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
int Student::getAge() { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

//setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }

void Student::setDaysInCourse(int daysInCourse[3]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//prints
void Student::print() {
    cout << getStudentID() << endl;
    cout << getFirstName() << endl;
    cout << getLastName() << endl;
    cout << getEmailAddress() << endl;
    cout << getAge() << endl;
    
    int* daysInCoursePrint = getDaysInCourse(); 
    cout << "Days in Course: " << daysInCoursePrint[0] << ", " << daysInCoursePrint[1] << ", "<< daysInCoursePrint[2] << endl;
    int averageDaysInCourse = (daysInCoursePrint[0] + daysInCoursePrint[1] + daysInCoursePrint[2]) / 3;
    cout << "Average days in Course: " << averageDaysInCourse << endl; 

    if (getDegreeProgram() == DegreeProgram::NETWORK){
        cout << "NETWORK" << endl;
    } else if (getDegreeProgram() == DegreeProgram::SECURITY){
        cout << "SECURITY" << endl;
    } else if (getDegreeProgram() == DegreeProgram::SOFTWARE){
        cout << "SOFTWARE" << endl;
    } else {
        cout << "UKNOWN: Uh oh" << endl; 
    }
}
