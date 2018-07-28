#pragma once

#include <iostream>
#include <string>
#include <limits>

#define NO_MATCH std::numeric_limits<int>::max()

class Record
{
    std::string name;
    std::string surname;

public:
    Record(std::string, std::string);

    std::string getName() const;
    std::string getSurname() const;

    virtual void showAll() = 0;
    virtual int getId() = 0;

    ///////////////////////////////
    virtual int getIndex() const = 0;
    virtual int getSalary() const = 0;
};
