#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>

#include <iostream>


class array {
    size_t _size = 0;
    int * _list = NULL;
public:
    array(size_t len) { // ctor
        _size = len;
        _list = (int *)calloc(len, sizeof(int));
        if (_list == NULL) {
            exit(-1);
        }
    }

    ~array() { // dtor
        free(_list);
    }

    const size_t size() const {
        return _size;
    }

    int * begin() {
        return _list;
    }

    int * end() {
        return (_list + _size);
    }

    void add(int x) {
        int * tmp = (int *)calloc(_size + 1, sizeof(int));
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


int main(int argc, char const *argv[])
{
    array A(10);

    srand(time(NULL));
    for(auto it = A.begin(); it != A.end(); ++it) {
        *it = rand() % 100;
        printf("%d\t", *it);
    }
    printf("\n");

    A.add(100);

    for(auto it : A) {
        printf("%d\t", it);
    }

        const char * s1 = "MI-203";

    std::cout << s1 << "\n";

    char * s2 = (char *)malloc(strlen(s1) + 2);
    strcpy(s2, s1);
    s2[strlen(s1)] = '!';
    s2[strlen(s1) + 1] = '\0';

    std::cout << s2 << "\n";

    free(s2);

    std::string s3 = "MI-203";
    s3 += "!";
    std::cout << s3 << "\n";

}
