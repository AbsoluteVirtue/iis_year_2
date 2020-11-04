#include <iostream>

using namespace std;


class X { 
    int i; double t;
    X(int k) { 
        i = k; 
        t = 0; 
        cout << 1; }
public:
    X(int k, double r = 0) { 
        i = k; 
        t = r; 
        cout << 2; }
    X & operator= (X & a) { 
        i = a.i; 
        t = a.t; 
        cout << 3; 
        return * this; }
    X(const X & a) { 
        i = a.i; 
        t = a.t; 
        cout << 4; } 
};


int main(int argc, char const *argv[])
{
    // X a; 
    // X b(1); 
    X c (2, 3.5); 
    X d = c; 
    X e (6.5, 3);
    c = d = e;
}
