#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

struct Test {
    char * p {nullptr};

    Test() {}

    Test(const char * str) {

        p = new char [strlen(str) + 1];

        for (int i=0;i < strlen(str); i++) {
            p[i] = str[i];
        }

        p[strlen(str)] = char('\0');
    }

    ~Test() {
        delete [] p;
    }
};


int cmp(const void * lhs, const void * rhs) {
    return strcmp(((Test *)lhs)->p, ((Test *)rhs)->p);
}

bool cmp_bool(Test & lhs, Test & rhs) {
    return strcmp(lhs.p, rhs.p);
}

void print_array(const Test * arr, const int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i].p << std::endl;
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
