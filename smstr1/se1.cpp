#include <iostream>


class queue {
    size_t _size{0};
    int * arr{NULL};

public:
    ~queue() {
        free(arr);
    }
    const size_t size() const {
        return _size;
    }
    void push_back(int x) {
        int * tmp = (int *)calloc(_size + 1, sizeof(int));
        if (tmp == NULL) {
            return;
        }
        for(int i = 0; i < _size; ++i) {
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
        int * tmp = (int *)calloc(_size, sizeof(int));
        if (tmp == NULL) {
            return;
        }
        for(int i = 0; i < _size; ++i) {
            tmp[i] = arr[i + 1];
        }
        free(arr);
        arr = tmp;
    }
    const int * begin() const {
        return arr;
    }
    const int * end() const {
        return arr + _size;
    }
};


int main(int argc, char const *argv[])
{
    // неявный вызов конструктора по умолчанию
    // (отсутствует в описании класса, поэтому генерируется компилятором)
    queue B;

    B.push_back(100);
    B.push_back(200);

    std::cout << B.size() << std::endl;
    for (const int elem : B)
    {
        std::cout << elem << "\t";
    }
    std::cout << std::endl;

    B.pop_front();

    std::cout << B.size() << std::endl;
    for (const int elem : B)
    {
        std::cout << elem << "\t";
    }

    return 0;
}
