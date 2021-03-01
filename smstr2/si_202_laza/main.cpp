#include <cstdio>
#include <cstring>
#include <string>
#include "rec.h"

void record::print()
{
    printf("%s %s %.0f %.0f%.0f \n", 
                this->name,
                this->adres.c_str(),
                this->number,
                this->faculties,
                this->students);

}

void open(FILE * input, record ** dest) 
{
    char buf [100] = {};
    size_t i = 0;
    while (fgets(buf, 100, input))
    {
        const char * delim = ",\"\n";
        char * token = strtok(buf, delim);

        if (!strcmp(token, "Name")) continue;
        
        record * tmp = new record;

        while (token)
        {
            if (tmp->name== nullptr) 
            {
                tmp->name = new char [strlen(token) + 1];
                strcpy(tmp->name, token);
            }
            else if (tmp->adres == "")
            {
                tmp->adres = token;
            }
            else if (tmp->number == 0) 
            {
                tmp->number = (double)atol(token);
            }
            else if (tmp->faculties == 0) 
            {
                tmp->faculties = (double)atol(token);
            }
            else if (tmp->students == 0) 
            {
                tmp->students = (double)atol(token);
            }
            token = strtok(NULL, delim);
        }
        
        dest[i] = tmp;
        ++i;
    }
}

void find_name(char * str, record ** dest, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        if (!strcmp(str, dest[i]->name))
        {
            dest[i]->print();
        }
    }
}

void find_adres(std::string str, record ** dest, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        if (str == dest[i]->adres)
        {
            dest[i]->print();
        }
    }
}

void clean_up(record ** dest, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete [] dest[i]->name;
        delete dest[i];
    }
}