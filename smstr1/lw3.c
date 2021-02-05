#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ROWS 4
#define ROW_LENGTH 4

int _compare(const void *a, const void *b);
void _print_array(int array [NO_OF_ROWS][ROW_LENGTH], size_t rows, size_t cols);

int main(int argc, char const *argv[])
{
    if (argc != (NO_OF_ROWS * ROW_LENGTH) + 1)
    {
        printf("wrong argument count");
        return 1;
    }

    int array[NO_OF_ROWS][ROW_LENGTH] = {
        {(int)atoi(argv[1]), (int)atoi(argv[2]), (int)atoi(argv[3]), (int)atoi(argv[4])},
        {(int)atoi(argv[5]), (int)atoi(argv[6]), (int)atoi(argv[7]), (int)atoi(argv[8])},
        {(int)atoi(argv[9]), (int)atoi(argv[10]), (int)atoi(argv[11]), (int)atoi(argv[12])},
        {(int)atoi(argv[13]), (int)atoi(argv[14]), (int)atoi(argv[15]), (int)atoi(argv[16])},
    };

    size_t total_size = sizeof(array);
    size_t row_size = sizeof(*array);
    size_t item_size = sizeof(*(int *)array);
    size_t array_total_items = (total_size / item_size);

    qsort(array, array_total_items, item_size, _compare);
    _print_array(array, NO_OF_ROWS, ROW_LENGTH);

    int max_repeated_item = 0;
    for (
        int *p = (int *)array + 1;
        p < (int *)array + array_total_items;
        ++p)
    {

        if (*p == *(p - 1))
            max_repeated_item = *p;
    }
    printf("%d ", max_repeated_item);

    int counter = 0;
    for (int i = 0; i < NO_OF_ROWS; ++i)
    {
        int flag = 1;
        for (int j = 0; j < ROW_LENGTH; ++j)
        {
            if (!array[i][j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            counter++;
    }
    printf("%d", counter);

    return 0;
}

int _compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void _print_array(int array [NO_OF_ROWS][ROW_LENGTH], size_t rows, size_t cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", array[i][j]);
        }
    }
}
