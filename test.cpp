#include <algorithm>
#include <cstring>
#include <iostream>


#define SIZE 2


class Test {
private:
    char * _p {nullptr};

    void _copy_string(const char * _string) {
        std::size_t _length = strlen(_string);
        _p = new char [_length + 1];

        for (int i=0;i < _length; i++) {
            _p[i] = _string[i];
        }

        _p[_length] = char('\0');
    }

    void _nullify_string() {
        if (_p != nullptr) {
            delete [] _p;
            _p = nullptr;
        }
    }
public:
    Test() {}

    Test(const char * str) {
        _copy_string(str);
    }

    Test(const Test & obj) {
        *this = obj;
    }

    Test(Test && obj) {
        *this = std::move(obj);
    }

    ~Test() {
        _nullify_string();
    }

    Test & operator =(const Test & obj) {
        _nullify_string();
        _copy_string(obj._p);

        return *this;
    }

    const char * get_p() const {
        return _p;
    }
};


int cmp_int(const void * lhs, const void * rhs) {
    return strcmp(
        ((Test *)lhs)->get_p(),
        ((Test *)rhs)->get_p()
    );
}

bool cmp_bool(Test & lhs, Test & rhs) {
    return strcmp(lhs.get_p(), rhs.get_p());
}

void print_array(const Test * arr, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i].get_p() << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    Test * arr = new Test [SIZE];

    arr[0] = Test("IA-192");
    arr[1] = Test("AI-192");

    qsort(arr, SIZE, sizeof(*arr), cmp_int);

    print_array(arr, SIZE);

    std::sort(arr, arr + SIZE, cmp_bool);

    print_array(arr, SIZE);

    delete [] arr;

    return 0;
}
