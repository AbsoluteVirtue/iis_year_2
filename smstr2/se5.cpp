// http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.31.9981
// His empirical conclusion is that Treesort is best, followed by Quicksort and Mergesort. 
// Sediment sort, bubble sort, selection sort perform very badly.

// В зависимости от "железа" иногда быстрее скопировать список в массив и применить быстрый алгоритм сортировки, чем сортировать с помощью медленных алгоритмов.
// https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html

#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    std::string * arr = (std::string *)malloc(10 * sizeof(std::string));
    arr[0] = "test";
    std::cout << arr[0];
    free(arr); 
    return 0;
}
