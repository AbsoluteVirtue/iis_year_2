#include <cstring>
#include <string>
#include <vector>

#include "rec.h"

void record::print()
{
    printf("%s %s %.0f %.0f\n", 
                this->code,
                this->birthplace.c_str(),
                this->night_pop,
                this->resident_pop);
}

void open(FILE * input, std::vector<record *> & dest) 
{
    char buf [100] = {};
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

        dest.push_back(tmp);
    }
}

void find_code(char * str, std::vector<record *> & dest) 
{
    for (auto it : dest)
    {
        if (!strcmp(str, it->code))
        {
            it->print();
        }
    }
}

void find_birthplace(std::string str, std::vector<record *> & dest) 
{
    for (auto it : dest)
    {
        if (str == it->birthplace)
        {
            it->print();
        }
    }
}

void clean_up(std::vector<record *> & dest)
{
    for (auto it : dest)
    {
        delete [] it->code;
    }
}
