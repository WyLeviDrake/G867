#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;

class Student {
    private:
        string studentId;
        string firstName;
        string lastName;
        string email;
        int age;
        int courseLength[3];
        DegreeProgram degreeProgram;

    public:
        Student();
        Student(string studentId, string firstName, string lastName, string email, int age, int courseLength[], DegreeProgram degreeProgram);
        ~Student();

        string getStudentId();
        string getFirstName();
        string getLastName();
        string getEmail();
        int getAge();
        int* getCourseLength();
        DegreeProgram getDegreeProgram();

        void setStudentId(string studentId);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmail(string email);
        void setAge(int age);
        void setCourseLength(int courseLength[]);
        void setDegreeProgram(DegreeProgram degreeProgram);

        static void printColumnNames();
        void print();
};