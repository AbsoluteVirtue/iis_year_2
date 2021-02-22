#ifndef __NEWLAB7_H__
#define __NEWLAB7_H__

#include <string>

using namespace std;

struct book
{
    string code;
    string autor;
    string name;
    string year_of_create;
    string count_of_pages;
    int edition;
};

void dinamic(book **&arr, size_t cap);
void search_element(book **&arr, size_t cap);
void sort(book **&arr, size_t cap);
void edit_element(book **&arr, size_t cap);
void new_end(book **&arr, int &number);
void delete_element(book **&arr, int &number);
void inserting_element(book **&arr, int &number);
void write_in_file(book **&arr, size_t number);
void read_of_file(book **&arr, size_t number);
void print(book **&arr, size_t number);
void delete_arr(book **&arr);

#endif
