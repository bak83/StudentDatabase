#pragma once

#include "Record.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>

class DataBase
{
   // std::vector<Student> studentBase;
    std::vector<Record*> dataBase;

 public:
    void addNewRecord(Record*);
    void displayRecordList();
   /* void addNewStudent(Student);
    void sortStudentsByIndex();
    void removeStudentByIndex(uint64_t);
    void displayStudentList();*/

};
