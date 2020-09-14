#ifndef __SWBJAW_H__
#define __SWBJAW_H__

#include <ostream>


class Swbjaw {

private:
    char * _character;

    void _copy_string(const char * _string);

public:
    Swbjaw();
    ~Swbjaw();
    Swbjaw(const char * _string);
    Swbjaw(const Swbjaw & obj);

    Swbjaw & operator =(const Swbjaw & obj);
    Swbjaw operator +(const Swbjaw & obj);
    friend std::ostream & operator <<(std::ostream& outs, const Swbjaw & obj);
};


#endif
