#include "DataBase.hpp"

void DataBase::addNewRecord(Record* r)
{
    dataBase.push_back(r);
}

void DataBase::displayRecordList()
{
    std::cout << "BAZA DANYCH:" << std::endl;
    for (int i = 0; i < dataBase.size(); ++i) {
        std::cout << i+1 << ". ";
        dataBase.at(i)->getInfo();
    }
}


/*void DataBase::sortStudentsByIndex()
{  
    for (int i = 1; i < studentBase.size(); ++i) {
        for (int j = studentBase.size()-1; j >= 1; j--) {
            if (studentBase.at(j).getIndex() < studentBase.at(j-1).getIndex()) {
                Student buff;
                buff = studentBase.at(j-1);
                studentBase.at(j-1) = studentBase.at(j);
                studentBase.at(j) = buff;
            }
        }
    }
}*/
/*
void DataBase::removeStudentByIndex(uint64_t idx)
{
    for (int i = 0; i < studentBase.size(); ++i) {
        if (idx == studentBase.at(i).getIndex()) {
            studentBase.erase(studentBase.begin() + i);
            break;
        }
    }
}

}*/
