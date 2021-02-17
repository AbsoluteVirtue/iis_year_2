#include <cstring>
#include <iostream>
#include <fstream>

struct record
{
    std::string code;
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

static size_t count = 10;

int main(int argc, char const *argv[])
{
    record ** array = new record * [count];

    for (size_t i = 0; i < count; i++)
    {
        array[i] = new record({
            "Test",
            "test",
            ((double)i + 1) * 10,
            ((double)i + 1) * 100,
        });
    }

    for (size_t i = 0; i < count; i++)
    {
        delete array[i];
    }
    delete [] array;

    std::cout << "Done!";
    return 0;
}
