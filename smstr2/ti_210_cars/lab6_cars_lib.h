#ifndef __LAB6_CARS__
#define __LAB6_CARS__

struct kniga
{
    char* avtor{ nullptr };
    char* nazv{ nullptr };
    int god{ 0 };
    char* izdanie{ nullptr };
    int str{ 0 };
    int tir{ 0 };
};

kniga** PushBack(kniga**& library);

void Output(kniga** library);

int StructSize(kniga** library);

void SearchBook(kniga** library);

void DeleteBook(kniga** library);

void SortLibrary(kniga** library);

kniga** finput(kniga**& library);

void EditBook(kniga **& library);

#endif
