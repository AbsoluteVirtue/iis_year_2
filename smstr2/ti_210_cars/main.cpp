#pragma warning(suppress : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <clocale>
#include "kniga.h"

int y = 5;
int main()
{
    setlocale(0, "");
    kniga** library = nullptr;

    FILE* f;
    char* s = (char*)malloc(100);
    int size = 0;
    f = fopen("lib.txt", "r");
    while (fgets(s,100,f))
    {
        size++;
    }
    free(s);
    fclose(f);
    //fseek(fp, 0, SEEK_SET);

    
    library = finput(library, size);

    Output(library, size);

    DeleteBook(library, size);

    Output(library, size);

    library = PushBack(library, size);

    Output(library, size);

    for (int i = 0; i < size; i++)
    {
        delete [] library[i]->avtor;
        delete [] library[i]->nazv;
        delete [] library[i]->izdanie;
        delete[] library[i];
    }
    
    return 0;
}