#pragma once

#include "Record.hpp"

class Student : public Record {
  int index;

public:
  Student(std::string, std::string, gender_t, uint64_t, address_t, int);

  int getIndex() const;

  void showAll() override;
  int getId() override;

  ///////////////////////////////
  virtual int getSalary() const { return NO_MATCH; }
};
