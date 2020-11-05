#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    int x = 0, y = 0;
    // ввод с клавиатуры - аналог scanf
    std::cin >> x >> y;
    // использование динамического массива из шаблонов STL (standard template library)
    std::vector<int> B = {x, y};
    // использование метода для вывода данных в терминал напрямую из объекта std::cout
    std::cout.operator<<("size: ").operator<<(B.size()).operator<<("\n");
    // использование встроенных указателей (итераторов) для доступа к элементам вектора по адресу
    for (auto it = B.begin(); it != B.end(); ++it)
    {
        std::cout << *it << "\t";
    }
    std::cout << "\n";
    // добавление нового элемента в вектор
    B.push_back(100);

    std::cout << "size: " << B.size() << std::endl;
    // скрытое использование итераторов вектора для доступа к элементам вектора по ссылке
    for (const int elem : B)
    {
        std::cout << elem << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
