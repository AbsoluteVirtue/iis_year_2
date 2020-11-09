#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <list>
#include <vector>


int main(int argc, char const *argv[])
{
    std::vector<int> A = {1, 2, 3, 4, 6};

    A.pop_back();

    srand(time(NULL));
    for(auto it = A.begin(); it != A.end(); ++it) {
        *it = rand() % 100;
        std::cout << *it << "\t";
    }
    std::cout << "\n";

    A.push_back(100);

    for(auto it : A) {
        std::cout << it << "\t";
    }
}
