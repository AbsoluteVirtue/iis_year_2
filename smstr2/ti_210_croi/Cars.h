// защита от множественного включения?
// лишних библиотек тут быть не должно
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Cars
{
    string _model;
    string _country;
    int _year;
    int _power;
    int _price;
};

void CarsEnter(Cars *(&c), int &n);
void ReadingCars(Cars *(&c), int &n, string fileName);
void Print(Cars *c, int n);
void CarsChange(Cars *(&c), int n);
void DeleteCars(Cars *(&c), int &n);
void Copy(Cars *(&c_n), Cars *(c_o), int n);
void AddCars(Cars *(&c), int &n);
void CarsSort(Cars *c, int n);
void Copy(Cars &c_n, Cars &c_o);
void SavingCars(Cars *c, int n, string fileName);
