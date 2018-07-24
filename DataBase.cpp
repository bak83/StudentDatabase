#include "DataBase.hpp"

#include <algorithm>
#include <typeinfo>
#include <typeindex>
#include <fstream>
#include <cstdlib>
#include <sstream>

void DataBase::addNewRecord(Record* r)
{
    dataBase.push_back(r);
}

void DataBase::displayRecordList()
{
    std::cout << "BAZA DANYCH:" << std::endl;
    for (int i = 0; i < dataBase.size(); ++i) {
        std::cout << i+1 << ". ";
        dataBase.at(i)->showAll();
    }
}

void DataBase::sortStudentsByIndex()
{
    std::sort(dataBase.begin(), dataBase.end(), [](const Record* p1, const Record* p2) {
        return std::type_index(typeid(*p1)) < std::type_index(typeid(*p2));
    }); // oddzielenie studentow od pracownikow (studenci na gorze)

    int boundaryIndex = 0;  // od tego elementu w bazie zaczyna sie typ Employee
    for (int i = 0; i < dataBase.size(); ++i) {
        if (dataBase.at(i)->getId() == 1)
            boundaryIndex++;
        else
            break;
    }

    std::sort(dataBase.begin(), dataBase.begin()+boundaryIndex, [](Record* p1, Record* p2) {
        return dynamic_cast<Student*>(p1)->getIndex() < dynamic_cast<Student*>(p2)->getIndex();
    });
}

void DataBase::sortBySurname()
{
    std::sort(dataBase.begin(), dataBase.end(), [](Record* p1, Record* p2) {
       return p1->getSurname() < p2->getSurname();
    });
}

void DataBase::removeStudentByIndex(int idx)
{
    for (int i = 0; i < dataBase.size(); ++i) {
        if (dataBase.at(i)->getId() == 1 &&
                dynamic_cast<Student*>(dataBase.at(i))->getIndex() == idx) {

            dataBase.erase(dataBase.begin()+i);
            break;
        }
    }
}

void DataBase::saveToFile()
{
    std::fstream file;
    file.open("Base.txt", std::ios::out);

    for (int i = 0; i < dataBase.size(); ++i) {
        if (dataBase.at(i)->getId() == 1) {
            file << "S" << "," << dataBase[i]->getName() << ","
                 << dataBase[i]->getSurname() << ","
                 << dynamic_cast<Student*>(dataBase.at(i))->getIndex() << ","
                 << dynamic_cast<Student*>(dataBase.at(i))->getGpa() << std::endl;
        }
        else if (dataBase.at(i)->getId() == 2) {
            file << "E" << "," << dataBase[i]->getName() << ","
                 << dataBase[i]->getSurname() << ","
                 << dynamic_cast<Employee*>(dataBase.at(i))->getSalary() << std::endl;
        }
    }

    file.close();
}

void DataBase::loadFile()
{
    std::fstream file;
    file.open("Base.txt", std::ios::in);

    if (file.good() == false)
    {
        std::cout << "File not exist" << std::endl;
        exit(0);
    }
    std::vector<Record*> fileDataBase;  // baza danych tylko z pliku

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
            float gpaNum = std::stof(strVec[4]);
            Student* studentPtr = new Student(strVec[1], strVec[2], indexNum, gpaNum);
            addNewRecord(studentPtr);
            fileDataBase.push_back(studentPtr);
        }
        else if (strVec[0] == "E") {
            int salaryNum = std::stoi(strVec[3]);
            Employee* employeePtr = new Employee(strVec[1], strVec[2], salaryNum);
            addNewRecord(employeePtr);
            fileDataBase.push_back(employeePtr);
        }
        strVec.clear();
    }

    file.close();
    std::cout << "BAZA DANYCH Z PLIKU:" << std::endl;
    for (int i = 0; i < fileDataBase.size(); ++i) {
        std::cout << i+1 << ". ";
        fileDataBase.at(i)->showAll();
    }
}

Record* DataBase::getRecord(size_t position) const
{
    return dataBase[position];
}
