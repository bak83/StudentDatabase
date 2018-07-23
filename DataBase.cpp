#include "DataBase.hpp"
#include <algorithm>
#include <typeinfo>
#include <typeindex>
#include <fstream>
#include <cstdlib>


void DataBase::saveToFile()
{
    std::fstream file;
    file.open("Base.txt", std::ios::out);

    std::cout << "BAZA DANYCH (plik):" << std::endl;
    for (int i = 0; i < dataBase.size(); ++i) {
        file << i+1 << ". " << dataBase[i] -> getName() << "  "
             << dataBase[i] -> getSurname() << "  ";
        if (dataBase.at(i)->getId() == 1) {
            file << dynamic_cast<Student*>(dataBase.at(i))->getIndex() << std::endl;
        }
        else if (dataBase.at(i)->getId() == 2) {
            file << dynamic_cast<Employee*>(dataBase.at(i))->getSalary() << std::endl;
        }
    }

    file.close();
}

void DataBase::loadFile()
{
    std::fstream file;
    std::string line;
    file.open("Base.txt", std::ios::in);
    while (getline(file,line))
        std::cout << line << std::endl;
    file.close();
}


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
    });

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
