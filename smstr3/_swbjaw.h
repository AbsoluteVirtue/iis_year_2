#ifndef __SWBJAW_H__
#define __SWBJAW_H__

class SwbjawException;
class Swbjaw;

#include <ostream>


class SwbjawException : public std::exception {
private:
    char * _message;

public:
    SwbjawException(const char * msg);
    const char * what() const throw();
};


class Swbjaw {

private:
    char * _character;

public:
    Swbjaw();
    ~Swbjaw();
    Swbjaw(const char * str);
    Swbjaw(const Swbjaw & obj);
    Swbjaw(Swbjaw && obj);

    Swbjaw & operator =(const Swbjaw & obj);
    Swbjaw & operator =(Swbjaw && obj);
    Swbjaw operator +(const Swbjaw & obj);
    friend std::ostream & operator <<(std::ostream& outs, const Swbjaw & obj);
};


#endif
