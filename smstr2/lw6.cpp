#include <algorithm>
#include <iostream>
#include <ctime>
#include "book.h"


void generate_delim_str(char * tmp, const size_t len, const char delimiter);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const std::size_t STR_LENGTH = 10;

    Library books;

    char tmp_a [STR_LENGTH] = {}, tmp_t [STR_LENGTH] = {};
    for (size_t i = 0; i < 3; ++i)
    {
        generate_delim_str(tmp_a, STR_LENGTH, ',');
        generate_delim_str(tmp_t, STR_LENGTH, 0);
        books.insert(tmp_a, tmp_t, 1900 + rand() % 100, i);
    }
    books.print();

    generate_delim_str(tmp_a, STR_LENGTH, ',');
    generate_delim_str(tmp_t, STR_LENGTH, 0);
    books.push_back(tmp_a, tmp_t, 1900 + rand() % 100);
    
    std::sort(books.begin(), books.end(), Book::comp);

    std::cout << "Sorted array\n";
    books.print();

    books.del(2);

    generate_delim_str(tmp_a, STR_LENGTH, ',');
    generate_delim_str(tmp_t, STR_LENGTH, 0);
    books.insert(tmp_a, tmp_t, 1900 + rand() % 100, 2);

    books.print();

    books.clear();

    return 0;
}

int _get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

void generate_delim_str(char * tmp, const size_t len, const char delimiter)
{
    if (len < 2) return;

    tmp[0] = (char)_get_random_range((int)'A', (int)'Z');

    if (len > 2)
    {
        for (size_t i = 1; i < len - 1; ++i)
        {
            if (delimiter && len > 4 && i == (len / 2) + 1)
            {
                tmp[i] = (char)_get_random_range((int)'A', (int)'Z');
            }
            else if (delimiter && len > 4 && i == (len / 2) - 1)
            {
                tmp[i] = delimiter;
            }
            else if (delimiter && delimiter != ' ' && len > 4 && i == (len / 2))
            {
                tmp[i] = ' ';
            }
            else
            {
                tmp[i] = (char)_get_random_range((int)'a', (int)'z');
            }
        }
    }
    tmp[len - 1] = '\0';
}
