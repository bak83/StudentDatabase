#include "Employee.hpp"

Employee::Employee(std::string n, std::string s, int sal):
    Record(n, s), salary(sal) {}

int Employee::getSalary() const { return salary; }

int Employee::getInfo()
{
    std::cout << getName() << "  "
              << getSurname() << "  "
              << getSalary() << " PLN" << std::endl;

    return 2;   // metoda pracownika
}
