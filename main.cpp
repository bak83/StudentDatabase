#include "DataBase.hpp"

#include <iostream>

int main()
{
    DataBase base;

    Student* s1 = new Student("Adam", "Malysz", 234398, 3.85);
    Student* s2 = new Student("Tadeusz", "Bocian", 225587, 4.93);
    Student* s3 = new Student("Monika", "Czajkowska", 223509, 4.06);

    Employee* e1 = new Employee("Elzbieta", "Krol", 3740);
    Employee* e2 = new Employee("Roman", "Czarny", 3565);

    base.addNewRecord(s1);
    base.addNewRecord(e2);
    base.addNewRecord(s2);
    base.addNewRecord(e1);
    base.addNewRecord(s3);

    base.displayRecordList();

    base.removeStudentByIndex(225587);

    base.displayRecordList();

    base.sortStudentsByIndex();

    base.displayRecordList();

    base.sortBySurname();

    base.displayRecordList();
    
    base.saveToFile();  // zapisz zawartosc bazy 'base' do pliku

    DataBase fileBase;  // utworz nowa baze

    fileBase.loadFile();    // wczytaj rekordy z pliku do nowej bazy
    fileBase.displayRecordList();   // wyswietl rekorody z pliku

    return 0;
}
