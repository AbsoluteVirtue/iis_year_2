#include <iostream>
#include <string>
#include <cstring>
#include <vector>


class String
{
    char * m{nullptr};
    size_t size{0};
public:
    ~String() 
    {
        free(m);
    }

    String(const char * src) 
    {
        size = strlen(src);
        m = (char *)malloc(size + 1);
        strcpy(m, src);
    }

    friend std::ostream & operator<<(std::ostream & os, String & src)
    {
        return os << src.m;
    }

    String & append(const char * src)
    {
        size_t len = strlen(src);
        char * tmp = (char *)malloc(size + len + 1);
        strcpy(tmp, m);
        strcat(tmp, src);
        free(m);
        m = tmp;
        size += len;
        return *this;
    }
};


template <typename T, size_t M, size_t N> 
void print(T (&matrix)[M][N]) 
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


template <typename T>
class Vector 
{
    size_t _size = 0;
    T * _list = NULL;
public:
    Vector(std::initializer_list<T> il)
    {
        _size = il.size();
        _list = (T *)calloc(_size, sizeof(T));
        std::copy(il.begin(), il.end(), _list);
    }

    ~Vector()
    {
        free(_list);
    }

    const size_t size() const
    {
        return _size;
    }

    T * begin()
    {
        return _list;
    }

    T * end()
    {
        return (_list + _size);
    }

    void push_back(T x)
    {
        T * tmp = (T *)calloc(_size + 1, sizeof(T));
        for(size_t i = 0; i < _size; ++i) 
        {
            tmp[i] = _list[i];
        }
        tmp[_size] = x;
        _size += 1;
        free(_list);
        _list = tmp;
    }
};


int main()
{
    std::string B[][2] = {
        {"TI-209", "TI-208"}, 
        {"TI-210", "IA-204"},
    };
    print(B);

    String s = "IBM-202";

    s.append("!").append("?");

    std::cout << s << "\n";

    Vector<int> v = {1, 4, 5, 11, 12314, 555};
    v.push_back(-100);
    for (auto it : v) {
        std::cout << it << "\t";
    }
}
