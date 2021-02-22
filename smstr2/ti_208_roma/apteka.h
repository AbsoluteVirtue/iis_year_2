#ifndef __FUNC_H__
#define __FUNC_H__

#include <string>
#include <vector>

struct apteka{
    std::string nazv;
    std::string address;
    std::string city;
    std::string tel;
};

void print_vec(std::vector<apteka> vec, int length);
void from_file(std::vector<apteka> &vec, std::ifstream &output_file , int &length);
void search_vec(std::vector<apteka> vec, int length);
void add_vec(std::vector<apteka> &vec, int &length);
void delete_vec(std::vector<apteka> &vec, int &length);
void redact_vec(std::vector<apteka> &vec, int length);
void sort_vec(std::vector<apteka> &vec);
bool compare_vec(const apteka &a, const apteka &b);
void record_vec(std::vector<apteka> vec, int length, std::ofstream &input_file);

#endif