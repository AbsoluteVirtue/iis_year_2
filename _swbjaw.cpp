#include <cstddef>
#include <ostream>
#include "_swbjaw.h"


std::size_t _strlen(const char* start) {
   const char* end = start;

   while (*end++ != 0);

   return end - start - 1;
}


char * & _copy_string(const char * _string) {

    std::size_t _length = _strlen(_string);
    char * _character = new char [_length + 1];

    for (int i=0;i < _length; i++) {
        _character[i] = _string[i];
    }

    _character[_length] = char('\0');

    return _character;
}


SwbjawException::SwbjawException(const char * msg) {
    _message = _copy_string(msg);
}


const char *  SwbjawException::what() const throw() {
    return _message;
}


Swbjaw::Swbjaw() : _character(nullptr) {

}


Swbjaw::Swbjaw(const char * str) {

    _character = _copy_string(str);

}


Swbjaw::Swbjaw(const Swbjaw & obj) {

    *this = obj;

}


Swbjaw::Swbjaw(Swbjaw && obj) : _character(nullptr) {

    *this = std::move(obj);

}


Swbjaw::~Swbjaw() {

    delete [] _character;
    _character = nullptr;

}


Swbjaw & Swbjaw::operator =(const Swbjaw & obj) {

    if (_character != nullptr) {
        delete [] _character;
        _character = nullptr;
        _character = _copy_string(obj._character);
    }

    return *this;
}


Swbjaw & Swbjaw::operator =(Swbjaw && obj) noexcept {

    if (this != &obj) {
        delete [] _character;

        _character = obj._character;
        obj._character = nullptr;
    }

    return *this;
}


Swbjaw Swbjaw::operator +(const Swbjaw & obj) {

    Swbjaw ret;
    std::size_t len = _strlen(_character);
    std::size_t obj_len = _strlen(obj._character);

    ret._character = new char [len + obj_len + 1];

    int i = 0;
    for (; i < len; i++) {
        ret._character[i] = _character[i];
    }

    for (int j = 0; i < len; i++, j++) {
        ret._character[i] = obj._character[j];
    }

    ret._character[len + obj_len] = char('\0');

    return ret;
}


std::ostream & operator <<(std::ostream & outs, const Swbjaw& obj) {

    outs << obj._character;

    return outs;
}
