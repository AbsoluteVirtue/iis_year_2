#include <iostream>
#include <string>
#include <sstream>

#include "newlab7.h"

static int count = 10;

int main()
{
    book **arr;

    dinamic(arr, count);

    for (size_t i = 0; i < count; i++)
    {
        std::stringstream x;
        x << i;
        std::string bufer = "Test " + x.str();

        arr[i]->code =  bufer;
        arr[i]->autor =  bufer;
        arr[i]->name =  bufer;
        arr[i]->year_of_create =  bufer;
        arr[i]->count_of_pages =  bufer;
        arr[i]->edition = 2000 + i;
    }

    print(arr, count);

    return 0;
}
