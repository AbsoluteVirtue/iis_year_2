#pragma once

#include <string>

struct Data
{
	std::string 
		Film_title,
		Country,
		Producer,
		Genre;
	int Year;
};

void DataEntry(Data *(&d), int &n);
void ReadingData(Data *(&d), int &n, string fileName);
void PrintData(Data *d, int n);
void DataChange(Data *(&d), int n);
void DeleteData(Data *(&d), int &n);
void Copy(Data *(&d_n), Data *(&d_o), int n);
void Copy(Data &d_n, Data &d_o);
void AddDate(Data *(&d), int &n);
void DataSorting(Data *d, int n);
void SavingData(Data *d, int n, string fileName);
