#include "Student.hpp"

Student::Student(std::string n, std::string s, int i):
    Record(n, s), index(i) {}

int Student::getIndex() const { return index; }

void Student::showAll()
{
    std::cout << getName() << "  "
              << getSurname() << "  "
              << getIndex() << std::endl;

}
