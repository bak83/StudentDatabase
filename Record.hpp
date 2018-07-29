#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

#define NO_MATCH std::numeric_limits<int>::max()

struct address_t {
  std::string city;
  std::string street;
  int number;
  std::string toString()
  {
      std::string add = city + ", " + street + " " + std::to_string(number);
      return add;
  }
};

enum gender_t { female, male };

class Record {
  std::string name;
  std::string surname;
  uint64_t PESEL;
  address_t address;
  gender_t gender;

public:
  Record(std::string, std::string, gender_t, uint64_t, address_t);

  std::string getName() const;
  std::string getSurname() const;
  uint64_t getPESEL() const;
  address_t getAddress() const;
  gender_t getGender() const;

  virtual void showAll() = 0;

  ///////////////////////////////
  virtual int getIndex() const = 0;
  virtual int getSalary() const = 0;
};
