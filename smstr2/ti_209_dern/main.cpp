#include <sstream>
#include <string>
#include "kniga.h"

static int count = 10;

int main(int argc, char const *argv[])
{
    kniga ** arr = new kniga * [count];

    for (size_t i = 0; i < count; i++)
    {
        arr[i] = new kniga;
 
        arr[i]->year = i + 1900;
        arr[i]->pages = i + 100;
        arr[i]->circulation = i + 1000;

        std::stringstream x;
        x << i;
        std::string bufer = "Test " + x.str();

        arr[i]->name = bufer;
        arr[i]->author = bufer;
    }

    Print(arr, count);

    Delete_all(arr, count);
    
    return 0;
}
