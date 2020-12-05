#include <cstring>
#include <iostream>


typedef unsigned short uint8;

struct book
{
private:
    char * author{nullptr};
    char * title{nullptr};
    unsigned short yop{0};
public:
    void fill(const char * a, const char * t, uint8 y) 
    {
        yop = y;
        author = new char [strlen(a) + 1];
        if (author)
        {
            strcpy(author, a);
        }
        title = new char [strlen(t) + 1];
        if (title)
        {
            strcpy(title, t);
        }
    }

    void print() 
    {
        std::cout   << author 
                    << " \"" << title << "\"" 
                    << " (" << yop << ")\n";
    }

    void clear()
    {
        yop = 0;
        delete [] author;
        author = nullptr;
        delete [] title;
        title = nullptr;
    }

    void change_yop(uint8 y) 
    {
        yop = y;
    }

};

int main(int argc, char const *argv[])
{
    book b1, b2;
    b1.fill("John Milton", "Paradise Lost", 2020);
    b2.fill("James Joyce", "Ulysses", 2019);

    book * sob = new book [2];
    sob[0] = b1;
    sob[1] = b2;

    for (auto i = sob; i != sob + 2; i++)
    {
        i->print();
    }

    b1.change_yop(1965);
    b1.print();
    
    b1.clear();
    b2.clear();
}
