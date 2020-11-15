#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


template <typename T>
class queue {
    size_t _size{0};
    T * arr{NULL};

public:
    ~queue() {
        free(arr);
    }
    const size_t size() const {
        return _size;
    }
    void push_back(T x) {
        T * tmp = (T *)calloc(_size + 1, sizeof(T));
        if (tmp == NULL) {
            return;
        }
        for(size_t i = 0; i < _size; ++i) {
            tmp[i] = arr[i];
        }
        tmp[_size] = x;
        free(arr);
        arr = tmp;
        _size += 1;
    }
    void pop_front() {
        if (!_size) {
            return;
        }
        _size -= 1;
        T * tmp = (T *)calloc(_size, sizeof(T));
        if (tmp == NULL) {
            return;
        }
        for(size_t i = 0; i < _size; ++i) {
            tmp[i] = arr[i + 1];
        }
        free(arr);
        arr = tmp;
    }
    const T * begin() const {
        return arr;
    }
    const T * end() const {
        return arr + _size;
    }
};

int pt_func_compare(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}

template <typename T>
T generic_compare(const T * a, const T * b)
{
    return *a - *b;
}

template <typename T, unsigned N, unsigned M>
int string_compare(const T (&a)[N], const T (&b)[M])
{
    return strcmp(a, b);
}


int main(int argc, char const *argv[])
{
    int a = 1, b = 88, r;

    r = generic_compare(&a, &b);

    r = string_compare("test", "hello");

    int c_array [10] = {};
    
    for (size_t i = 0; i < 10; i++)
    {
        c_array[i] = rand() % 100;
    }

    qsort(c_array, 10, sizeof(*c_array), pt_func_compare);

    queue<int> generic_q;

    generic_q.push_back(100);
    generic_q.push_back(200);

    std::cout << generic_q.size() << std::endl;
    for (const int elem : generic_q)
    {
        std::cout << elem << "\t";
    }
}
