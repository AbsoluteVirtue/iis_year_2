#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


size_t slen(const char * str) {
    size_t i = 0;
    while (str[++i]);
    return i;
}


void scpy(const char * src, char ** dest) {
    size_t len = slen(src);
    *dest = (char *)malloc(len + 1);
    for (size_t i = 0; i < len + 1; i++)
    {
        (*dest)[i] = src[i];
    }
}


int main(int argc, char const *argv[])
{
    const char * p = "test";
    char * t;
    scpy(p, &t);
    std::cout << p << " " << t << std::endl;

    return 0;
}
