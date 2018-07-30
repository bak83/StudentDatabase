#include "Generator.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <fstream>
#include <ctime>
#include <random>

std::string Generator::generateName(int gend)
{
    std::fstream file;
    std::string nameGen;

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
            nameGen = line;
            break;
        }
        lineNum++;
    }

    file.close();

    return nameGen;
}

std::string Generator::generateSurname(int gend)
{
    std::fstream file;
    std::string surnameGen;

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
            surnameGen = line;
            break;
        }
        lineNum++;
    };

    file.close();

    return surnameGen;
}

gender_t Generator::generateGender(int gend)
{
    if (gend == 0)
        return female;
    else if (gend == 1)
        return male;
}

std::string Generator::generateCity()
{
    std::fstream fileCities;
    std::string city;

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
            city = line;
            break;
        }
        lineNum++;
    }

    fileCities.close();

    return city;
}

std::string Generator::generateStreet()
{
    std::fstream fileStreets;
    std::string street;

    fileStreets.open("Streets.txt", std::ios::in);

    if (fileStreets.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 30 + 1;

    std::string line;
    int lineNum = 1;

    while (getline(fileStreets, line)) {
        if (lineNum == randNum) {
            street = line;
            break;
        }
        lineNum++;
    }

    fileStreets.close();

    return street;
}

int Generator::generateHouseNumber()
{
    return rand() % 150 + 1;
}

uint64_t Generator::generatePESEL(int gend)
{
    if (gend == 0)
        return 12345678901;
    else if (gend == 1)
        return 99876543212;
}

int Generator::generateIndex()
{
    return rand() % 50001 + 200000;
}

int Generator::generateSalary()
{
    return rand() % 4001 + 2000;
}

Record* Generator::generateRecord()
{
    int randNumGen = rand() % 2; // losuje plec
    int randNumType = rand() % 2;   // losuje typ student/pracownik

    if (randNumType == 0) {
        Student* studentPtr = new Student(generateName(randNumGen), generateSurname(randNumGen),
                                          generateGender(randNumGen), generatePESEL(randNumGen),
                                        { generateCity(), generateStreet(), generateHouseNumber() },
                                          generateIndex());
        return studentPtr;
    }
    else if (randNumType == 1) {
        Employee* employeePtr = new Employee(generateName(randNumGen), generateSurname(randNumGen),
                                             generateGender(randNumGen), generatePESEL(randNumGen),
                                           { generateCity(), generateStreet(), generateHouseNumber() },
                                             generateSalary());
        return employeePtr;
    }
}
