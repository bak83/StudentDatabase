#pragma once

#include "Student.hpp"
#include <vector>

class DataBase
{
    std::vector<Student> studentBase;

 public:
    void addNewStudent(Student);
    void sortStudentsByIndex();
    void removeStudentByIndex(uint64_t);
    void displayStudentList();

};
