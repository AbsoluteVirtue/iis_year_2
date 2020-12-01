#include <iostream>
#include <string>

using namespace std;

/*
    20 20 20
    21 21 21
    -----------------------------------
    5
    2 2
    2 6
    5
    0 1
    1.9 4
    1.5 2
    1 8
    1 7
    1 8
*/


void f(char x, const char *s){ cout<<x<<" "<<1<<endl;}

// void f(int x, char *s="hello",int y){ cout<<3<<endl;}

void f(double x, char *s="H"){ cout<<x<<" "<<2<<endl;}

void f(float x, char *s){ cout<<x<<" "<<6<<endl;}

void f(int x,double s){ cout<<x<<" "<<7<<endl;}

void f(double x,double s){ cout<<x<<" "<<8<<endl;}

void f(double x, const char *s){ cout<<x<<" "<<4<<endl;}

void f(int x, char *s="hello"){ cout<<5<<endl;}

void f(float x, const char *s){ cout<<x<<" "<<6<<endl;}

void f1() {
    int a,b,
    *p=&a,
    &r=a;
    // float &c=a;
    const float &d=a;
    // int &c;
    a=20;
    cout<<a<<" "<<r<<" "<<*p<<endl;
    b=r++;
    *p=a;
    cout<<a<<" "<<r<<" "<<*p<<endl;   
    // c=b;
    // int &f=2;
    const int &ff=0.99;
    int * const  & r1=p;
    int * const   & r2=0;2;
}

int main(int argc, char const *argv[])
{
    f1();
    cout<< "-----------------------------------" << endl;

    int a=1;
    char h[0];
    float d=2;

    f(a);
    f(d);
    f(d,"yy");
    f('0');
    f('0',"y");
    f(1.9,"a");
    f(1.5,h);
    f(1.,1.);
    f(1,1);
    // f(1,0);
    f(1.,1);
}
