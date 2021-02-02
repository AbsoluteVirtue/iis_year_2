#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>


void sum_r(int & x) 
{
    ++x;
}

void sum_c(int x) 
{
    ++x;
}

void sum_p(int * x) 
{
    ++*x;
}

int main(int argc, char const *argv[])
{
  
    std::vector<int> v = {};

    for (size_t i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    std::cout << "\n";
    std::cout << v.capacity() << "\n";

    for (size_t i = 0; i < 31072; i++)
    {
        v.push_back(i);
    }
    std::cout << v.capacity() << "\n";

    v.push_back(100);

    std::cout << v.capacity() << "\n";
    
    return 0;
}
