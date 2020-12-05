#include <algorithm>
#include <cstring>
#include <iostream>

typedef unsigned short uint8;

struct book
{
    char * title{nullptr};
    char * author{nullptr};
    uint8 year{0};

    void fill(const char * a, const char * t, uint8 y) 
    {
        this->author = new char [strlen(a) + 1];
        if(this->author) 
        {
            strcpy(this->author, a);
        }
        this->title = new char [strlen(t) + 1];
        if(this->title) 
        {
            strcpy(this->title, t);
        }
        this->year = y;
    }

    void clear()
    {
        year = 0;
        delete [] author;
        author = nullptr;
        delete [] title;
        title = nullptr;
    }

    void print() 
    {
        printf("%s \"%s\" (%d)\n", author, title, year);
    }
};


bool comp(const book &a, const book &b) 
{
    return a.year < b.year;
}


int main(int argc, char const *argv[])
{
    book b1, b2;

    b2.fill("Алексей Толстой", "Князь Серебряный", 1900);
    b1.fill("Владимир Маяковский", "Облако в штанах", 1920);

    book * sob =  new book [2];

    sob[0] = b1;
    sob[1] = b2;

    for (size_t i = 0; i < 2; i++)
    {
        sob[i].print();
    }

    std::cout << "\n";
    std::sort(sob, sob + 2, comp);

    for (size_t i = 0; i < 2; i++)
    {
        sob[i].print();
        sob[i].clear();
    }

    delete [] sob; 
}
