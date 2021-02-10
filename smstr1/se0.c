// gcc -E se0.cpp > pre.i
// gcc -S pre.i
// gcc -c pre.s
// gcc -O pre.o 
// -save-temps

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Hello, world!");
    return 0;
}
