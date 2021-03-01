#pragma once

// библиотеки должны быть там, где они используются
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std; // так делать не надо

struct Data
{
	string 
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
