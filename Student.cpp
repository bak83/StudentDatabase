#include "Student.hpp"

Student::Student(std::string n, std::string s, uint64_t i):
    Record(n, s), index(i) {}

uint64_t Student::getIndex() const { return index; }
