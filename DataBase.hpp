#pragma once

#include "Employee.hpp"
#include "Record.hpp"
#include "Student.hpp"

#include <vector>

class DataBase {
  std::vector<Record *> dataBase;

public:
    void addNewRecord(Record *);
    void displayRecordList();
    void saveToFile();
    void loadFile();
    void sortStudentsByIndex();
    void sortEmployeesBySalary();
    void sortBySurname();
    void sortByPESEL();
    void removeStudentByIndex(int);
    void removeRecordByPESEL(uint64_t);
    bool validatePESEL(uint64_t);
    void generate(int);
   // void modifySalaryAndAddressByPESEL(uint64_t, int,
   //                                    std::string, std::string, int);
    Record *getRecord(size_t) const;
    Record *searchRecordBySurname(std::string)const;
    Record *searchRecordByPESEL(uint64_t)const;
};
