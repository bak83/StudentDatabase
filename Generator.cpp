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

    while (geline(file, line)) {
        if (lineNum == randNum) {
            record->name = line;
            break;
        }
    }

    file.close();
}

void Generator::generateSurname(int gend)
{
    std::fstream file;

    if (gend == 1)
        file.open("SurnamesFemale.txt", std::ios::in);
    else if (gend == 0)
        file.open("SurnamesMale.txt", std::ios::in);

    if (file.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 100 + 1;

    std::string line;
    int lineNum = 1;

    while (geline(file, line)) {
        if (lineNum == randNum) {
            record->surname = line;
            break;
        }
    }

    file.close();
}

Record* Generator::generateRecord()
{
    int randGender = rand() % 2;

    generateName(randGender);
    generateSurname(randGender);

    return record;
}
