#pragma once

#include "Record.hpp"

class Employee : public Record {
  int salary;

public:
  Employee(std::string, std::string, gender_t, uint64_t, address_t, int);

  int getSalary() const;

  void showAll() override;

  ///////////////////////////////
  virtual int getIndex() const { return NO_MATCH; }
};
