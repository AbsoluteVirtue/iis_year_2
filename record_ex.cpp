#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "record.h"

#define NO_OF_LINES 278

int main(int argc, char const *argv[])
{
    FILE * input = fopen("census.csv", "r");
    if (input == NULL) 
    {
        printf("error: file read");
        return 1;
    }
    
    std::vector<record *> db;

    open(input, db);

    printf("\nenter code: ");

    char str [10] = {};
    scanf("%s", str);

    find_code(str, db);

    printf("\nenter birthplace: ");

    std::string in = "";
    std::cin >> in;

    find_birthplace(in, db);
    
    clean_up(db);
    
    fclose(input);

    return 0;
}
