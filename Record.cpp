#include "Record.hpp"

Record::Record(std::string n, std::string s): name(n), surname(s) {}

std::string Record::getName() const { return name; }

std::string Record::getSurname() const { return surname; }
