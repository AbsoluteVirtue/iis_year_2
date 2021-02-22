#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>
#include <vector>

struct Book
{
    std::string author{""};
    std::string title{""};
    unsigned int year{0};
    unsigned int pages{0};
    unsigned int sales{0};

    void print();
};

void openFile(FILE *file, std::vector<Book *> &arr);
void find_author(std::vector<Book *> arr, std::string author);
bool cmpSales(Book *a, Book *b);
void edit(std::vector<Book *> &arr, size_t idx, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales);
void addToTheEnd(std::vector<Book *> &arr, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales);
void remove(std::vector<Book *> &arr, size_t idx);
void insert(std::vector<Book *> &arr, size_t idx, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales);
void inputFile(FILE *file, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales);
void clearMem(std::vector<Book *> & arr);


#endif