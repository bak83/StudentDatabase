#include "Generator.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <fstream>
#include <ctime>
#include <random>
#include <array>

int Generator::generateRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

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

    int randNum = generateRandomNumber(1, 100);

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

    int randNum = generateRandomNumber(1, 100);

    std::string line;
    int lineNum = 1;

    while (getline(file, line)) {
        if (lineNum == randNum) {
            surnameGen = line;
            break;
        }
        lineNum++;
    }

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

    int randNum = generateRandomNumber(1, 10);

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

    int randNum = generateRandomNumber(1, 30);

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
    return generateRandomNumber(1, 120);
}

uint64_t Generator::generatePESEL(int gend, int type)
{
    std::array<int,11> peselArray = {0};
    int randYear, randMonth, randDay, randSeries, randGender;

    randMonth = generateRandomNumber(1, 12);
    if (randMonth == 1 || randMonth == 3 || randMonth == 5 || randMonth == 7 ||
            randMonth == 8 || randMonth == 10 || randMonth == 12) {

        randDay = generateRandomNumber(1, 31);
    }
    else if (randMonth == 4 || randMonth == 6 || randMonth == 9 || randMonth == 11) {
        randDay = generateRandomNumber(1, 30);
    }
    else if (randMonth == 2) {
         randDay = generateRandomNumber(1, 28);
    }

    peselArray[2] = randMonth / 10; // MIESIAC
    peselArray[3] = randMonth % 10;
    peselArray[4] = randDay / 10;   // DZIEŃ
    peselArray[5] = randDay % 10;

    randSeries = generateRandomNumber(100, 999);
    peselArray[6] = randSeries / 100;
    peselArray[7] = (randSeries % 100) / 10;
    peselArray[8] = randSeries % 10;

    if (type == 0) {
        randYear = generateRandomNumber(1983, 1999);
        peselArray[0] = (randYear % 100) / 10;  // ROK
        peselArray[1] = randYear % 10;
        if (gend == 0) {    // female student
            peselArray[9] = generateRandomNumber(0, 4) * 2;
        }
        else if (gend == 1) {  // male student
            peselArray[9] = generateRandomNumber(0, 4) * 2 + 1;
        }
    }
    else if (type == 1) {
        randYear = generateRandomNumber(1948, 1994);
        peselArray[0] = (randYear % 100) / 10;  // ROK
        peselArray[1] = randYear % 10;
        if (gend == 0) {    // female employee
            peselArray[9] = generateRandomNumber(0, 4) * 2;
        }
        else if (gend == 1) {   // male employee
            peselArray[9] = generateRandomNumber(0, 4) * 2 + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += peselArray[i];
    }

    int controlNum = (10 - (sum % 10)) % 10;
    peselArray[10] = controlNum;

    uint64_t peselNum = 0;

    for (int i = 0; i < 11; ++i) {  // zamiana tablicy na liczbe
        peselNum *= 10;
        peselNum += peselArray[i];
    }

    return peselNum;
}

int Generator::generateIndex()
{
    return generateRandomNumber(200000, 259999);
}

int Generator::generateSalary()
{
    return generateRandomNumber(2500, 6000);
}

Record* Generator::generateRecord()
{
    int randNumGen = generateRandomNumber(0, 1); // losuje plec
    int randNumType = generateRandomNumber(0, 1);   // losuje typ student/pracownik

    if (randNumType == 0) {
        Student* studentPtr = new Student(generateName(randNumGen), generateSurname(randNumGen),
                                          generateGender(randNumGen), generatePESEL(randNumGen, randNumType),
                                        { generateCity(), generateStreet(), generateHouseNumber() },
                                          generateIndex());
        return studentPtr;
    }
    else if (randNumType == 1) {
        Employee* employeePtr = new Employee(generateName(randNumGen), generateSurname(randNumGen),
                                             generateGender(randNumGen), generatePESEL(randNumGen, randNumType),
                                           { generateCity(), generateStreet(), generateHouseNumber() },
                                             generateSalary());
        return employeePtr;
    }
}
