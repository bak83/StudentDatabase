#include "DataBase.hpp"

#include <iostream>

int main() {
  DataBase base;

  Student *s1 = new Student("Adam", "Malysz", male, 95021333374,
                            {"Wroclaw", "Miodowa", 4}, 234398);
  Student *s2 = new Student("Tadeusz", "Bocian", male, 12345678913,
                            {"Warszawa", "Cebulowa", 12}, 225587);
  Student *s3 = new Student("Monika", "Czajkowska", female, 12345678914,
                            {"Krakow", "Nozownicza", 8}, 223509);

  Employee *e1 = new Employee("Elzbieta", "Krol", female, 12345678915,
                              {"Wroclaw", "Dworcowa", 9}, 3740);
  Employee *e2 = new Employee("Roman", "Czarny", male, 12345678916,
                              {"Wroclaw", "Gdanska", 45}, 3565);

  base.addNewRecord(s1);
  base.addNewRecord(e2);
  base.addNewRecord(s2);
  base.addNewRecord(e1);
  base.addNewRecord(s3);

  base.displayRecordList();

  base.sortStudentsByIndex();

  base.displayRecordList();

  base.removeStudentByIndex(225587);
  base.removeRecordByPESEL(95021333374);
  base.displayRecordList();

  base.sortBySurname();
  base.sortByPESEL();
  base.displayRecordList();
  base.validatePESEL(95021333356);
  base.searchRecordBySurname("Czajkowska");
  base.searchRecordByPESEL(12345678913);

  base.saveToFile();

  DataBase base2;

  base2.loadFile();

  base2.displayRecordList();

  DataBase base3;
  base3.generate(10);

  base3.displayRecordList();

  delete s1, s2, s3, e1, e2;

  return 0;
}
