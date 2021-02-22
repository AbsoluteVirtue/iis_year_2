#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "computer.h"

int main(int argc, char const *argv[]) {
    FILE * input = fopen("computer.txt", "r");
    if (input == NULL)
    {
        printf("error: file read");
        return 1;
    }
    FILE * output = fopen("computeroutput.txt", "w");
    if (output == NULL)
    {
        printf("error: file read");
        return 1;
    }
    vector arr_struct;
    arr_struct.create();
    arr_struct.open(input);
    computer test = *arr_struct.first;
    arr_struct.edit(60, test);
    arr_struct.push_back(test);
    arr_struct.insert(20, test);
    arr_struct.del(50);
    arr_struct.sort_price();
    for(arr_struct.position = arr_struct.first; arr_struct.position <= arr_struct.last; arr_struct.position++) 
        arr_struct.output(output);
    for(arr_struct.position = arr_struct.first; arr_struct.position <= arr_struct.last; arr_struct.position++) 
        arr_struct.print();
    arr_struct.clean_up();
    return 0;
}
