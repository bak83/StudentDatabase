#include "Record.hpp"
#include "Student.hpp"
#include "Employee.hpp"

class Generator
{
    Record* record;

public:
    std::string generateName(int);
    std::string generateSurname(int);
    gender_t generateGender(int);
    std::string generateCity();
    std::string generateStreet();
    int generateHouseNumber();
    void generateAddress();


    uint64_t generatePESEL(int);
    int generateIndex();
    int generateSalary();

    Record* generateRecord();
};
