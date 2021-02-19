#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include "functions.h"

static int count = 10;

int main(int argc, char const *argv[])
{
    FILM ** arr = nullptr;

    strucalloc(arr, count);

    for (size_t i = 0; i < count; i++)
    {
        arr[i]->year = i + 1900;
        std::stringstream x;
        x << i;
        std::string bufer = "Test " + x.str();

        arr[i]->country = (char *)malloc(strlen(bufer.c_str()) + 1);
        strcpy(arr[i]->country, bufer.c_str());

        arr[i]->janr = (char *)malloc(strlen(bufer.c_str()) + 1);
        strcpy(arr[i]->janr, bufer.c_str());

        arr[i]->nam = (char *)malloc(strlen(bufer.c_str()) + 1);
        strcpy(arr[i]->nam, bufer.c_str());

        arr[i]->reg = (char *)malloc(strlen(bufer.c_str()) + 1);
        strcpy(arr[i]->reg, bufer.c_str());

        strucoutp(arr, i);
    }

    strucfree(arr, count);

    return 0;
}
