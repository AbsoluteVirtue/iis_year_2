#include <iostream>
#include <string>

using namespace std;


// void f(int x, char *s="hello", int y){ cout<<0<<endl;}

void f(double x, char *s){ cout<<x<<" "<<1<<endl;}

void f(char x, const char *s){ cout<<x<<" "<<5<<endl;}

void f(float x, const char *s){ cout<<x<<" "<<6<<endl;}

void f(int x,double s){ cout<<x<<" "<<7<<endl;}

void f(double x, const char *s){ cout<<x<<" "<<2<<endl;}

void f(int x, const char *s="hello"){ cout<<3<<endl;}

void f(float x, char *s){ cout<<x<<" "<<4<<endl;}

void f(double x,double s){ cout<<x<<" "<<8<<endl;}


int main(int argc, char const *argv[])
{
    int a=-1;
    char h[0];
    float d=.1;

    f(d, "yy");
    f('0');
    f(1.5,h);
    f(5.,1.);
    f(1,5);
    f('0', "y");
    f(a);
    f(d);
    f(1.5, "a");
    f(1.,1);
    // f(1,0);

    return 0;
}
