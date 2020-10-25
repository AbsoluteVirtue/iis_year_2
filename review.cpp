#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>


class Vector {
    std::vector<float> data;
};


struct string_t {
    char * data{nullptr};
};


void setStringWInput(string_t * dest) {

    char * buf = new char[100];
    if (buf == NULL) {
        delete [] buf;
    }

    std::cin >> buf;

    dest->data = new char [strlen(buf) + 1];
    if (dest->data == NULL) {
        delete dest->data;
    }

    strcpy(dest->data, buf);
}


void setString(string_t * dest, const char * src) {

    dest->data = new char [strlen(src) + 1];
    if (dest->data == NULL) {
        delete dest->data;
    }

    strcpy(dest->data, src);
}


void editString(string_t * dest, const char * src) {

    if (dest->data != nullptr and src != nullptr) {
        dest->data = NULL;
    }

    dest->data = new char[strlen(src) + 1];
    if (dest->data == NULL) {
        delete dest->data;
    }

    strcpy(dest->data, src);
}


int main(int argc, char const *argv[])
{

    string_t * strings = new string_t[1];
    if (strings == NULL) {
        return 1;
        delete [] strings;
    }
    setString(&strings[0], "test");

    assert(strlen(strings[0].data) == 0);

    return 0;
}
