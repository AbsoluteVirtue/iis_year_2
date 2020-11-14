#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


struct Example {
    int number;
    char * c_type_string;
    std::string obj_string;
};


void memory(int *** array_pointer_reference, int rows, int columns);
void clear(int ** array_pointer, int rows);
void print(int ** array_pointer, int rows, int columns);

void struct_example();
void menu_example();


int main(int argc, char const *argv[])
{
    struct_example();

    std::cout << "------------------";

    menu_example();

    return 0;
}

void struct_example() 
{
    Example ex = {0, {}, ""};

    char buf[80];

    std::cin >> ex.number >> buf >> ex.obj_string;

    size_t buflen = strlen(buf);

    ex.c_type_string = (char *)malloc(buflen + 1);
    strcpy(ex.c_type_string, buf);

    std::cout << ex.number << "\t" << ex.c_type_string << "\t" << ex.obj_string;
}

void menu_example() 
{
    int ** matrix_pointer = NULL;
    int rows_number = 4, columns_number = 4, option = -1;

    while(option)
    {
        printf("press 1-6 to select corresponding action:\n1. ");
        scanf("%i", &option);
        if (!option) {
            exit(0);
        } else if (!matrix_pointer && option == 1) {
            memory(&matrix_pointer, rows_number, columns_number);
        } else if (matrix_pointer && option == 2) {
            print(matrix_pointer, rows_number, columns_number);
        } else if (matrix_pointer && option == 6) {
            clear(matrix_pointer, rows_number);
        }else {
            printf("invalid input\n");
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
