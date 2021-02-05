#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 10

int _get_random_range(int lower, int upper);
void _print_array(int _a [], int size);
int _compare(const void * a, const void * b);

int main(int argc, char const * argv [])
{    
    if (argc != ARR_LEN + 1)
    {
        printf("wrong argument count");
        return 1;
    }
    
    int array_arg [ARR_LEN] = {};

    for (int i = 0; i < ARR_LEN; ++i)
    {
        array_arg[i] = (int)atoi(argv[i + 1]);
    }

    qsort(array_arg, ARR_LEN, sizeof(*array_arg), _compare);

    _print_array(array_arg, ARR_LEN);

    return 0;
}

int _get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

void _print_array(int _a [], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", _a[i]);
    }
}

int _compare(const void * a, const void * b)
{
    return (*(int *)a - *(int *)b);
}
