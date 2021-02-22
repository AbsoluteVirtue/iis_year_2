// защита от множественного включения?
// включать файлы надо там, где они используются
#include <iostream>
#include <fstream>
#include <string>

using namespace std; // так не надо делать

struct Countries {
	string _Country;
	string _Capital;
	int _Area;
	int _Populations;
	int _VVP;
};

void countriesEnter(Countries* (&c), int& n);
void Readingcountries(Countries* (&c), int& n, string nameoffile);
void Print(Countries* c, int n);
void countriesChange(Countries* (&c), int n);
void Deletecountries(Countries* (&c), int& n);
void Copy(Countries* (&c_n), Countries* (c_o), int n);
void Addcountries(Countries* (&c), int& n);
void countriesSort(Countries* c, int n);
void Copy(Countries& c_n, Countries& c_o);
void Savingcountries(Countries* c, int n, string nameoffile);
