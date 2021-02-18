#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

struct record
{
    std::string code;
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

static size_t count = 10;

void print(record ** & arr, size_t n);
void create(record ** & arr, size_t n);
void clear(record ** & arr, size_t n);

int main(int argc, char const *argv[])
{
    record ** array = nullptr;

    create(array, count);

    print(array, count);

    clear(array, count);

    std::cout << "Done!";
    return 0;
}

void create(record ** & arr, size_t n)
{
    arr = new record * [n];

    for (size_t i = 0; i < n; i++)
    {
        arr[i] = new record;
        arr[i]->birthplace = "Hello " + i;
        std::ostringstream addr;
        addr << arr[i];
        arr[i]->code = addr.str();
        arr[i]->night_pop = 1;
        arr[i]->resident_pop = 2;
    }
}

void clear(record ** & arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete [] arr;
}

void print(record ** & arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i]->code << "\n";
    }
}
