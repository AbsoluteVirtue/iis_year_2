#ifndef __BOOK_H__
#define __BOOK_H__

struct Book;

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

#endif
