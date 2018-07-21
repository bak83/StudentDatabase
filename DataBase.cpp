#include "DataBase.hpp"

void DataBase::addNewStudent(Student s)
{
    studentBase.push_back(s);
}

void DataBase::sortStudentsByIndex()
{  
    for (int i = 1; i < studentBase.size(); ++i)
    {
        for (int j = studentBase.size()-1; j >= 1; j--)
        {
            if (studentBase.at(j).getIndex() < studentBase.at(j-1).getIndex())
            {
                Student buff;
                buff = studentBase.at(j-1);
                studentBase.at(j-1) = studentBase.at(j);
                studentBase.at(j) = buff;
            }
        }
    }
}

void DataBase::removeStudentByIndex(uint64_t idx)
{
    for (int i = 0; i < studentBase.size(); ++i)
    {
        if (idx == studentBase.at(i).getIndex())
        {
            studentBase.erase(studentBase.begin() + i);
            break;
        }
    }
}

void DataBase::displayStudentList()
{
    std::cout << "LISTA STUDENTOW:" << std::endl;
    for (int i = 0; i < studentBase.size(); ++i)
    {
        std::cout << i+1 << ". " << studentBase.at(i).getName() << "  "
                  << studentBase.at(i).getSurname() << "  "
                  << studentBase.at(i).getIndex() << std::endl;
    }

    std::cout << std::endl;
}
