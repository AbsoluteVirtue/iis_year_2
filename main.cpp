#include <iostream>
#include <cstring>
#include <string>
#include "swbjaw.h"

using namespace std;


class Coordinates {
    int x {0};
    int y {0};
    char * p {""};

public:
    Coordinates() {
        cout << "default constructor invoked" << endl;
    };
    Coordinates(int _x, int _y, const char * _p) : x(_x), y(_y) {
        if (p != nullptr) {
            p = nullptr;
        }

        int len = strlen(_p); 

        p = new char [len + 1];

        for (int i=0; i < len; i += 1) {
            p[i] = _p[i];
        }
        p[len] = '\0';
    }
    Coordinates(const Coordinates & obj) {
        * this = obj;
    }
    ~Coordinates() {
        delete [] p;
    }
    Coordinates & operator =(const Coordinates & obj) {
        x = obj.x;
        y = obj.y;

        int len = strlen(obj.p); 

        p = new char [len + 1];

        for (int i=0; i < len; i += 1) {
            p[i] = obj.p[i];
        }
        p[len] = '\0';

        return * this;
    }


    void print() {
        cout << "x: " << x << "; y: " << y << endl;
        if (p != nullptr) {
            cout << p << endl;
        }
    }

};


int main(int argc, char const *argv[]) {

    Coordinates c;

    Coordinates coord(1, 2, "hello");

    Coordinates coord_copy(coord);

    Coordinates coord_eq = coord_copy;

    return 0;
}
