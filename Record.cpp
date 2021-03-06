#include "Record.hpp"

Record::Record(std::string n, std::string s, gender_t g, uint64_t p,
               address_t a): name(n), surname(s), gender(g), PESEL(p), address(a) {}

std::string Record::getName() const { return name; }

std::string Record::getSurname() const { return surname; }

uint64_t Record::getPESEL() const { return PESEL; }

address_t Record::getAddress() const { return address; }

gender_t Record::getGender() const { return gender; }

void Record::setName(std::string n) { name = n; }
void Record::setSurname(std::string s) { surname = s; }
void Record::setAddressCity(std::string cit) { address.city = cit; }
void Record::setAddressStreet(std::string str) { address.street = str; }
void Record::setAddressNumber(int num) { address.number = num; }
