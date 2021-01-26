#include <cstdio>
#include <cstdlib>
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

    char buf [100] = {};
    size_t i = 0;
    while (fgets(buf, 100, input))
    {
        const char * delim = ",\"\n";
        char * token = strtok(buf, delim);

        if (!strcmp(token, "Code")) continue;
        
        record * tmp = new record;

        while (token)
        {
            if (tmp->code == nullptr) 
            {
                tmp->code = new char [strlen(token) + 1];
                strcpy(tmp->code, token);
            }
            else if (tmp->birthplace == "")
            {
                tmp->birthplace = token;
            }
            else if (tmp->night_pop == 0) 
            {
                tmp->night_pop = (double)atol(token);
            }
            else if (tmp->resident_pop == 0) 
            {
                tmp->resident_pop = (double)atol(token);
            }
            token = strtok(NULL, delim);
        }
        
        db[i] = tmp;
        ++i;
    }

    char str [10] = {};
    printf("enter code: \n");
    scanf("%s", str);

    for (size_t i = 0; i < NO_OF_LINES; i++)
    {
        if (!strcmp(str, db[i]->code))
        {
            db[i]->print();
        }
    }

    printf("enter code: \n");
    
    std::string in = ""; 
    std::cin >> in;

    for (size_t i = 0; i < NO_OF_LINES; i++)
    {
        if (in == db[i]->birthplace)
        {
            db[i]->print();
        }
    }
    
    for (size_t i = 0; i < NO_OF_LINES; i++)
    {
        delete [] db[i]->code;
        delete db[i];
    }    
    
    fclose(input);
    return 0;
}
