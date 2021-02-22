#include "Cars.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int _sMenu;
void Menu()
{
    
cout << "Enter your choice:" << endl;
cout<< "(0) Exit of program" << endl;
cout << "(1) Input your date" << endl;
cout << "(2) Output" << endl;
cout << "(3) Change" << endl;
cout<< "(4) Delete" << endl;
cout<< "(5) Add" << endl;
cout<< "(6) Sort" << endl;
cout<< "(7) Save" << endl;
cout << "your choice: ";
cin >> _sMenu;
}

int main() {
//SetConsoleCP(1251); 
//SetConsoleOutputCP(1251);
//setlocale (LC_CTYPE , "rus");
Menu();
int _actions;
int amountOfCars = 0;
string fileName;

Cars* c = new Cars[amountOfCars];

while (_sMenu != 0)
{
switch (_sMenu)
{
case 1:
cout << "Enter by hand or from file?: ";
cin >> _actions;

if (_actions == 1) {
CarsEnter(c, amountOfCars);
}
else
{


ReadingCars(c, amountOfCars, "Ion.csv");
}
Menu();
break;

case 2:
if (amountOfCars != 0) {
Print(c, amountOfCars);
}
else
cout << "Date empty" << endl;
Menu();
break;

case 3:
if (amountOfCars != 0) {
CarsChange(c, amountOfCars);
}
else
cout << "Date empty" << endl;
Menu();
break;

case 4:
if (amountOfCars != 0) {
DeleteCars(c, amountOfCars);
}
else
cout << "Date Empty" << endl;
Menu();
break;

case 5:
if (amountOfCars != 0) {
AddCars(c, amountOfCars);
amountOfCars++;
}
else
cout << "Date empty" << endl;
Menu();
break;

case 6:
if (amountOfCars != 0) {
CarsSort(c, amountOfCars);
}
else
cout << "Date empty" << endl;
Menu();
break;

case 7:
cout << "Enter file name: ";
cin >> fileName;
if (amountOfCars != 0) {
SavingCars(c, amountOfCars, fileName);
}
else
cout << "Date empty" << endl;
Menu();
break;

default:
cout << "Error 888!" << endl;
Menu();
break;
}
}
}