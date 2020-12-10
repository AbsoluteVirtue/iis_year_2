#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned short uint2_t;

typedef struct book
{
    char *author;
    char *title;
    uint2_t year;
} Book;

void fill(Book * lhs, const char * a, const char * t, const uint2_t y);
int comp(const void * a, const void * b);
void push_back(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx);

int main(int argc, char const *argv[])
{
    #define NO_OF_BOOKS 3

    Book file [NO_OF_BOOKS] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    Book * books = (Book *)malloc(NO_OF_BOOKS * sizeof(Book));
    if (books == NULL){
        return -1;
    }

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        fill(&books[i], file[i].author, file[i].title, file[i].year);
    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    push_back(&books, "Bronte, Emily", "Wuthering Heights", 1850, NO_OF_BOOKS);

    qsort(books, NO_OF_BOOKS + 1, sizeof(Book), comp);

    printf("Sorted array\n");
    for (size_t i = 0; i < NO_OF_BOOKS + 1; i++)
    {    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    free(books);

    return 0;
}

void fill(Book * lhs, const char * a, const char * t, const uint2_t y) 
{
    lhs->author = strdup(a);
    lhs->title = strdup(t);
    lhs->year = y;
}

int comp(const void * a, const void * b) 
{
    return *((Book *)a)->author - *((Book *)b)->author;
}

void push_back(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx) 
{
    *array = (Book *)realloc(*array, (idx + 1) * sizeof(Book));
    if (*array == NULL) 
    {
        exit(-1);
    }
    fill(&(*array)[idx], a, t, y);
}
