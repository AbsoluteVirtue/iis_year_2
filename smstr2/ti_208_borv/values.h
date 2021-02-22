#ifndef __LAB_H__
#define __LAB_H__

// включать только те библиотеки, которые используются в самом файле
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct values{
    std::string nation;
    double wave;
    double trad_values;
    double rat_values;
};

void finish_prog();
bool compareByLength(const values &a, const values &);
void delete_elem(std::vector<values> &vec, int pos, int &length);
void redact(std::vector<values> &vec, int pos, int length);
void search(std::vector<values> vec, int length);
void add_end(std::vector<values> &vec, int &length);
void fill_from_file(std::vector<values> &vec, std::ifstream& file, int &length);
void print_vector(std::vector<values> vec, int length);
void sort(std::vector<values> &vec);
void insert_into_file(std::vector<values> &vec, std::ofstream &file_2, int length);

#endif
