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

#endif
