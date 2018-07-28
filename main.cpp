#include "DataBase.hpp"

#include <iostream>

int main()
{
    DataBase base;

    Student* s1 = new Student("Adam", "Malysz", 234398);
    Student* s2 = new Student("Tadeusz", "Bocian", 225587);
    Student* s3 = new Student("Maksymilian", "Czajkowski", 223509);

    Employee* e1 = new Employee("Elzbieta", "Krol", 3740);
    Employee* e2 = new Employee("Roman", "Czarny", 3565);

    base.addNewRecord(s1);
    base.addNewRecord(e2);
    base.addNewRecord(s2);
    base.addNewRecord(e1);
    base.addNewRecord(s3);

    base.displayRecordList();

    base.sortStudentsByIndex();

    base.displayRecordList();   

    base.removeStudentByIndex(225587);

    base.displayRecordList();

    base.sortBySurname();

    base.displayRecordList();

    delete s1, s2, s3, e1, e2;

    return 0;
}
