#include "DataBase.hpp"
#include <algorithm>
#include <typeinfo>
#include <typeindex>

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

    std::sort(dataBase.begin(), dataBase.begin()+boundaryIndex,
              [](Record* p1, Record* p2) {
        return dynamic_cast<Student*>(p1) > dynamic_cast<Student*>(p2);
    });
}
/*
void DataBase::removeStudentByIndex(int idx)
{
    for (int i = 0; i < studentBase.size(); ++i) {
        if (idx == studentBase.at(i).getIndex()) {
            studentBase.erase(studentBase.begin() + i);
            break;
        }
    }
}

}*/
