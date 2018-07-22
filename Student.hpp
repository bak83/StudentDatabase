#pragma once
#include "Record.hpp"

class Student: public Record
{
    int index;

public:
    Student(std::string, std::string, int);

    int getIndex() const;
    void showAll() override;

};
