#include "Generator.hpp"

#include <fstream>
#include <ctime>
#include <random>

void Generator::generateName()
{
    std::fstream file;
    file.open("Names.txt", std::ios::in);
    if (file.good() == false) {
        std::cout << "Plik nie istnieje" << std::endl;
        exit(0);
    }

    int randNum = rand() % 100 + 1;

    std::string line;
    int lineNum = 1;

    while (geline(file, line)) {
        if (lineNum == randNum) {
            record->set
        }
    }

}
