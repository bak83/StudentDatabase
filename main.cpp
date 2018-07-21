#include <iostream>
#include "DataBase.hpp"

int main()
{
    DataBase base;

    Student s1("Ferdynand", "Kiepski", 234398);
    Student s2("Tadeusz", "Bocian", 225587);
    Student s3("Monika", "Czajkowska", 223509);

    base.addNewStudent(s1);
    base.addNewStudent(s2);
    base.addNewStudent(s3);
   
    base.displayStudentList();

    base.sortStudentsByIndex();

    base.displayStudentList();

    base.removeStudentByIndex(225587);

    base.displayStudentList();

    return 0;
}
