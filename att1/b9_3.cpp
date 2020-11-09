#include <iostream>

using namespace std;


class I {
    int i;

public:
    I() : i(0) { 
        cout << "one" <<  i << endl; }
    I(int a) : i(a) { 
        cout << "two " << i << endl; }
    I(const I & other) : i(other.i) { 
        cout << "three " << i << endl; }
    ~I() { 
        cout << "end  "<<i << endl; }
    int Get() { 
        return i; }
    void operator+= (const I & op) { 
        i+=op.i; } 
};

void f(I & x, I y) { 
    y += 1000; 
    x += y; }


int main(int argc, char const *argv[])
{

    I i1; 
    I i2(20);
    i2 += 400;
    f(i1, i2);
    cout << i1.Get() << i2.Get() << endl;

}

/*
    one0
    two 20
    two 400
    end  400
    three 420
    two 1000
    end  1000
    end  1420
    1420420
    end  420
    end  1420
*/
