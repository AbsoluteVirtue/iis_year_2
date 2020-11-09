#include <iostream>
#include <string>

using namespace std;

/*
    10262
*/

class X { 
    int a, b;
public: 
    X (const X & x){
        a = x.a;
        b = x.b;
        cout << a; 
    }
    X (int a=0, int b=0) { 
        this -> a = a; 
        b = a; 
        cout << b;
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
