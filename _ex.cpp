#include <iostream>
#include <cstring>


using namespace std;


typedef unsigned char byte;


struct Test
{
    int code{0};
    char * name{nullptr};

    void incr();

    void setstr(char * & dest, const char * src);

    // Test(const char * str);
};


// Test::Test(const char * str) {
//     Test::setstr(name, str);
// }


void Test::setstr(char * & dest, const char * src) {
    dest = new char [strlen(src + 1)];
    strcpy(dest, src);
}


void Test::incr() {
    this->code += 1;
}



int main(int argc, char const *argv[])
{
    Test test_obj;

    test_obj.incr();

    return 0;
}
