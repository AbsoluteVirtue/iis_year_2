#include <cstring>
#include <iostream>
#include "book.h"


void Book::fill(const char * a, const char * t, const uint2_t y) 
{
    if (this->author != nullptr)
    {
        delete [] this->author;
    }
    this->author = strdup(a);

    if (this->title != nullptr)
    {
        delete [] this->title;
    }
    this->title = strdup(t);

    this->year = y;
}

void Book::clear()
{
    delete [] this->author;
    this->author = nullptr;

    delete [] this->title;
    this->title = nullptr;

    this->year = 2000;
}

void Book::print() 
{
    std::cout   << this->author << " "
                << this->title << " "
                << this->year << std::endl;
}

bool Book::comp(const Book & lhs, const Book & rhs)
{
    return *lhs.author < *rhs.author;
}

///////////////////////////////////////////////////

Book * Library::begin()
{
    return this->list;
}

Book * Library::end()
{
    return this->list + this->length;
}

void Library::push_back(const char * a, const char * t, const uint2_t y)
{
    Book * tmp = new Book [this->length + 1];
    std::copy(this->begin(), this->end(), tmp);
    delete [] this->list;
    tmp[this->length].fill(a, t, y);
    this->length += 1;
    this->list = tmp;
}

void Library::insert(const char * a, const char * t, const uint2_t y, const std::size_t idx)
{
    if (idx >= this-> length) return;

    this->length += 1;
    Book * tmp = new Book [this->length];

    std::size_t k = 0;
    for (size_t i = 0; i < this->length; ++i)
    {
        if (idx == i)
        {
            tmp[i].fill(a, t, y);
        }
        else 
        {
            tmp[i] = this->list[k++];
        }
    }
    delete [] this->list;
    this->list = tmp;
}

void Library::del(const std::size_t idx)
{
    if (idx >= this->length) return;

    Book * tmp = new Book [this->length - 1];
    size_t k = 0;
    for (size_t i = 0; i < this->length; ++i)
    {
        if (idx == i) 
        {
            this->list[i].clear();
        }
        else
        {
            tmp[k++] = this->list[i];
        }
    }
    delete [] this->list;
    this->length -= 1;
    this->list = tmp;
}

void Library::clear()
{
    for (std::size_t i = 0; i < this->length; ++i)
    {
        this->list[i].clear();
    }
    delete [] this->list;
}

void Library::print()
{
    for (std::size_t i = 0; i < this->length; ++i)
    {
        this->list[i].print();
    }
}
