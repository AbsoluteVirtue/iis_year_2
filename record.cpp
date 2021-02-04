#include <cstring>
#include <string>

#include "record.h"



void record::print()
{
    printf("%s %s %.0f %.0f\n", 
                this->code,
                this->birthplace.c_str(),
                this->night_pop,
                this->resident_pop);
}

void open(FILE * input, record ** dest) 
{
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
        
        dest[i] = tmp;
        ++i;
    }
}

void find_code(char * str, record ** dest, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        if (!strcmp(str, dest[i]->code))
        {
            dest[i]->print();
        }
    }
}

void find_birthplace(std::string str, record ** dest, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        if (str == dest[i]->birthplace)
        {
            dest[i]->print();
        }
    }
}

void clean_up(record ** dest, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete [] dest[i]->code;
        delete dest[i];
    }
}
