#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

bool cmp(std::string a, std::string b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    std::ifstream input;
    input.open("census.csv");
    if (!input.is_open()) return 1;

    std::string line;
    std::vector<std::string> v;
    while (std::getline(input, line))
    {
        v.push_back(line);
    }

    std::sort(v.begin(), v.end(), cmp);

    for (auto i : v)
    {
        std::cout << i << "\n";
    }

    return 0;
}
