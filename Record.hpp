#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

class Record
{
    std::string name;
    std::string surname;

public:
    Record(std::string n, std::string s): name(n), surname(s) {};
    ~Record() {}

};
