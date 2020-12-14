#ifndef __BOOK_H__
#define __BOOK_H__

struct Book;
struct Library;
typedef unsigned short  uint2_t;

struct Book
{
    void clear();
    void fill(const char * a, const char * t, const uint2_t y);
    void print();
    static bool comp(const Book & lhs, const Book & rhs);
private:
    char *author{nullptr};
    char *title{nullptr};
    uint2_t year{2000};
};

struct Library
{
    void push_back(const char * a, const char * t, const uint2_t y);
    void insert(const char * a, const char * t, const uint2_t y, const std::size_t idx);
    void del(const std::size_t idx);
    void clear();
    void print();
    Book * begin();
    Book * end();
private:
    Book * list{nullptr};
    std::size_t length{0};
};

#endif
