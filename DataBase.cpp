#include "DataBase.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <sstream>

void DataBase::addNewRecord(Record *r) { dataBase.push_back(r); }

void DataBase::displayRecordList() {
  std::cout << "BAZA DANYCH:" << std::endl;
  for (int i = 0; i < dataBase.size(); ++i) {
    std::cout << i + 1 << ". ";
    dataBase.at(i)->showAll();
  }
}

void DataBase::sortStudentsByIndex() {
  std::sort(dataBase.begin(), dataBase.end(),
            [](const Record *p1, const Record *p2) {
              return p1->getIndex() < p2->getIndex();
            });
}

void DataBase::sortBySurname() {
  std::sort(dataBase.begin(), dataBase.end(), [](Record *p1, Record *p2) {
    return p1->getSurname() < p2->getSurname();
  });
}

void DataBase::sortByPESEL() {
  std::sort(dataBase.begin(), dataBase.end(), [](Record *p1, Record *p2) {
    return p1->getPESEL() < p2->getPESEL();
  });
}

void DataBase::removeStudentByIndex(int idx) {
  for (int i = 0; i < dataBase.size(); ++i) {
    if (dataBase[i]->getIndex() < NO_MATCH && dataBase[i]->getIndex() == idx) {
      dataBase.erase(dataBase.begin() + i);
      break;
    }
  }
}

void DataBase::removeStudentByPESEL(uint64_t idx) {
  for (int i = 0; i < dataBase.size(); ++i) {
    if (dataBase[i]->getPESEL() < NO_MATCH && dataBase[i]->getPESEL() == idx) {
      dataBase.erase(dataBase.begin() + i);
      break;
    }
  }
}

void DataBase::saveToFile() {
  std::fstream file;
  file.open("Base.txt", std::ios::out);

  for (int i = 0; i < dataBase.size(); ++i) {
    if (dataBase[i]->getIndex() < NO_MATCH) {
      file << "S"
           << "," << dataBase[i]->getName() << "," << dataBase[i]->getSurname()
           << "," << dataBase[i]->getIndex() << std::endl;
    } else if (dataBase[i]->getSalary() < NO_MATCH) {
      file << "E"
           << "," << dataBase[i]->getName() << "," << dataBase[i]->getSurname()
           << "," << dataBase[i]->getSalary() << std::endl;
    } else {
      std::cout << "Blad zapisu do pliku" << std::endl;
    }
  }

  file.close();
}

void DataBase::loadFile() {
  std::fstream file;
  file.open("Base.txt", std::ios::in);

  if (file.good() == false) {
    std::cout << "Plik nie istnieje" << std::endl;
    exit(0);
  }

  std::string line;
  std::string indivString;
  char separator = ',';
  std::vector<std::string> strVec;

  while (std::getline(file, line)) {
    std::stringstream ss(line);

    while (std::getline(ss, indivString, separator)) {
      strVec.push_back(indivString);
    }
    if (strVec[0] == "S") {
      int indexNum = std::stoi(strVec[3]);
      // Student* studentPtr = new Student(strVec[1], strVec[2], indexNum);
      // addNewRecord(studentPtr);
    } else if (strVec[0] == "E") {
      int salaryNum = std::stoi(strVec[3]);
      // Employee* employeePtr = new Employee(strVec[1], strVec[2], salaryNum);
      // addNewRecord(employeePtr);
    }
    strVec.clear();
  }

  file.close();
}

void DataBase::validatePESEL(uint64_t pesel) {
  // TODO: In future, is will be "bool" method

  std::array<int, 11> pesel_array = {0};
  for (int i = 10; i >= 0; i--) {
    pesel_array[i] = pesel % 10;
    pesel /= 10;
  }

  int sum = 0;
  std::array<int, 10> TEMP{{9, 7, 3, 1, 9, 7, 3, 1, 9, 7}};

  for (int i = 0; i < 10; i++)
    sum += pesel_array[i] * TEMP[i];

  if (sum % 10 == pesel_array[10])
    std::cout << "PESEL is correct" << std::endl;
  else
    std::cout << "PESEL is incorrect" << std::endl;
}

Record *DataBase::getRecord(size_t position) const {
  return dataBase[position];
}
/*
void DataBase::searchRecord()
{


    std::string myString ="Adam";
    auto it = std::find_if(dataBase.begin(), dataBase.end(), [&myString](const
Record& obj) {return obj.getName() == myString;});

    if (it != dataBase.end())
    {
      // found element. it is an iterator to the first matching element.
      // if you really need the index, you can also get it:
      auto index = std::distance(dataBase.begin(), it);
      std::cout<< index << std::endl;
    }
}
*/
