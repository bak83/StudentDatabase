#include "Student.hpp"

#include <iomanip>

Student::Student(std::string n, std::string s, gender_t ge, uint64_t p,
                 address_t a, int i)
    : Record(n, s, ge, p, a), index(i) {}

int Student::getIndex() const { return index; }

void Student::showAll()
{
  std::cout << std::right << std::setw(13) << getName();
  std::cout << std::right << std::setw(15) << getSurname();
  std::cout << std::right << std::setw(16) << getPESEL();
  if (getGender() == 0)
      std::cout << std::right << std::setw(6) << "K";
  else if (getGender() == 1)
      std::cout << std::right << std::setw(6) << "M";
  std::cout << std::right << std::setw(30) << getAddress().toString();
  std::cout << std::right << std::setw(12) << getIndex();
  std::cout << std::endl;
}
