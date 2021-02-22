#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "apteka.h"

// должен быть массив указателей
void from_file(std::vector<apteka> &vec, std::ifstream &output_file, int &length)
{
    apteka tmp;
    size_t found_1, found_2;
    std::string str;
    while (getline(output_file, str))
    {
        found_1 = str.find(',');
        found_2 = str.find(',', found_1 + 1);
        tmp.nazv = str.substr(0, found_1);
        tmp.city = str.substr(found_1 + 1, found_2 - found_1 - 1);
        found_1 = str.find(',', found_2 + 1);
        tmp.address = str.substr(found_2 + 1, found_1 - found_2 - 1);
        found_2 = str.size();
        tmp.tel = str.substr(found_1 + 1, found_2 - found_1 - 1);
        vec.push_back(tmp);
        length++;
    }
}

void print_vec(std::vector<apteka> vec, int length)
{
    // vec.size() вместо length
    for (int i = 0; i < length; i++)
    {
        std::cout << i + 1 << " -  " << vec[i].nazv << "  " << vec[i].city << "  " << vec[i].address << "  " << vec[i].tel << std::endl;
    }
}

void search_vec(std::vector<apteka> vec, int length)
{
    // разделять ввод данных и поиск данных
    std::string search;
    std::cout << "Введите название аптеки: ";
    std::cin >> search;
    for (int i = 0; i < length; i++)
    {
        if (vec[i].nazv == search)
        {
            std::cout << i + 1 << " -  " << vec[i].nazv << "  " << vec[i].city << "  " << vec[i].address << "  " << vec[i].tel << std::endl;
        }
    }
}

void add_vec(std::vector<apteka> &vec, int &length)
{
    // разделять ввод данных и сохранение данных
    apteka tmp;
    std::cout << "Введите название новой аптеки: ";
    std::cin >> tmp.nazv;
    std::cout << "Введите город: ";
    std::cin >> tmp.city;
    std::cout << "Введите адрес: ";
    std::cin >> tmp.address;
    std::cout << "Введите телефон: ";
    std::cin >> tmp.tel;
    vec.push_back(tmp);
    length++;
}

void delete_vec(std::vector<apteka> &vec, int &length)
{
    std::cout << "Введите номер строки элемента, который хотите удалить: ";
    int tmp;
    std::cin >> tmp;
    while (tmp <= 0 || tmp > length)
    {
        std::cout << "Вы ввели неправильное значение, попробуйте еще раз: ";
        std::cin >> tmp;
    }
    vec.erase(vec.begin() + tmp - 1, vec.begin() + tmp);
    length--;
}

void redact_vec(std::vector<apteka> &vec, int length)
{
    std::cout << "Введите номер строки элемента, который хотите редактировать: ";
    int tmp;
    std::cin >> tmp;
    while (tmp <= 0 || tmp > length)
    {
        std::cout << "Вы ввели неправильное значение, попробуйте еще раз: ";
        std::cin >> tmp;
    }
    std::cout << tmp + 1 << " -  " << vec[tmp - 1].nazv << "  " << vec[tmp - 1].city << "  " << vec[tmp - 1].address << "  " << vec[tmp - 1].tel << std::endl;
    std::cout << "Что хотите поменять?\n1.Название\n2.Город\n3.Адрес\n4.Телефон\n5.Ничего\n";
    int cmp;
    std::cin >> cmp;
    while (cmp != 5)
    {
        if (cmp == 1)
        {
            std::cout << "Название: ";
            std::cin >> vec[tmp - 1].nazv;
        }
        if (cmp == 2)
        {
            std::cout << "Город: ";
            std::cin >> vec[tmp - 1].city;
        }
        if (cmp == 3)
        {
            std::cout << "Адрес: ";
            std::cin >> vec[tmp - 1].address;
        }
        if (cmp == 4)
        {
            std::cout << "Телефон: ";
            std::cin >> vec[tmp - 1].tel;
        }
        std::cout << "Что хотите поменять еще?\n1.Название\n2.Город\n3.Адрес\n4.Телефон\n5.Ничего\n";
        std::cin >> cmp;
    }
}

void sort_vec(std::vector<apteka> &vec)
{
    // не надо делать функции, которые просто включают в себя вызов другой функции
    std::sort(vec.begin(), vec.end(), compare_vec);
}

bool compare_vec(const apteka &a, const apteka &b)
{
    return a.nazv.size() < b.nazv.size();
}

void record_vec(std::vector<apteka> vec, int length, std::ofstream &input_file)
{
    for (int i = 0; i < length; i++)
    {
        input_file << vec[i].nazv << ", " << vec[i].city << ", " << vec[i].address << ", " << vec[i].tel << std::endl;
    }
}
