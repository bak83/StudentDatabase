#include "Student.hpp"

Student::Student(std::string n, std::string s, int i):
    Record(n, s), index(i) {}

int Student::getIndex() const { return index; }

int Student::getInfo()
{
    std::cout << getName() << "  "
              << getSurname() << "  "
              << getIndex() << std::endl;

    return 1; // metoda Studenta
}
