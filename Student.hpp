#pragma once
#include "Record.hpp"

class Student: public Record
{
    int index;
    float gpa;

public:
    Student(std::string, std::string, int, float);

    int getIndex() const;
    float getGpa() const;
    void showAll() override;
    int getId() override;

};
