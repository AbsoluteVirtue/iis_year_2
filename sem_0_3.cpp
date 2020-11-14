#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


void memory(int *** array_pointer_reference, int rows, int columns);
void clear(int ** array_pointer, int rows);
void print(int ** array_pointer, int rows, int columns);

void menu_example();


int main(int argc, char const *argv[])
{
    menu_example();
    return 0;
}


void menu_example() 
{
    int ** matrix_pointer = NULL;
    int rows_number = 4, columns_number = 4, option = -1;

    while(option)
    {
        printf("press 1-6 to select corresponding action:\n1. memory\n2. print\n6. clear \n0. exit\n");
        scanf("%i", &option);
        if (!option) {
            exit(0);
        } else if (!matrix_pointer && option == 1) {
            memory(&matrix_pointer, rows_number, columns_number);
        } else if (matrix_pointer && option == 2) {
            print(matrix_pointer, rows_number, columns_number);
        } else if (matrix_pointer && option == 6) {
            clear(matrix_pointer, rows_number);
            matrix_pointer = NULL;
        }else {
            printf("invalid input, ");
        }
    }
}

void memory(int *** array_pointer_reference, int rows, int columns) 
{
    *array_pointer_reference = (int **)calloc(rows, sizeof(int *));
    for (size_t i = 0; i < rows; i++)
    {
        (*array_pointer_reference)[i] = (int *)calloc(columns, sizeof(int));
    }
}

void clear(int ** array_pointer, int rows) 
{
    for (size_t i = 0; i < rows; i++)
    {
        free(array_pointer[i]);
    }
    free(array_pointer);
}

void print(int ** array_pointer, int rows, int columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%d\t", array_pointer[i][j]);
        }
        printf("\n");
    }
}
