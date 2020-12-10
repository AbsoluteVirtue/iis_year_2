#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book
{
    char *author;
    char *title;
    unsigned short year;
};


int main(int argc, char const *argv[])
{
    #define NO_OF_BOOKS 3

    struct book file [NO_OF_BOOKS] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    struct book * books;

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        printf("%s \"%s\" (%d)\n", 
                books[i].author, 
                books[i].title, 
                books[i].year);
    }

    return 0;
}
