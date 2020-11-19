#include <iostream>
#include <string>
#include <cstring>
#include <vector>


void print(std::string (&matrix)[2][2], size_t M, size_t N) 
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


int main()
{
    std::string B[][2] = {
        {"TI-209", "TI-208"}, 
        {"TI-210", "IA-204"},
    };
    print(B, 2, 2);
}
