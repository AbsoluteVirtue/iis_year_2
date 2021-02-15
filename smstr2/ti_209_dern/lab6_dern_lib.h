#include <iostream>
#include <string>  
#include <sstream>  
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

struct kniga
{
	string author = {};
	string name = {};
	int year = 0;
	int pages = 0;
	long int circulation = 0;
	void _print()
	{
		cout << " - " << author << endl;
		cout << " - " << name << endl;
		cout << " - " << year << endl;
		cout << " - " << pages << endl;
		cout << " - " << circulation << endl;
	}
};

void Manual_input(kniga* (&spisok), int(&count));					//(1)
void Search(kniga* (&spisok), int n);								//(2)
void Sort_Data(kniga* (&spisok), int(&n));							//(3)
void Change_Data(kniga* (&spisok), int(n));							//(4)
void Add_end(kniga* (&spisok), int(&n));							//(5)
void Delete_one(kniga* (&spisok), int(&n));							//(6)
void Add_new(kniga* (&spisok), int(&n));							//(7)
void Recording_Data(kniga* (&spisok), int(&n), string fileName);	//(8)
void Reading_Data(kniga* (&spisok), int(&n), string fileName);		//(9)
void Print(kniga* (&spisok), int(n));								//(10)
void Delete_all(kniga* (&spisok), int(&n));							//(11)
