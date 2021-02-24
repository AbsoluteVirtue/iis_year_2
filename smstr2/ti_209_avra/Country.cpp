#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "Country.h"

// аналог. работы Гагауза

// должен быть массив указателей
void Country::print()
{
	std::cout << this->name << " " << this->capital << " " << this->area << " " << this->population << " " << this->vvp << std::endl;
}

void open_file(std::ifstream &read_file, std::vector<Country> &country)
{
	// файл лучше открывать здесь
	if (read_file.is_open())
	{
		size_t i = 0;
		size_t place = 0;
		std::string token;
		std::string buf;
		std::string delim = ",";
		std::vector<std::vector<std::string>> out_stream;
		std::string skip = "Name";
		while (getline(read_file, buf, '\n'))
		{
			if (!(buf.find(skip)))
				continue;

			std::vector<std::string> temp;
			while ((place = buf.find(delim)) != std::string::npos)
			{
				token = buf.substr(0, place);
				temp.push_back(token);
				buf.erase(0, place + delim.length());
			}
			Country temp_country;
			out_stream.push_back(temp);
			temp.clear();

			temp_country.name = out_stream[i][0];
			temp_country.capital = out_stream[i][1];
			temp_country.area = atoi(out_stream[i][2].c_str());
			temp_country.population = atoi(out_stream[i][3].c_str());
			temp_country.vvp = atoi(out_stream[i][4].c_str());

			country.push_back(temp_country);
			i++;
		}
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

#pragma region find

void find_name(std::string str, std::vector<Country> country)
{
	for (int i = 0; i < country.size(); ++i)
	{
		if (str == country[i].name)
		{
			country[i].print();
		}
	}
};

void find_capital(std::string str, std::vector<Country> country)
{
	for (int i = 0; i < country.size(); ++i)
	{
		if (str == country[i].capital)
		{
			country[i].print();
		}
	}
};

void find_area(int area, std::vector<Country> country)
{
	for (int i = 0; i < country.size(); ++i)
	{
		if (area == country[i].area)
		{
			country[i].print();
		}
	}
};

void find_population(int population, std::vector<Country> country)
{
	for (int i = 0; i < country.size(); ++i)
	{
		if (population == country[i].population)
		{
			country[i].print();
		}
	}
};

void find_vvp(int vvp, std::vector<Country> country)
{
	for (int i = 0; i < country.size(); ++i)
	{
		if (vvp == country[i].vvp)
		{
			country[i].print();
		}
	}
};

bool cmpByNameUp(const Country &a, const Country &b)
{
	return a.name[0] < b.name[0];
}

bool cmpByNameDown(const Country &a, const Country &b)
{
	return a.name[0] > b.name[0];
}

bool cmpByCapitalUp(const Country &a, const Country &b)
{
	return a.capital[0] < b.capital[0];
}

bool cmpByCapitalDown(const Country &a, const Country &b)
{
	return a.capital[0] > b.capital[0];
}

bool cmpByAreaUp(const Country &a, const Country &b)
{
	return a.area < b.area;
}

bool cmpByAreaDown(const Country &a, const Country &b)
{
	return a.area > b.area;
}

bool cmpByPopulationUp(const Country &a, const Country &b)
{
	return a.population < b.population;
}

bool cmpByPopulationDown(const Country &a, const Country &b)
{
	return a.population > b.population;
}

bool cmpByVvpUp(const Country &a, const Country &b)
{
	return a.vvp < b.vvp;
}

bool cmpByVvpDown(const Country &a, const Country &b)
{
	return a.vvp > b.vvp;
}

void sortMenu(std::vector<Country> &country)
{
	std::cout << "1. Sort by Name Down" << std::endl;
	std::cout << "2. Sort by Name Up" << std::endl;
	std::cout << "3. Sort by Capital Down" << std::endl;
	std::cout << "4. Sort by Capital Up" << std::endl;
	std::cout << "5. Sort by Area Down" << std::endl;
	std::cout << "6. Sort by Area Up" << std::endl;
	std::cout << "7. Sort by Population Down" << std::endl;
	std::cout << "8. Sort by Population Up" << std::endl;
	std::cout << "9. Sort by Vvp Down" << std::endl;
	std::cout << "10. Sort by Vvp Up" << std::endl;

	size_t choose = 0;
	std::cout << "How do you want to sort your list? ";
	std::cin >> choose;
	std::cout << std::endl;
	if (choose == 1)
	{
		std::sort(country.begin(), country.end(), cmpByNameDown);
	}
	if (choose == 2)
	{
		std::sort(country.begin(), country.end(), cmpByNameUp);
	}
	if (choose == 3)
	{
		std::sort(country.begin(), country.end(), cmpByCapitalDown);
	}
	if (choose == 4)
	{
		std::sort(country.begin(), country.end(), cmpByCapitalUp);
	}
	if (choose == 5)
	{
		std::sort(country.begin(), country.end(), cmpByAreaDown);
	}
	if (choose == 6)
	{
		std::sort(country.begin(), country.end(), cmpByAreaUp);
	}
	if (choose == 7)
	{
		std::sort(country.begin(), country.end(), cmpByPopulationDown);
	}
	if (choose == 8)
	{
		std::sort(country.begin(), country.end(), cmpByPopulationUp);
	}
	if (choose == 9)
	{
		std::sort(country.begin(), country.end(), cmpByVvpDown);
	}
	if (choose == 10)
	{
		std::sort(country.begin(), country.end(), cmpByVvpUp);
	}
}

#pragma endregion

void changeElement(size_t place, std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp)
{
	size_t len = country.size(); // зачем переменная, если используется только 1 раз?
	if (place > len || place < 0)
	{
		std::cout << "Incorrect index" << std::endl;
	}
	else
	{
		country[place - 1].name = name;
		country[place - 1].capital = capital;
		country[place - 1].area = area;
		country[place - 1].population = population;
		country[place - 1].vvp = vvp;
	}
}

void pushElement(std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp)
{
	Country temp;
	temp.name = name;
	temp.capital = capital;
	temp.area = area;
	temp.population = population;
	temp.vvp = vvp;
	country.push_back(temp);
}

void deleteElement(size_t place, std::vector<Country> &country)
{
	size_t len = country.size();
	if (place > len || place < 0)
	{
		std::cout << "Incorrect index" << std::endl;
	}
	else
	{
		country.erase(country.begin() + (place - 1));
	}
}

void insertElement(size_t place, std::vector<Country> &country, std::string name, std::string capital, int area, int population, int vvp)
{
	size_t len = country.size();
	if (place > len || place < 0)
	{
		std::cout << "Incorrect index" << std::endl;
	}
	else
	{
		Country temp;
		temp.name = name;
		temp.capital = capital;
		temp.area = area;
		temp.population = population;
		temp.vvp = vvp;
		country.insert(country.begin() + (place - 1), temp);
	}
}

void writeToFile(std::ofstream &write_file, std::string name, std::string capital, int area, int population, int vvp)
{
	write_file << name << "," << capital << "," << area << "," << population << "," << vvp << "," << std::endl;
}
