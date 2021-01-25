#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned short uint2_t;
typedef struct book
{
    char *author;
    char *title;
    uint2_t year;
} Book;

void init(Book * bp);
void fill(Book * bp, const char * a, const char * t, const uint2_t y);
void push_back(Book ** array, const char * a, const char * t, const uint2_t y, size_t size);
void insert(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx, size_t size);
void del(Book ** array, const size_t idx, const size_t size);
void clear(Book ** array, const size_t size);
void print(Book ** array, const size_t size);

void generate_delim_str(char * tmp, const size_t len, const char delimiter);
void generate_str(char * tmp, const size_t len);
int comp(const void * a, const void * b);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    size_t NO_OF_BOOKS = 3;
    const size_t STR_LENGTH = 10;

    Book * books = (Book *)calloc(NO_OF_BOOKS, sizeof(Book));
    if (books == NULL){
        return -1;
    }

    char tmp_a[STR_LENGTH] = {}, tmp_t[STR_LENGTH] = {};
    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        generate_delim_str(tmp_a, STR_LENGTH, ',');
        generate_delim_str(tmp_t, STR_LENGTH, 0);

        init(&books[i]);
        fill(&books[i], tmp_a, tmp_t, 1900 + (rand() % 100));
    
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title,
                books[i].year);
    }

    generate_delim_str(tmp_a, STR_LENGTH, ',');
    generate_delim_str(tmp_t, STR_LENGTH, 0);
    push_back(&books, tmp_a, tmp_t, 1900 + (rand() % 100), NO_OF_BOOKS);
    NO_OF_BOOKS += 1;

    qsort(books, NO_OF_BOOKS, sizeof(Book), comp);

    printf("Sorted array\n");
    print(&books, NO_OF_BOOKS);

    del(&books, 2, NO_OF_BOOKS);
    NO_OF_BOOKS -= 1;

    generate_delim_str(tmp_a, STR_LENGTH, ',');
    generate_delim_str(tmp_t, STR_LENGTH, 0);
    insert(&books, tmp_a, tmp_t, 1900 + (rand() % 100), 2, NO_OF_BOOKS);
    NO_OF_BOOKS += 1;

    printf("Resized array\n");
    print(&books, NO_OF_BOOKS);

    clear(&books, NO_OF_BOOKS);

    return 0;
}

void init(Book * bp)
{
    bp->author = NULL;
    bp->title = NULL;
    bp->year = 2000;
}

void print(Book ** array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {    
        printf("%s \"%s\" (%d)\n", 
                (*array)[i].author, 
                (*array)[i].title,
                (*array)[i].year);
    }
}

void clear(Book ** array, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if ((*array)[i].author)
        {
            free((*array)[i].author);
        }
        if ((*array)[i].title)
        {
            free((*array)[i].title);
        }
    }
    free(*array);
}

void fill(Book * bp, const char * a, const char * t, const uint2_t y) 
{
    if (bp->author != NULL) 
    {
        free(bp->author);
    }
    bp->author = strdup(a);

    if (bp->title != NULL) 
    {
        free(bp->title);
    }
    bp->title = strdup(t);

    bp->year = y;
}

int comp(const void * a, const void * b) 
{
    return *((Book *)a)->author - *((Book *)b)->author;
}

void push_back(Book ** array, const char * a, const char * t, const uint2_t y, size_t size) 
{
    *array = (Book *)realloc(*array, (size + 1) * sizeof(Book));
    if (*array == NULL) 
    {
        exit(-1);
    }
    init(&(*array)[size]);
    fill(&(*array)[size], a, t, y);
}

void insert(Book ** array, const char * a, const char * t, const uint2_t y, size_t idx, size_t size)
{
    if (idx >= size) return;

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
            init(&tmp[i]);
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
    if (idx >= size) return;

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

int _get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

void generate_delim_str(char * tmp, const size_t len, const char delimiter)
{
    if (len < 2) return;

    tmp[0] = (char)_get_random_range((int)'A', (int)'Z');

    if (len > 2)
    {
        for (size_t i = 1; i < len - 1; ++i)
        {
            if (delimiter && len > 4 && i == (len / 2) + 1)
            {
                tmp[i] = (char)_get_random_range((int)'A', (int)'Z');
            }
            else if (delimiter && len > 4 && i == (len / 2) - 1)
            {
                tmp[i] = delimiter;
            }
            else if (delimiter && delimiter != ' ' && len > 4 && i == (len / 2))
            {
                tmp[i] = ' ';
            }
            else
            {
                tmp[i] = (char)_get_random_range((int)'a', (int)'z');
            }
        }
    }
    tmp[len - 1] = '\0';
}

void generate_str(char * tmp, const size_t len)
{
    if (len < 2) return;

    tmp[0] = (char)_get_random_range((int)'A', (int)'Z');

    if (len > 2) {
        for (size_t i = 1; i < len - 1; ++i)
        {
            tmp[i] = (char)_get_random_range((int)'a', (int)'z');
        }
    }
    tmp[len - 1] = '\0';
}
