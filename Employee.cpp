#include "Employee.hpp"

Employee::Employee(std::string n, std::string s, int sal):
    Record(n, s), salary(sal) {}

double Employee::getSalary() const { return salary; }
