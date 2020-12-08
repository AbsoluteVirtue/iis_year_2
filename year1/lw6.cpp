#include <algorithm>
#include <cstring>
#include <iostream>

typedef unsigned short uint8;

struct book
{
private:
    char * author{nullptr};
    char * title{nullptr};
    uint8 yop{0};
public:
    void fill(const char * a, const char * t, uint8 y) 
    {
        yop = y;

        size_t len_a = strlen(a) + 1;
        author = new char [len_a];
        std::move(a, a + len_a, author);

        size_t len_t = strlen(t) + 1;
        title = new char [len_t];
        std::move(t, t + len_t, title);
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

    static bool comp(const book & lhs, const book & rhs) 
    {
        return *(lhs.author) < *(rhs.author);
    }
};


int main(int argc, char const *argv[])
{
    book b1, b2;

    b1.fill("Milton, John", "Paradise Lost", 2020);
    b2.fill("Joyce, James", "Ulysses", 2019);

    #define N 2

    // TODO: use unique_ptr
    book * sob = new book [N];
    sob[0] = b1;
    sob[1] = b2;

    for (auto i = sob; i != sob + N; i++)
    {
        i->print();
    }

    b1.change_yop(1965);

    std::cout << "\n";
    std::sort(sob, sob + N, book::comp);

    for (auto i = sob; i != sob + N; i++)
    {
        i->print();
        i->clear();
    }
    
    delete [] sob;
}
