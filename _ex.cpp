#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdbool>

#include "smstr2/si_202_ghim/flight_funs.h"

struct vec
{
    int x{0}, y{0};

    vec() {}

    vec(const vec & other)
    {
        this->x = this->y = 5;
    }

    vec & operator=(const vec & other)
    {
        this->x = this->y = 4;
        return *this;
    }
    vec & operator=(vec && other) noexcept 
    {
        this->x = this->y = 3;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    vec a = vec();
    a.x = 1;
    a.y = 1;
    vec b = a;

    std::cout << b.x << " " << b.y;

    return 0;
}
