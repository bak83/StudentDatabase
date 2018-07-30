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
  void sortBySurname();
  void sortByPESEL();
  void removeStudentByIndex(int);
  void removeRecordByPESEL(uint64_t);
  void validatePESEL(uint64_t);
  void generate(int);
  Record *getRecord(size_t) const;
  Record *searchRecordBySurname(std::string)const;
Record *searchRecordByPESEL(uint64_t)const;
};
