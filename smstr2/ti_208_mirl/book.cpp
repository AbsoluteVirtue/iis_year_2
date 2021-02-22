#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#include "book.h"

#define LEN 100

void Book::print()
{
    std::cout << this->author << " " << this->title << " " << this->year << " " << this->pages << " " << this->sales << std::endl;
}

// аналог. работы Гагауза

void openFile(FILE *file, std::vector<Book *> &arr)
{
    // файл нужно открывать и закрывать здесь же
    char buffer[LEN] = {};
    while (fgets(buffer, LEN, file))
    {
        const char *delim = ",\"\n";
        char *token = strtok(buffer, delim);

        // пропускаем первую строку
        if (!strcmp(token, "Author"))
            continue;

        Book *tmp = new Book;
        while (token)
        {
            if (tmp->author == "")
            {
                tmp->author = token;
            }
            else if (tmp->title == "")
            {
                tmp->title = token;
            }
            else if (tmp->year == 0)
            {
                tmp->year = atoi(token);
            }
            else if (tmp->pages == 0)
            {
                tmp->pages = atoi(token);
            }
            else if (tmp->sales == 0)
            {
                tmp->sales = atoi(token);
            }
            token = strtok(NULL, delim);
        }
        arr.push_back(tmp);
    }
}

void find_author(std::vector<Book *> arr, std::string author)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i]->author == author)
        {
            arr[i]->print();
            break;
        }
    }
}

bool cmpSales(Book *a, Book *b)
{
    return a->sales < b->sales;
}

void edit(std::vector<Book *> &arr, size_t idx, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales)
{
    size_t len = arr.size(); // зачем переменная, если значение используется только 1 раз
    if (idx <= 0 || idx > len)
    {
        std::cout << "No such element";
    }
    else
    {
        arr[idx - 1]->author = author;
        arr[idx - 1]->title = title;
        arr[idx - 1]->year = year;
        arr[idx - 1]->pages = pages;
        arr[idx - 1]->sales = sales;
    }
}

void addToTheEnd(std::vector<Book *> &arr, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales)
{
    Book *tmp = new Book;
    tmp->author = author;
    tmp->title = title;
    tmp->year = year;
    tmp->pages = pages;
    tmp->sales = sales;
    arr.push_back(tmp);
}

void remove(std::vector<Book *> &arr, size_t idx)
{
    // перед тем как удалить указатель, нужно его освободить 
    arr.erase(arr.begin() + (idx - 1));
}

void insert(std::vector<Book *> &arr, size_t idx, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales)
{
    arr.insert(arr.begin() + (idx - 1), new Book({author, title, year, pages, sales}));
}

void inputFile(FILE *file, std::string author, std::string title, unsigned int year, unsigned int pages, unsigned int sales)
{
    // файл лучше открывать и закрывать в этой функции
    std::string str = author + "," + title + "," + std::to_string(year) + "," + std::to_string(pages) + "," + std::to_string(sales);
    fprintf(file, "\n%s", str.c_str());
}

void clearMem(std::vector<Book *> & arr)
{
    for (auto it : arr)
    {
        delete it;
    }
}