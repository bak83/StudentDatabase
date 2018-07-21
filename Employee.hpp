#pragma once
#include "Record.hpp"

class Employee: public Record
{
    double salary;

public:
    Employee(std::string, std::string, double);
    Employee(): Record() {}
    ~Employee() {}

    double getSalary() const;

};
