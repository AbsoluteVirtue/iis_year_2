#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


int pt_func_compare(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}


int main(int argc, char const *argv[])
{
    int c_array [10] = {};
    
    for (size_t i = 0; i < 10; i++)
    {
        c_array[i] = rand() % 100;
    }

    qsort(c_array, 10, sizeof(*c_array), pt_func_compare);
}
