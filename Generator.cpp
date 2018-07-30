#include "Generator.hpp"

#include <fstream>
#include <ctime>
#include <random>

void Generator::generateName(int gend)
{
    std::fstream file;

    if (gend == 0)
        file.open("NamesFemale.txt", std::ios::in);
    else if (gend == 1)
        file.open("NamesMale.txt", std::ios::in);

    if (file.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 100 + 1;

    std::string line;
    int lineNum = 1;

    while (getline(file, line)) {
        if (lineNum == randNum) {
            record->name = line;
            break;
        }
        lineNum++;
    }

    file.close();
}

void Generator::generateSurname(int gend)
{
    std::fstream file;

    if (gend == 0)
        file.open("SurnamesFemale.txt", std::ios::in);
    else if (gend == 1)
        file.open("SurnamesMale.txt", std::ios::in);

    if (file.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 100 + 1;

    std::string line;
    int lineNum = 1;

    while (getline(file, line)) {
        if (lineNum == randNum) {
            record->surname = line;
            break;
        }
        lineNum++;
    }

    file.close();
}

void Generator::generateGender(int gend)
{
    if (gend == 0)
        record->gender = female;
    else if (gend == 1)
        record->gender = male;
}

void Generator::generateAddress()
{
    std::fstream fileCities;
    fileCities.open("Cities.txt", std::ios::in);

    if (fileCities.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 10 + 1;

    std::string line;
    int lineNum = 1;

    while (getline(fileCities, line)) {
        if (lineNum == randNum) {
            record->address.city = line;
            break;
        }
        lineNum++;
    }

    fileCities.close();

    std::fstream fileStreets;
    fileStreets.open("Streets.txt", std::ios::in);

    if (fileStreets.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    randNum = rand() % 30 + 1;
    lineNum = 1;

    while (getline(fileStreets, line)) { // ***
        if (lineNum == randNum) {
            record->address.street = line;
            break;
        }
        lineNum++;
    }

    fileStreets.close();

    randNum = rand() % 400 + 1;

    record->address.number = randNum;
}

void Generator::generatePESEL(int gend)
{
    if (gend == 0)
        record->PESEL = 12345678901;
    else if (gend == 1)
        record->PESEL = 99876543212;
}

int Generator::generateIndex()
{
    return 228769;
}

int Generator::generateSalary()
{
    return 3200;
}

Record* Generator::generateRecord()
{
    int randNum = rand() % 2; // losuje plec

    generateName(randNum);
    generateSurname(randNum);
    generateGender(randNum);
    generateAddress();
    generatePESEL(randNum);

    randNum = rand() % 2;   // losuje typ student/pracownik

    if (randNum == 0) {
        Student student(record->getName(), record->getSurname(),
                        record->getGender(), record->getPESEL(),
                        record->getAddress(), generateIndex());
        Student* studentPtr = &student;
        return studentPtr;
    }
    else {
        Employee employee(record->getName(), record->getSurname(),
                          record->getGender(), record->getPESEL(),
                          record->getAddress(), generateSalary());
        Employee* employeePtr = &employee;
        return employeePtr;
    }
}
