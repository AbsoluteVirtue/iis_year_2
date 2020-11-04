#include <iostream>
#include <string>

using namespace std;


class A { 
    int i; double t;

    // A(int k) { 
    //     i = k; 
    //     t = 0;
    //     cout << 1;}
public:
    A(int k=0, double r = 0) { 
        i = k; 
        t = r;
        cout << i; }
    A & operator= (A & a) { 
        i = a.i; 
        t = a.t; 
        cout << t; 
        return * this; }
    A(const A & a) { 
        i = a.i; 
        t = a.t; 
        cout << t; } 
};


int main(int argc, char const *argv[])
{

    A a;
    A b(1); 
    A c (0, 3.5); 
    A d = c; 
    A e (6, 3);
    c = d = e;

}
