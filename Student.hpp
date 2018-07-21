#ifndef STUDENTS_STUDENT_H_
#define STUDENTS_STUDENT_H_
#include <iostream>
#include <string>
#include <stdint.h>

class Student
{
    std::string name;
    std::string surname;
    uint64_t index;

public:
    Student(std::string, std::string, uint64_t);
    Student();
    ~Student();

    void setName(std::string);
    void setSurname(std::string);
    void setIndex(uint64_t);

    std::string getName() const;
    std::string getSurname() const;
    uint64_t getIndex() const;

};

#endif
