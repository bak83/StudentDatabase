#include "Record.hpp"
#include "Student.hpp"
#include "Employee.hpp"

class Generator
{
    Record* record;

public:
    void generateName(int);
    void generateSurname(int);
    void generateGender(int);
    void generateAddress();
    void generatePESEL(int);
    int generateIndex();
    int generateSalary();

    Record* generateRecord();
};
