#include "DataBase.hpp"
#include "Generator.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <sstream>
#include <iomanip>

void DataBase::addNewRecord(Record *r)
{
    if (validatePESEL(r->getPESEL()))
        dataBase.push_back(r);
    else ;
}

void DataBase::displayRecordList()
{
  std::cout << "BAZA DANYCH:" << std::endl;
  for (int i = 0; i < dataBase.size(); ++i) {
    std::cout << std::right << std::setw(3) << i + 1 << ". ";
    dataBase.at(i)->showAll();
  }
}

void DataBase::sortStudentsByIndex()
{
  std::sort(dataBase.begin(), dataBase.end(), [](const Record *p1, const Record *p2) {
              return p1->getIndex() < p2->getIndex();
            });
}

void DataBase::sortEmployeesBySalary()
{
  std::sort(dataBase.begin(), dataBase.end(), [](const Record *p1, const Record *p2) {
              return p1->getSalary() < p2->getSalary();
            });
}

void DataBase::sortBySurname()
{
  std::sort(dataBase.begin(), dataBase.end(), [](Record *p1, Record *p2) {
    return p1->getSurname() < p2->getSurname();
  });
}

void DataBase::sortByPESEL()
{
  std::sort(dataBase.begin(), dataBase.end(), [](Record *p1, Record *p2) {
    return p1->getPESEL() < p2->getPESEL();
  });
}

void DataBase::removeStudentByIndex(int idx)
{
  for (int i = 0; i < dataBase.size(); ++i) {
    if (dataBase[i]->getIndex() < NO_MATCH && dataBase[i]->getIndex() == idx) {
      dataBase.erase(dataBase.begin() + i);
      break;
    }
  }
}

void DataBase::removeRecordByPESEL(uint64_t pes)
{
    for (int i = 0; i < dataBase.size(); ++i) {
        if (dataBase[i]->getPESEL() == pes) {
            dataBase.erase(dataBase.begin() + i);
            break;
        }
    }
}

void DataBase::saveToFile()
{
  std::fstream file;
  file.open("Base.txt", std::ios::out);

  for (int i = 0; i < dataBase.size(); ++i) {
    if (dataBase[i]->getIndex() < NO_MATCH) {
      file << "S" << ":" << dataBase[i]->getName() << ":" << dataBase[i]->getSurname()
           << ":" << dataBase[i]->getPESEL() << ":" << dataBase[i]->getGender()
           << ":" << dataBase[i]->getAddress().city << ":" << dataBase[i]->getAddress().street
           << ":" << dataBase[i]->getAddress().number << ":" << dataBase[i]->getIndex() << std::endl;
    } else if (dataBase[i]->getSalary() < NO_MATCH) {
      file << "E" << ":" << dataBase[i]->getName() << ":" << dataBase[i]->getSurname()
           << ":" << dataBase[i]->getPESEL() << ":" << dataBase[i]->getGender()
           << ":" << dataBase[i]->getAddress().city << ":" << dataBase[i]->getAddress().street
           << ":" << dataBase[i]->getAddress().number << ":" << dataBase[i]->getSalary() << std::endl;
    } else {
      std::cout << "Blad zapisu do pliku" << std::endl;
    }
  }

  file.close();
}

void DataBase::loadFile()
{
  std::fstream file;
  file.open("Base.txt", std::ios::in);

  if (file.good() == false) {
    std::cout << "Plik nie istnieje" << std::endl;
    exit(0);
  }

  std::string line;
  std::string indivString;
  char separator = ':';
  std::vector<std::string> strVec;

  while (std::getline(file, line)) {
    std::stringstream ss(line);

    while (std::getline(ss, indivString, separator)) {
      strVec.push_back(indivString);
    }
    uint64_t peselNum= std::stol(strVec[3]);
    int houseNum = std::stoi(strVec[7]);
    if (strVec[0] == "S") {
        int indexNum = stoi(strVec[8]);
        if (strVec[4] == "0") {
            Student* studentPtr = new Student(strVec[1], strVec[2], female, peselNum,
            {strVec[5], strVec[6], houseNum}, indexNum);
            addNewRecord(studentPtr);
        }
        else if (strVec[4] == "1") {
            Student* studentPtr = new Student(strVec[1], strVec[2], male, peselNum,
            {strVec[5], strVec[6], houseNum}, indexNum);
            addNewRecord(studentPtr);
        }
    } else if (strVec[0] == "E") {
        int salaryNum = std::stoi(strVec[8]);
        if (strVec[4] == "0") {
            Employee* employeePtr = new Employee(strVec[1], strVec[2], female, peselNum,
            {strVec[5], strVec[6], houseNum}, salaryNum);
            addNewRecord(employeePtr);
        }
        else if (strVec[4] == "1") {
            Employee* employeePtr = new Employee(strVec[1], strVec[2], male, peselNum,
            {strVec[5], strVec[6], houseNum}, salaryNum);
            addNewRecord(employeePtr);
        }
    }
    strVec.clear();
  }

  file.close();
}

bool DataBase::validatePESEL(uint64_t pesel)
{
    std::array<int,11> coeffs = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    std::array<int,11> peselArray = {0};

    for (int i = 10; i >= 0; --i) { // zamiana PESELu na tablice
        peselArray[i] = pesel % 10;
        pesel /= 10;
    }

    int sum = 0;
    for (int i = 0; i < 11; ++i) {
        sum += peselArray[i] * coeffs[i];
    }

    if (sum % 10 == 0)
        return true;
    else
        return false;
}

Record *DataBase::getRecord(size_t position) const
{
    return dataBase[position];
}

Record *DataBase::searchRecordBySurname(std::string surname) const
{
    for (int i = 0; i < dataBase.size(); ++i){
         if (dataBase[i]->getSurname()==surname)
             return dataBase[i]; }
}

Record *DataBase::searchRecordByPESEL(uint64_t pesel) const
{
    for (int i = 0; i < dataBase.size(); ++i){
         if (dataBase[i]->getPESEL()==pesel)
             return dataBase[i]; }
}

void DataBase::generate(int n)
{
    Generator generator;
    for (int i = 0; i < n; ++i) {
        dataBase.push_back(generator.generateRecord());
    }
}
