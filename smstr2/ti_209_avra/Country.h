#ifndef __LEON_H__
#define __LEON_H__
#include <string>
#include <vector>

struct Country 
{
    std::string name{""};
    std::string capital{""};
    int area{0};
    int population{0};
    int vvp{0};

    void print(); 
};

void open_file(std::ifstream &file, std::vector<Country> &country);
void find_name(std::string str, std::vector<Country> country);
void find_capital(std::string str, std::vector<Country> country);
void find_area(int area, std::vector<Country> country);
void find_population(int population, std::vector<Country> country);
void find_vvp(int vvp, std::vector<Country> country);
void sortMenu(std::vector<Country> &country);
bool cmpByNameUp(const Country &a, const Country &b);
bool cmpByNameDown(const Country &a, const Country &b);
bool cmpByCapitalUp(const Country &a, const Country &b);
bool cmpByCapitalDown(const Country &a, const Country &b);
bool cmpByAreaUp(const Country &a, const Country &b);
bool cmpByAreaDown(const Country &a, const Country &b);
bool cmpByPopulationUp(const Country &a, const Country &b);
bool cmpByPopulationDown(const Country &a, const Country &b);
bool cmpByVvpUp(const Country &a, const Country &b);
bool cmpByVvpDown(const Country &a, const Country &b);
void changeElement(size_t pos, std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp);
void pushElement(std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp);
void deleteElement(size_t pos, std::vector<Country> &country);
void insertElement(size_t pos, std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp);
void writeToFile(std::ofstream &write_file, std::string name, std::string capital, int area, int population, int vvp);

#endif
