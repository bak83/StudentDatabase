#include "Record.hpp"

class Generator
{
    Record* record;

public:
    void generateName(int);
    void generateSurname(int);
    void setGender(int);

    Record* generateRecord();
};
