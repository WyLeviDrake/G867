#pragma once
#include "student.h"

class Roster {
    private:
        int index = -1;
        Student* classRosterArray[5];
    
    public:
        void parse(string tableRow);
        void add(string studentId, string firstName, string lastName, string email, int age, int courseLength1, int courseLength2, int courseLength3, DegreeProgram degreeProgram);
        void remove(string studentId);

        void printAll();
        void printAverageDaysInCourse(string studentId);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        ~Roster();
};