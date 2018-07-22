#pragma once

#include "Record.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>

class DataBase
{
    std::vector<Record*> dataBase;

 public:
    void addNewRecord(Record*);
    void displayRecordList();
    void saveToFile();
    void sortStudentsByIndex();
    void removeStudentByIndex(int);

};
