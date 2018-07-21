#pragma once
#include "Record.hpp"

class Employee: public Record
{
    int salary;

public:
    Employee(std::string, std::string, int);
    Employee(): Record() {}
    ~Employee() {}

    double getSalary() const;

};
