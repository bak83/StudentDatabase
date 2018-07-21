#pragma once
#include "Record.hpp"
#include <stdint.h>

class Student: public Record
{
    uint64_t index;

public:
    Student(std::string, std::string, uint64_t);
    Student(): Record() {}
    ~Student() {}

    uint64_t getIndex() const;
    void showAll() override;

};
