#ifndef __REC_H__
#define __REC_H__

#include <string>

struct record
{
    char * code{nullptr};
    std::string birthplace{""};
    double night_pop{0};
    double resident_pop{0};

    void print();
};

void open(FILE * input, record ** dest);
void find_code(char * str, record ** dest, size_t len);
void find_birthplace(std::string str, record ** dest, size_t len);
void clean_up(record ** dest, size_t len);

#endif
