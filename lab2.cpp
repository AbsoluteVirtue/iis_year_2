#include <algorithm>
#include <cstring>
#include <iostream>


#define SIZE 2


class Test {
private:
    char * _p {nullptr};

    void _copy_string(const char * _string) {
        _p = new char [strlen(_string) + 1];

        for (int i=0;i < strlen(_string); i++) {
            _p[i] = _string[i];
        }

        _p[strlen(_string)] = '\0';
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

    friend bool operator==(Test & lhs, Test & rhs) {
        return bool(strcmp(lhs._p, rhs._p));
    }

    friend std::ostream & operator<<(std::ostream & os, Test & obj) {
        return os << obj.get_p();
    }

    const char * get_p() const {
        return _p;
    }

    void set_p(const char * source) {
        _nullify_string();
        _copy_string(source);
    }
};


int cmp_int(const void * lhs, const void * rhs) {
    return strcmp(
        ((Test *)lhs)->get_p(),
        ((Test *)rhs)->get_p()
    );
}

bool cmp_bool(Test & lhs, Test & rhs) {
    return lhs == rhs;
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

    Test a = arr[0];

    std::cout << a << std::endl;

    a.set_p("Test");

    std::cout << a << std::endl;

    std::cout << (arr[0] == arr[1]) << std::endl;

    qsort(arr, SIZE, sizeof(*arr), cmp_int);

    print_array(arr, SIZE);

    std::sort(arr, arr + SIZE, cmp_bool);

    print_array(arr, SIZE);

    delete [] arr;

    return 0;
}
