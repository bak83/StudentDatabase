#include "Record.hpp"

Record::Record(std::string n, std::string s, gender_t g, uint64_t p,
               address_t a): name(n), surname(s), gender(g), PESEL(p), address(a) {}

std::string Record::getName() const { return name; }

std::string Record::getSurname() const { return surname; }

uint64_t Record::getPESEL() const { return PESEL; }

address_t getAddress() const { return address; }
