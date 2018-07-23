#include "Student.hpp"

Student::Student(std::string n, std::string s, int i, float g):
    Record(n, s), index(i), gpa(g) {}

int Student::getIndex() const { return index; }

float Student::getGpa() const { return gpa; }

void Student::showAll()
{
    std::cout << getName() << "  "
              << getSurname() << "  "
              << getIndex() << "  "
              << getGpa() << std::endl;

}

int Student::getId() { return 1; }
