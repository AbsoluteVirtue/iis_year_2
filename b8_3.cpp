#include <iostream>

using namespace std;

/*
    1.521.51.5
*/

class C { 
    int i; 
    double t;

    C( ) { 
        i = t = 1.0; 
        cout << i; }

public:
    C(int k = 0, double r = 1.5) { 
        i = k; 
        t = r; 
        cout << t;
    }
    C(const C & a) { 
        i = a.i; 
        t = a.t; 
        cout << t; 
    }
};


int main(int argc, char const *argv[])
{
    // C a;
    C b(1); 
    C c(1, 2); 
    C d = b; 
    C e = 3;
    b = c = e;

}
