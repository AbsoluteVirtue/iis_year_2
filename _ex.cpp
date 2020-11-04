#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{

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
