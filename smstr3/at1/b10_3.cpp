#include <iostream>

using namespace std;

/*
    1  
    2 3
    2 7
    end  7
    3 0
    2 1
    end  1
    end  0
    0 0
    end  0
    end  0
*/

class I { 
    int i;
public:
    I() : i(0) { 
        cout << "1  " << endl; }
    I(int a) : i(a) { 
        cout<<"2 " << i << endl; }
    I(const I & other) : i(other.i) { 
        cout << "3 " << i << endl; }
    ~I() { 
        cout << "end  "<<i << endl; }
    int Get() { 
        return i; }
    void operator*=(const I & op) { 
        i*=op.i; }
};

void f(I x, I & y) {
     x *= 1; 
     y *= x;
}


int main(int argc, char const *argv[])
{
    I i1; 
    I i2(3); 
    i1 *= 7;
    f(i1, i2);
    cout << i1.Get() << ' ' << i2.Get()<< endl;
}
