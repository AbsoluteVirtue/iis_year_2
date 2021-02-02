#ifndef __REC_H__
#define __REC_H__
#include <list>
#include <string>
#include <vector>

struct record
{
    void print();

    char * code{nullptr};
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

void open(FILE * input, std::list<record *> & dest);
void find_code(char * str,  std::list<record *> & dest);
void find_birthplace(std::string str,  std::list<record *> & dest);
void clean_up(std::list<record *> & dest);

#endif
