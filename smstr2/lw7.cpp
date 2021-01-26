#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include "rec.h"


#define NO_OF_LINES 278


int main(int argc, char const *argv[])
{
    FILE * input = fopen("census.csv", "r");
    if (input == NULL) 
    {
        printf("error: file read");
        return 1;
    }
    
    record * db [NO_OF_LINES] = {};

    open(input, db);

    printf("\nenter code: ");
    char str [10] = {};
    scanf("%s", str);

    find_code(str, db, NO_OF_LINES);

    printf("\nenter birthplace: ");

    std::string in = ""; 
    std::cin >> in;

    find_birthplace(in, db, NO_OF_LINES);
    
    clean_up(db, NO_OF_LINES);
    
    fclose(input);

    return 0;
}
