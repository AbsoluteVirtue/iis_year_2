#include <algorithm>
#include <iostream>
#include "book.h"


void push_back(Book * & array, const char * a, const char * t, const uint2_t y, size_t idx);

int main(int argc, char const *argv[])
{
    size_t NO_OF_BOOKS = 3;

    Book file [3] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    // TODO: use unique_ptr
    Book * books = new Book [NO_OF_BOOKS];

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        books[i].fill(file[i].author, file[i].title, file[i].year);
        books[i].print();
    }

    push_back(books, "Bronte, Emily", "Wuthering Heights", 1850, NO_OF_BOOKS);
    NO_OF_BOOKS += 1;
    
    std::sort(books, books + NO_OF_BOOKS, Book::comp);

    std::cout << "Sorted array\n";
    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        books[i].print();
    }

    delete [] books;

    return 0;
}

void push_back(Book * & array, const char * a, const char * t, const uint2_t y, std::size_t idx) 
{
    Book * tmp = new Book [idx + 1];
    std::copy(array, array + idx, tmp);
    delete [] array;
    tmp[idx].fill(a, t, y);
    array = tmp;
}
