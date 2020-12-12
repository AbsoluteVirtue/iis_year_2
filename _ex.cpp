#include <algorithm>
#include <cstring>
#include <iostream>

typedef unsigned short  uint2_t;

struct Book
{
    char *author{nullptr};
    char *title{nullptr};
    uint2_t year{2000};

    void fill(const char * a, const char * t, const uint2_t y);
    void print();
    static bool comp(const Book & lhs, const Book & rhs);
};

void Book::fill(const char * a, const char * t, const uint2_t y) 
{
    author = strdup(a);
    title = strdup(t);
    year = y;
}

void Book::print() 
{
    std::cout   << author << " "
                << title << " "
                << year << std::endl;
}

bool Book::comp(const Book & lhs, const Book & rhs)
{
    return *lhs.author < *rhs.author;
}

void push_back(Book * & array, const char * a, const char * t, const uint2_t y, std::size_t idx) 
{
    Book * tmp = new Book [idx + 1];
    std::copy(array, array + idx, tmp);
    delete [] array;
    tmp[idx].fill(a, t, y);
    array = tmp;
}

int main(int argc, char const *argv[])
{
    #define NO_OF_BOOKS 3

    Book file [NO_OF_BOOKS] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };

    Book * books = new Book [NO_OF_BOOKS];

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        books[i].fill(file[i].author, file[i].title, file[i].year);
        books[i].print();
    }

    push_back(books, "Bronte, Emily", "Wuthering Heights", 1850, NO_OF_BOOKS);
    
    std::sort(books, books + NO_OF_BOOKS + 1, Book::comp);

    std::cout << "Sorted array\n";
    for (size_t i = 0; i < NO_OF_BOOKS + 1; i++)
    {
        books[i].print();
    }

    delete [] books;

    return 0;
}
