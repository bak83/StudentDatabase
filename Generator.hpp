#include "Record.hpp"

struct Generator
{
    std::string generateName(int);
    std::string generateSurname(int);
    gender_t generateGender(int);
    std::string generateCity();
    std::string generateStreet();
    int generateHouseNumber();
    uint64_t generatePESEL(int, int);
    int generateIndex();
    int generateSalary();
    int generateRandomNumber(int, int);

    Record* generateRecord();
};
