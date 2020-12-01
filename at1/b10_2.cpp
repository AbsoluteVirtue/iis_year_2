#include <iostream>

using namespace std;

/*
    0 0 0
    1 1 1
    -----------------------------------
    5
    0 3
    0 6
    5
    0 1
    0 4
    0 3
    0 8
    1 7
    0 8
*/


void f(double x, const char *s){ cout<<x<<" "<<4<<endl;}

void f(int x, char *s="hello"){ cout<<5<<endl;}

void f(float x, char *s){ cout<<x<<" "<<6<<endl;}

void f(char x, const char *s){ cout<<x<<" "<<1<<endl;}

// void f(int x, char *s="hello",int y){ cout<<2<<endl;}

void f(double x, char *s="H"){ cout<<x<<" "<<3<<endl;}

void f(int x,double s){ cout<<x<<" "<<7<<endl;}

void f(double x,double s){ cout<<x<<" "<<8<<endl;}

void f(float x, const char *s){ cout<<x<<" "<<6<<endl;}

void f1() {
    int a,b,
    *p=&a,
    &r=a;
    // float &c=a;
    const float &d=a;
    // int &c;
    a=0;
    cout<<a<<" "<<r<<" "<<*p<<endl;
    b=r++;
    *p=a;
    cout<<a<<" "<<r<<" "<<*p<<endl;   
    // c=b;
    // int &f=2;
    const int &ff=0.99;
    int * const  & r1=p;
    int * const   & r2=0;
}


int main(int argc, char const *argv[])
{

    f1();
    cout<< "-----------------------------------" << endl;

    int a=1.9;
    char h[0];
    float d=0.;
    f(a);
    f(d);
    f(d,"yy");
    f('0');
    f('0',"y");
    f(0.,"a");
    f(0.,h);
    f(0.,0.);
    f(1,1);
    // f(1,0);
    f(0.,1);
}
