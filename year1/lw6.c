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
void insert(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx, size_t size);
void del(Book ** array, const size_t idx, const size_t size);

int main(int argc, char const *argv[])
{
    size_t NO_OF_BOOKS = 3;

    Book file [3] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    Book * books = (Book *)calloc(NO_OF_BOOKS, sizeof(Book));
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
    NO_OF_BOOKS += 1;

    qsort(books, NO_OF_BOOKS, sizeof(Book), comp);

    printf("Sorted array\n");
    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        if (1813 == books[i].year)
        {
            fill(&books[i], "Austen, Jane", "Emma", 1815);
        }
    }
    
    printf("Changed array\n");
    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    del(&books, 2, NO_OF_BOOKS);
    NO_OF_BOOKS -= 1;

    insert(&books, "Austen, Jane", "Pride and Prejudice", 1813, 2, NO_OF_BOOKS);
    NO_OF_BOOKS += 1;

    printf("Resized array\n");
    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        free(books[i].author);
        free(books[i].title);
    }
    free(books);

    return 0;
}

void fill(Book * lhs, const char * a, const char * t, const uint2_t y) 
{
    if (lhs->author != NULL) 
    {
        free(lhs->author);
    }
    lhs->author = strdup(a);

    if (lhs->title != NULL) 
    {
        free(lhs->title);
    }
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
    fill( &(*array)[idx], a, t, y );
}

void insert(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx, size_t size)
{
    size += 1;
    Book * tmp = (Book *)calloc(size, sizeof(Book));
    if (tmp == NULL)
    {
        exit(-1);
    }

    size_t k = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (idx == i)
        {
            fill(&tmp[i], a, t, y);
        }
        else 
        {
            tmp[i] = (*array)[k++];
        }
    }
    free(*array);
    *array = tmp;
}

void del(Book ** array, const size_t idx, const size_t size) 
{
    Book * tmp = (Book *)calloc(size - 1, sizeof(Book));
    if (tmp == NULL)
    {
        exit(-1);
    }

    size_t k = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (idx == i) 
        {
            free((*array)[i].author);
            (*array)[i].author = NULL;

            free((*array)[i].title);
            (*array)[i].title = NULL;

            (*array)[i].year = 0;
        }
        else
        {
            tmp[k++] = (*array)[i];
        }
    }
    free(*array);
    *array = tmp;
}
