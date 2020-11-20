#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>


template <size_t M, size_t N, typename T> void print(T (&matrix)[M][N]) 
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


int _PtFuncCompare(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}

template <typename _K, typename _V> 
struct Test {
    _K _key;
    _V _val;

    friend std::ostream & operator<<(std::ostream & os, const Test<_K, _V> & obj)
    {
        return os << obj._key << " " << obj._val;
    }
};


template <typename T1, typename T2>
class Vector {
    size_t _size = 0;
    Test<T1, T2> * _list = NULL;
public:
    Vector(std::initializer_list<Test<T1, T2>> il) {
        _size = il.size();
        _list = (Test<T1, T2> *)calloc(_size, sizeof(Test<T1, T2>));
        std::copy(il.begin(), il.end(), _list);
    }

    ~Vector() {
        free(_list);
    }

    const size_t size() const {
        return _size;
    }

    Test<T1, T2> * begin() {
        return _list;
    }

    Test<T1, T2> * end() {
        return (_list + _size);
    }

    void push_back(Test<T1, T2> x) {
        Test<T1, T2> * tmp = (Test<T1, T2> *)calloc(_size + 1, sizeof(Test<T1, T2>));
        for(size_t i = 0; i < _size; ++i) 
        {
            tmp[i] = _list[i];
        }
        tmp[_size] = x;
        _size += 1;
        free(_list);
        _list = tmp;
    }

    friend std::ostream & operator<<(std::ostream & os, const Vector<T1, T2> & obj) 
    {
        return os << *(obj.begin());
    }
};


int main()
{
    Vector<int, std::string> v = { {1, "one"}, {2, "two"} };

    v.push_back({100, "100.666"});

    for (auto it : v) {
        std::cout << it << "\t";
    }
}
