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
  void removeStudentByIndex(int);
  Record *getRecord(size_t) const;
};
