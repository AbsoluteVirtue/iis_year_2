#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>


#define NO_OF_LINES 278

struct record 
{
    char * code{nullptr};
    std::string birthplace{""};
    double night_pop{0};
    double resident_pop{0};
};

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
            printf("%s %.0f %.0f\n", 
                db[i]->birthplace.c_str(),
                db[i]->night_pop,
                db[i]->resident_pop);
        }
    }

    printf("enter code: \n");
    
    std::string in = ""; 
    std::cin >> in;

    for (size_t i = 0; i < NO_OF_LINES; i++)
    {
        if (in == db[i]->birthplace)
        {
            std::cout << db[i]->code << " " << db[i]->night_pop << " " << db[i]->resident_pop << "\n";
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
