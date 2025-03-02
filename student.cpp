#include "student.h"

Student::Student(){
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < 3; i++) {
        this->courseLength[i] = 0;
    }
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int courseLength[], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->courseLength[i] = courseLength[i];
    }
    this->degreeProgram = degreeProgram;
}

Student::~Student() {

}

string Student::getStudentId() {
    return this->studentId;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmail() {
    return this->email;
}
int Student::getAge() {
    return this->age;
}
int* Student::getCourseLength() {
    return this->courseLength;
}
DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string email) {
    this->email = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setCourseLength(int courseLength[]) {
    for (int i = 0; i < 3; i++) {
        this->courseLength[i] = courseLength[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

static void printColumnNames() {
    cout << "Student ID|First Name|Last Name|Email|Age|Course Length|Degree Program\n";
}
void Student::print() {
    cout << this->getStudentId() << "\t"; 
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t";
    cout << this->getEmail() << "\t";
    cout << this->getAge() << "\t";
    cout << this->getCourseLength()[0] << ",";
    cout << this->getCourseLength()[1] << ",";
    cout << this->getCourseLength()[2] << "\t";
    cout << degreeProgramStrings[this->getDegreeProgram()] << "\n";
}
