#include <iostream>
#include <string>
#include <sstream>

int get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

int main(int argc, char const *argv[])
{
    std::istringstream buf;
    buf.str("1 2\n3 4\n");
    for (std::string line; std::getline(buf, line); )
    {
        std::cout << line;
    }
    
    return 0;
}