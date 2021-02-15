#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

#include "smstr2/record.h"

int main(int argc, char const *argv[])
{
    record ** array = nullptr;

    std::ifstream input;
    input.open("census.csv");
    if (!input.is_open()) return 1;

    std::string line;
    while (std::getline(input, line))
    {
        std::cout << line << std::endl;
    }

    return 0;
}
