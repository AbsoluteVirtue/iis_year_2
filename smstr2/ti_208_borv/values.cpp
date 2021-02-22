#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "values.h"

// аналог. работе Романюка

// должен быть массив указателей
void fill_from_file(std::vector<values> &vec, std::ifstream& file, int &length)
{
    // vec.size() вместо length
    values tmp;
    size_t found_1, found_2;
    std::string str;
    while(getline(file, str))
    {   
        found_1 = str.find(',');
        found_2 = str.find(',', found_1+1);
        tmp.nation = str.substr(0, found_1);
        tmp.wave = std::stod(str.substr( found_1 + 1, found_2 - found_1 - 1));
        found_1 = str.find(',', found_2+1);
        tmp.trad_values = std::stod(str.substr( found_2 + 1, found_1 - found_2 - 1)); 
        found_2 = str.size();
        tmp.rat_values = std::stod(str.substr(found_1 +1, found_2 - found_1 - 1));
        vec.push_back(tmp);
        length++;
    }
}

void add_end(std::vector<values> &vec, int &length)
{
    // ввод данных отделять от сохранения данных
    values tmp;
    std::cout <<"Введите название страны - ";
    std::cin >> tmp.nation;
    std::cout <<"Введите номер волны - ";
    std::cin >> tmp.wave;
    std::cout <<"Введите индекс традиционных культур - ";
    std::cin >> tmp.trad_values;
    std::cout <<"Введите индекс инных культур - ";
    std::cin >> tmp.rat_values;
    vec.push_back(tmp);
    length++;
}

void search(std::vector<values> vec, int length)
{
    std::string nation;
    bool found = false;
    std::cout<<"Введите название страны - ";
    std::cin >> nation; 
    int i = 0;
    while(i != length)
    {
        if(vec[i].nation == nation)
        {
            std::cout << i+1 <<" - " << vec[i].nation <<"  "<< vec[i].wave <<"  "<< vec[i].trad_values <<"  "<< vec[i].rat_values<<std::endl;
            found = true;
        }
        i++;
    }
    if(found != true)
    {
        std::cout << "Элемента с таким названием не было найдено"<<std::endl;
    }
}

void redact(std::vector<values> &vec, int pos, int length)
{
    if(pos < 0 || pos > length)
    {
        std::cout << "Элемента с такой позицией нет в нашей базе"<<std::endl;
    }
    else
    {
        int choice = 0;
        std::cout << pos <<" элемент - "<<vec[pos-1].nation<<"  "<<vec[pos-1].wave <<"  "<<vec[pos-1].trad_values<<"  "<<vec[pos-1].rat_values<<std::endl;
        std::cout <<"Что вы хотите изменить в "<< pos <<" элементе:\n1.Страну\n2.Номер волны\n3.Индекс традиционой культуры\n4.Индекс инных культур\n5.Ничего"<<std::endl;
        std::cin >> choice;
        {
            while(choice > 5 || choice < 1)
            {
                std::cout <<"Вы ввели невозможное значение, введите еще раз - ";
                std::cin >> choice;
            }
        }
        while(choice != 5)
        {
            if(choice == 1)
            {
                std::string tmp;
                std::cout <<"Введите новое название страны - "; 
                std::cin >> tmp;
                vec[pos-1].nation = tmp;
            }
            if(choice == 2)
            {
                double tmp;
                std::cout <<"Введите новый номер волны - ";
                std::cin >> tmp;
                vec[pos-1].wave = tmp;
            }
            if(choice == 3)
            {
                double tmp;
                std::cout <<"Введите новый нидекс традициональных культур - ";
                std::cin >> tmp;
                vec[pos-1].trad_values = tmp;
            }
            if(choice == 4)
            {
                double tmp;
                std::cout <<"Введите новый индекс инных культур - ";
                std::cin >> tmp;
                vec[pos-1].rat_values = tmp;
            }
            std::cin >> choice;
            while(choice > 5 || choice < 1)
            {
                std::cout <<"Вы ввели невозможное значение, введите еще раз - ";
                std::cin >> choice;
            }
        }
    }
    
}

void print_vector(std::vector<values> vec, int length)
{
    int i = 0;
    while(i != length)
    {
        std::cout << i+1 << " -  " << vec[i].nation << "  " << vec[i].wave << "  " << vec[i].trad_values << "  " << vec[i].rat_values << std::endl;
        i++;
    }
}

void delete_elem(std::vector<values> &vec, int pos, int &length)
{   
    vec.erase(vec.begin()+pos-1, vec.begin()+pos); // зачем диапазон?
    length--;
}

void sort(std::vector<values> &vec)
{
    // не надо делать функции, которые просто вызывают другую функцию
    std::sort(vec.begin(), vec.end(), compareByLength);
}

bool compareByLength(const values &a, const values &b)
{
    return a.nation.size() < b.nation.size();
}

void finish_prog()
{
    exit(0);
}

void insert_into_file(std::vector<values> &vec, std::ofstream& file_2, int length)
{
    // файл, в который пишется, нужно открывать в этой же функции
    for (int i = 0; i < length ; i++)
	{
	    file_2 << vec[i].nation <<", " << vec[i].wave <<", " << vec[i].trad_values<<", " << vec[i].rat_values << std::endl;
	}
}