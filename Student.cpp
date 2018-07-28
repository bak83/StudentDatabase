#include "Student.hpp"

#include <iomanip>

Student::Student(std::string n, std::string s, int i):
    Record(n, s), index(i) {}

int Student::getIndex() const { return index; }

void Student::showAll()
{
    std::cout << std::right << std::setw(13) << getName();
    std::cout << std::right << std::setw(13) << getSurname();
    std::cout << std::right << std::setw(9) << getIndex();
    std::cout << std::endl;
}

int Student::getId() { return 1; }
