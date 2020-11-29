#include <cstring>
#include <iostream>
#include <vector>

////////////////////////////////////////////

struct Foo
{
    Foo()
    {
        std::cout << "a";
    }
    Foo(const Foo &)
    {
        std::cout << "b";
    }
};

void q1()
{
    std::vector<Foo> bar(5);
}

/////////////////////////////////////////////

class A
{
public:
    void f()
    {
        std::cout << "A";
    }
};

class B : public A
{
public:
    void f()
    {
        std::cout << "B";
    }
};

void g(A &a)
{
    a.f();
}

void q2()
{
    B b;
    g(b);
}

/////////////////////////////////////

template <size_t N> // or declare N as a global var
void print(const std::string (&A)[N])
{
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << A[i];
    }
}

void q3()
{
    std::string a[] = {"A", "B", "C"};
    print(a);
}

///////////////////////////////////////

void allocate(std::string ***A, size_t M, size_t N)
{
    *A = new std::string *[M];
    for (size_t i = 0; i < M; ++i)
    {
        (*A)[i] = new std::string[N];
    }
}

void q4()
{
    std::string **a = nullptr;
    allocate(&a, 10, 20);
}

///////////////////////////////////////////

int compare(const void *a, const void *b)
{
    return (strlen((char *)a) - strlen((char *)b));
}

void q5()
{
    char *a[] = {"Alpha", "Bravo", "Charlie"};
    qsort(a, 3, sizeof(char *), compare);
}

///////////////////////////////////////////

int main(int argc, char const *argv[])
{
    return 0;
}
