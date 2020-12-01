#include <iostream>

using namespace std;


class A {    
    int a, b;
public:
    A() {}
    A(const A & x) {    
        a = x.a;
        b = x.b;
        cout << 1;    
    }
    A(int a) { 
        this -> a = a;
        b = a;
        cout << 2;  
    } 
    A(double x, int a) { 
        this -> a = a;
        b = a;
        cout << 2;  
    }        
};

void f () { 
    A x(1);    
    A y;     
    A z = A(2.5, 4);
    A s = 6;    
    A w = z;     
    x = z = w;      
}


int main(int argc, char const *argv[])
{
    f();
}
