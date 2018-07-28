#include "Employee.hpp"

#include <iomanip>

Employee::Employee(std::string n, std::string s, gender_t g, uint64_t p,
                   address_t a, int sal)
    : Record(n, s, g, p, a), salary(sal) {}

int Employee::getSalary() const { return salary; }

void Employee::showAll() {
  std::cout << std::right << std::setw(13) << getName();
  std::cout << std::right << std::setw(13) << getSurname();
  std::cout << std::right << std::setw(9) << getSalary();
  std::cout << std::endl;
}

int Employee::getId() { return 2; }
