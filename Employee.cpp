#include "Employee.hpp"

#include <iomanip>

Employee::Employee(std::string n, std::string s, gender_t g, uint64_t p,
                   address_t a, int sal)
    : Record(n, s, g, p, a), salary(sal) {}

int Employee::getSalary() const { return salary; }
//void Employee::setSalary(int sal) { salary = sal; }

void Employee::showAll()
{
  std::cout << std::right << std::setw(13) << getName();
  std::cout << std::right << std::setw(13) << getSurname();
  std::cout << std::right << std::setw(14) << getPESEL();
  if (getGender() == 0)
      std::cout << std::right << std::setw(4) << "K";
  else if (getGender() == 1)
      std::cout << std::right << std::setw(4) << "M";
  std::cout << std::right << std::setw(30) << getAddress().toString();
  std::cout << std::right << std::setw(9) << getSalary();
  std::cout << std::endl;
}
