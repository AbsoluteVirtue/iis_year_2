#include <iostream>

using namespace std;

/*
    -10 -10 -10
    -11 -11 -11
    -----------------------------------
    1.9 3
    1
    0.1 6
    1
    0 5
    1.8 4
    1.1 8
    2 7
    1 8
*/


void f(double x, char *s){ cout<<x<<" "<<3<<endl;}

void f(double x, const char *s){ cout<<x<<" "<<4<<endl;}

void f(char x, const char *s){ cout<<x<<" "<<5<<endl;}

// void f(int x, char *s="hello",int y){ cout<<0<<endl;}

void f(int x, const char *s="hello"){ cout<<1<<endl;}

void f(float x, char *s){ cout<<x<<" "<<2<<endl;}

void f(float x){ cout<<x<<" "<<6<<endl;}

void f(int x,double s){ cout<<x<<" "<<7<<endl;}

void f(double x,double s){ cout<<x<<" "<<8<<endl;}

void f1() {
    int a,b,
    *p=&a,
    &r=a;
    // float &c=a;
    const float &d=a;
    // int &c;
    a=-10;
    cout<<a<<" "<<r<<" "<<*p<<endl;
    b=--r;
    *p=a;
    cout<<a<<" "<<r<<" "<<*p<<endl;   
    const int *const r1 = &a;
    a++;
    // r1++;
    // c=b;
}


void f1() {
    int a,b,
    *p=&a,
    &r=a;
    // float &c=a;
    const float &d=a;
    // int &c;
    a=-10;
    cout<<a<<" "<<r<<" "<<*p<<endl;
    b=--r;
    *p=a;
    cout<<a<<" "<<r<<" "<<*p<<endl;   
    const int *const r1 = &a;
    a++;
    // r1++;
    // c=b;
}


int main(int argc, char const *argv[])
{
<<<<<<< HEAD:att1/b8_2.cpp
    f1();
    cout << "----------------------------" << endl;
=======

    f1();

    cout<< "-----------------------------------" << endl;
>>>>>>> eb44ead908889dadd2641675c618c92546cca60f:b8_2.cpp

    int a=1;
    char h[0];
    float d=.1;
    f(1.9,h);
    f(a);
    f(d);
    f('0');
    f('0',"y");
    f(1.8,"a");
    f(1.1,1.);
    f(2,1);
    f(1.,1);
    // f(1,0);

}

/*
    -10 -10 -10
    -11 -11 -11
    ----------------------------
    1.9 3
    1
    0.1 6
    1
    0 5
    1.8 4
    1.1 8
    2 7
    1 8
*/