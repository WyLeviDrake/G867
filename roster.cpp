#include "roster.h"

void Roster::parse(string tableRow) {
    DegreeProgram degreeProgram;

    int end = tableRow.find(",");
    string studentId = tableRow.substr(0, end);

    int start = end + 1;
    end = tableRow.find(",", start);
    string firstName = tableRow.substr(start, end - start);

    start = end + 1;
    end = tableRow.find(",", start);
    string lastName = tableRow.substr(start, end - start);

    start = end + 1;
    end = tableRow.find(",", start);
    string email = tableRow.substr(start, end - start);

    start = end + 1;
    end = tableRow.find(",", start);
    string email = tableRow.substr(start, end - start);

    start = end + 1;
    end = tableRow.find(",", start);
    int age = stod(tableRow.substr(start, end - start));

    start = end + 1;
    end = tableRow.find(",", start);
    int courseLength1 = stod(tableRow.substr(start, end - start));

    start = end + 1;
    end = tableRow.find(",", start);
    int courseLength2 = stod(tableRow.substr(start, end - start));

    start = end + 1;
    end = tableRow.find(",", start);
    int courseLength3 = stod(tableRow.substr(start, end - start));

    start = end + 1;
    int length = tableRow.length();
    string degreeProgramString = tableRow.substr(start, length - start);
    if (degreeProgramString == "SOFTWARE") {
        DegreeProgram degreeProgram = SOFTWARE;
    }
    if (degreeProgramString == "NETWORK") {
        DegreeProgram degreeProgram = NETWORK;
    }
    if (degreeProgramString == "SECURITY") {
        DegreeProgram degreeProgram = SECURITY;
    }

    add(studentId, firstName, lastName, email, age, courseLength1, courseLength2, courseLength3, degreeProgram);
}

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int courseLength1, int courseLength2, int courseLength3, DegreeProgram degreeProgram) {
    int courseLengthArray[3] = {courseLength1, courseLength2, courseLength3};
    classRosterArray[++index] = new Student(studentId, firstName, lastName, email, age, courseLengthArray, degreeProgram);
}

void Roster::remove(string studentId) {
    bool inArray = false;
    for (int i = 0; i <= Roster::index; i++) {
        if (studentId == classRosterArray[i]->getStudentId()) {
            inArray = true;
            if (i < 4) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[4];
                classRosterArray[4] = temp;
            }
            Roster::index--;
        }
    } 
    if (!inArray) {
        cout << "Student ID not found." << std::endl;
    } 
}

void Roster::printAll() {
    Student::printColumnNames();
    for (int i = 0; i <= Roster::index; i++) {
        classRosterArray[i]->print();
        cout << std::endl;
    }
}

void Roster::printAverageDaysInCourse(string studentId) {
    for (int i = 0; i <= Roster::index; i++) {
        if (Roster::classRosterArray[i]->getStudentId() == studentId) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += classRosterArray[i]->getCourseLength()[j];
            }
            double average = (sum / 3);            
        }
    }
}

void Roster::printInvalidEmails() {
    bool incorrectEmails = false;
    for (int i = 0; i <= Roster::index; i++) {
        string email = classRosterArray[i]->getEmail();
        if (email.find(" ") | !email.find("@") && !email.find(".") ) {
            incorrectEmails = true;
            cout << classRosterArray[i]->getEmail() << std::endl;
        }
    }
    if (!incorrectEmails) {
        cout << "No invalid emails on roster." << std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printColumnNames();
    for (int i = 0; i <= Roster::index; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            cout << std::endl;
        }        
    }
}

Roster::~Roster() {
    for (int i = 0; i < 4; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    
}