#include <iostream>
#include <string>


class integer {
public:
    int value{0};
    std::string name{""};

    integer(void) : value(0), name("") {}

    integer(int num) : value(num) {}

    integer(std::string src) : name(src) {}

    integer(const integer & other): value(other.value), name(other.name) {}

    void set(int num) {

        value = num;
    }

    const integer operator+(const integer & other) {

        return integer(value + other.value);
    }

    integer operator+(int num) {

        return integer(value + num);
    }

    integer & operator++() {
        value += 1;
        return *this;
    }

    integer operator++( int ) {
        integer old(*this);
        value += 1;
        return old;
    }

    friend const integer operator--(integer & num, int);

    friend std::ostream & operator<<(std::ostream & os, const integer & obj) {
        return os << obj.name;
    }

};


class childe : public integer {
    std::string position{""};

public:
    childe(const childe & other) : integer(other), position(other.position) {}
    childe(const integer & other) : integer(other) {}
};


int main(int argc, char const *argv[])
{
    integer a("test");

    std::cout << a << std::endl;

    childe b(a);

    std::cout << b << std::endl;

    return 0;
}
