#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>

typedef unsigned short uint2;
struct Book
{
    char *author{nullptr};
    char *title{nullptr};
    uint2 year{0};

    void init()
    {
        this->year = 0;
        this->author = nullptr;
        this->title = nullptr;
    }
    int fill(const char * a, const char * t, const uint2 y)
    {
        this->author = strdup(a);
        this->title = strdup(t);
        this->year = y;
    }
    void print() 
    {
        std::cout   << author << " " 
                    << title << " " 
                    << year << std::endl;
    }
    static bool comp(const Book & lhs, const Book & rhs){
        return *lhs.author < *rhs.author;
    }
};

int push_back(Book * & array, const char * a, const char * t, const uint2 y, size_t idx);

int main(int argc, char const *argv[])
{
    #define NO_OF_BOOKS 3

    Book file [NO_OF_BOOKS] = {
        {"Thackeray, William", "The Luck of Barry Lyndon", 1844},
        {"Bronte, Charlotte", "Jane Eyre: An Autobiography", 1847},
        {"Austen, Jane", "Pride and Prejudice", 1813},
    };
    // TODO: use unique_ptr
    Book * books = new Book [NO_OF_BOOKS];

    for (size_t i = 0; i < NO_OF_BOOKS; i++)
    {
        books[i].init();
        books[i].fill(file[i].author,
                        file[i].title,
                        file[i].year);
        books[i].print();
    }

    push_back(books, "Bronte, Emily", "Wuthering Heights", 1850, NO_OF_BOOKS);
    std::cout << "\n";

    std::sort(books, books + NO_OF_BOOKS + 1, Book::comp);

    for (size_t i = 0; i < NO_OF_BOOKS + 1; ++i)
    {
        books[i].print();
    }

    delete [] books;

    return 0;
}

int push_back(Book * & array, const char * a, const char * t, const uint2 y, size_t idx)
{
    Book * tmp = new Book [idx + 1];
    std::copy(array, array + idx, tmp);
    delete [] array;
    tmp[idx].fill(a, t, y);
    array = tmp;
}
