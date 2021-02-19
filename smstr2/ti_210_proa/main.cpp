#include <sstream>
#include <string>
#include "mLibrary.h"

static int count = 10;

int main(int argc, char const *argv[])
{
    movie ** arr = nullptr;

    memoAlloc(arr, count);

    for (size_t i = 0; i < count; i++)
    {
        std::stringstream x;
        x << i;
        std::string bufer = "Test " + x.str();

        arr[i]->name = bufer;
        arr[i]->country = bufer;
        arr[i]->producer = bufer;
        arr[i]->genre = bufer;
        arr[i]->year = 2000 + i;

        arr[i]->print();
    }

    freeMemo(arr, count);

    return 0;
}
