#include <iostream>

using namespace std;


void f1() {
    int a,b,
    *p=&a,
    &r=a;
    // float &c=a;
    const float &d=a;
    // int &c;
    a=3;
    cout<<a<<" "<<r<<" "<<*p<<endl;
    b=r;
    *p=a=--b;
    cout<<a<<" "<<r<<" "<<*p<<endl;   
    // c=b;
    const int *const r1 = &a;
    a++;
    // (*r1)++;
}

// void f(int x, char *s="hello",int y){ cout<<0<<endl;}

void f(double x, char *s){ cout<<x<<" "<<1<<endl;}

void f(double x, const char *s){ cout<<x<<" "<<2<<endl;}

void f(int x, char *s="hello"){ cout<<3<<endl;}

void f(float x, char *s){ cout<<x<<" "<<4<<endl;}

void f(char x, const char *s){ cout<<x<<" "<<5<<endl;}

void f(float x, const char *s){ cout<<x<<" "<<6<<endl;}

void f(int x,double s){ cout<<x<<" "<<7<<endl;}

void f(double x,double s){ cout<<x<<" "<<8<<endl;}

int main(int argc, char const *argv[])
{
    f1();
    cout << "----------------------------" << endl;

    int a=1;
    char h[0];
    float d=.1;
    f(d,"yy");
    f('0');
    f('0',"y");
    f(a);
    f(d);
    f(1.5,"a");
    f(1.5,h);
    f(5.,1.);
    f(1,5);
    f(1.,1);
    // f(1,0);
}

/*
    3 3 3
    2 2 2
    ----------------------------
    0.1 6
    3
    0 5
    3
    3
    1.5 2
    1.5 1
    5 8
    1 7
    1 8
*/