#include <iostream>
#include <typeinfo>
#include "DataBase.hpp"

int main()
{
    DataBase base;

    Student s1("Adam", "Malysz", 234398);
    Student s2("Tadeusz", "Bocian", 225587);
    Student s3("Monika", "Czajkowska", 223509);

    Employee e1("Elzbieta", "Krol", 3740);
    Employee e2("Roman", "Czarny", 3565);

    base.addNewRecord(&s1);
    base.addNewRecord(&e2);
    base.addNewRecord(&s2);
    base.addNewRecord(&e1);
    base.addNewRecord(&s3);

    base.displayRecordList();

    base.sortStudentsByIndex();

    base.displayRecordList();


   /*

    base.removeStudentByIndex(225587);

    base.displayStudentList();*/



    return 0;
}
