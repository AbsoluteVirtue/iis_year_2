#include <ciso646>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>


struct Vector
{
    Vector() = delete;
    Vector(size_t len);
    Vector(std::initializer_list<int> il);
    ~Vector();
    int add(int x);
    int get(size_t index);
    int set(size_t index, int x);
    int norm();
private:
    size_t _size{};
    int * _list{NULL};
};

int main(int argc, char const *argv[])
{
    #define N 10
    srand(time(NULL));

    Vector A(N);

    for (size_t i = 0; i < N; ++i)
    {
        A.set(i, rand() % 100);
        printf("%d\t", A.get(i));
    }
    printf("\n");

    return 0;
}

Vector::~Vector()
{
    if (_list != nullptr)
    {
        free(_list);
    }
}

Vector::Vector(std::initializer_list<int> il)
{
    _size = il.size();
    _list = (int *)calloc(_size, sizeof(int));
    if (_list == NULL)
    {
        throw;
    }
    std::copy(il.begin(), il.end(), _list);
}

Vector::Vector(size_t len)
{
    if (len < 1)
    {
        throw;
    }

    _list = (int *)calloc(len, sizeof(int));
    if (_list == NULL)
    {
        throw;
    }

    _size = len;
}

int Vector::add(int x)
{
    int * tmp = (int *)calloc(_size + 1, sizeof(int));
    if (tmp == NULL)
    {
        return -1;
    }

    std::copy(_list, _list + _size, tmp);
    tmp[_size] = x;

    _size += 1;

    free(_list);

    _list = tmp;

    return 0;
}

int Vector::get(size_t index)
{
    if (_size < 1 or index < 0 or index > _size - 1)
    {
        throw;
    }

    return _list[index];
}

int Vector::set(size_t index, int x)
{
    if (_size < 1 or index < 0 or index > _size - 1)
    {
        return 1;
    }

    _list[index] = x;

    return 0;
}

int Vector::norm()
{
    int sum = 0;
    for (size_t i = 0; i < _size; ++i)
    {
        sum += _list[i];
    }

    return sum;
}
