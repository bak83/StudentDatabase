#include "Employee.hpp"

Employee::Employee(std::string n, std::string s, double sal):
    Record(n, s), salary(sal) {}

double Employee::getSalary() const { return salary; }
