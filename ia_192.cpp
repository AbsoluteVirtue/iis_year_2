#include <algorithm>
#include <cstring>
#include <iostream>


class Test {
private:
    char * p {nullptr};

    void _copy_string(const char * _string) {
        std::size_t _length = strlen(_string);
        p = new char [_length + 1];

        for (int i=0;i < _length; i++) {
            p[i] = _string[i];
        }

        p[_length] = char('\0');
    }
public:
    Test() {}

    Test(const char * str) {
        if (p != nullptr) {
            delete [] p;
            p = nullptr;
        }
        _copy_string(str);
    }

    Test(const Test & obj) {
        *this = obj;
    }

    Test(Test && obj) {
        *this = std::move(obj);
    }

    ~Test() {
        delete [] p;
        p = nullptr;
    }

    Test & operator =(const Test & obj) {
        if (p != nullptr) {
            delete [] p;
            p = nullptr;
        }
        _copy_string(obj.p);

        return *this;
    }

    char * get_p() const {
        return p;
    }
};


int cmp(const void * lhs, const void * rhs) {
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
    Test * arr = new Test [2];

    arr[0] = Test("IA-192");
    arr[1] = Test("AI-192");

    qsort(arr, 2, sizeof(*arr), cmp);

    print_array(arr, 2);

    std::sort(arr, arr + 2, cmp_bool);

    print_array(arr, 2);

    return 0;
}
