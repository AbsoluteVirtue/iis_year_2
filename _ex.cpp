#include <cstring>
#include <iostream>

struct book
{
    char *author;
    char *title;
    unsigned short year;
};


int main(int argc, char const *argv[])
{
    #define NO_OF_BOOKS 3

    book file [NO_OF_BOOKS] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    book * books;

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        std::cout   << books[i].author
                    << books[i].title 
                    << books[i].year << std::endl;
    }
    

    return 0;
}
