#include <cstring>
#include <iostream>
#include "book.h"


void Book::fill(const char * a, const char * t, const uint2_t y) 
{
    this->author = strdup(a);
    this->title = strdup(t);
    this->year = y;
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
