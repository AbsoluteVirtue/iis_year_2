#include <algorithm>
#include <cstring>
#include <iostream>


class test
{
    int x{0};
    float y{0};
    std::string s;
public:
    test();
    test(int _x, int _y);
    ~test();
    test operator+(const test & other) const;
    friend std::ostream & operator<<(std::ostream & os, const test & other) {

        return os << other.x << "\t" << other.y << std::endl;
    }
};

test test::operator+(const test & other) const {

    test tmp = test(other.x + x, other.y + y);
    return tmp;
}

test::test(int _x, int _y): x(_x), y(_y)
{

}

test::test()
{

}

test::~test()
{

}



int main(int argc, char const *argv[])
{

    test a = {1, 2};

    test b = {3, 4};

    test c = a + b;

    std::cout << c << "\n" << std::endl;

    return 0;
}
