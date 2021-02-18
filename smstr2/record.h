#ifndef __RECORD_H__
#define __RECORD_H__

struct record
{
    void print();

    char * code{nullptr};
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

void open(FILE * input, std::vector<record *> & dest);
void find_code(char * str, std::vector<record *> & dest);
void find_birthplace(std::string str, std::vector<record *> & dest);
void clean_up(std::vector<record *> & dest);

#endif
