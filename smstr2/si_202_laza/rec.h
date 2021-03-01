#ifndef __REC_H__
#define __REC_H__

#include <string>

struct record
{
    char * name{nullptr};
    std::string adres{""};
    double number{0};
    double faculties{0};
    double students{0};

    void print();
};

void open(FILE * input, record ** dest);
void find_name(char * str, record ** dest, size_t len);
void find_adres(std::string str, record ** dest, size_t len);
void clean_up(record ** dest, size_t len);

#endif