#include <iostream>
#include <string>

using namespace std;

class X { 
    int a, b;

public: 
    X() {};
    X(const X & x){ 
        a = x.a; 
        b = x.b; 
        cout << a << endl; 
    }
    X(float x, int y) {}
    X(int a) { 
        this -> a = a; 
        b = a; 
        cout << b << endl;
    }

};

void f () 
{ 
    X x (1); 
    X y;
    X z = X(2.5, 4);
    X s = 6;
    X w = z;
    s = z = w;
}


int main(int argc, char const *argv[])
{
    f();

    return 0;
}
