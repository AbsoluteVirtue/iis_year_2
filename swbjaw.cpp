#include <cstddef>
#include <ostream>
#include "swbjaw.h"


std::size_t _strlen(const char* start) {
   const char* end = start;

   while (*end++ != 0);

   return end - start - 1;
}

Swbjaw::Swbjaw() {

    _character = nullptr;

}

Swbjaw::Swbjaw(const char * _string) {

    _copy_string(_string);

}

Swbjaw::Swbjaw(const Swbjaw & obj) {

    _copy_string(obj._character);

}

Swbjaw::~Swbjaw() {

    delete [] _character;
    _character = nullptr;

}

Swbjaw & Swbjaw::operator =(const Swbjaw & obj) {

    if (_character != nullptr) {
        delete [] _character;
        _character = nullptr;
    }

    _copy_string(obj._character);

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

void Swbjaw::_copy_string(const char * _string) {

    std::size_t _length = _strlen(_string);
    _character = new char [_length + 1];

    for (int i=0;i < _length; i++) {
        _character[i] = _string[i];
    }

    _character[_length] = char('\0');

}
