#include <iostream>
#include <string>
#include <fstream>

#include "book.h"

using namespace std;

void dinamic(book **&arr, size_t cap)
{
	arr = new book *[cap]; // [cap]
	for (int i = 0; i < cap; i++)
	{
		arr[i] = new book;
	}
}

void search_element(book **&arr, size_t cap)
{
	string ccode;
	cout << "Enter the code of line 4-numbers: ";
	cin >> ccode;
	for (int i = 0; i < cap; i++)
	{
		if (arr[i]->code == ccode)
		{
			cout << arr[i]->code << " " << arr[i]->autor << " " << arr[i]->name << " " << arr[i]->year_of_create << " " << arr[i]->count_of_pages << " " << arr[i]->edition << endl;
		}
	}
}

void sort(book **&arr, size_t cap)
{
	string k;
	for (int i = 0; i <= cap - 1; i++)
	{
		int m = i;
		double s;
		for (int ii = i; ii <= cap - 1; ii++)
		{
			if (arr[m]->edition < arr[ii]->edition)
			{
				m = ii;
			}
		}
		if (m != i)
		{
			k = arr[i]->code;
			arr[i]->code = arr[m]->code;
			arr[m]->code = k;
			k = arr[i]->autor;
			arr[i]->autor = arr[m]->autor;
			arr[m]->autor = k;
			k = arr[i]->name;
			arr[i]->name = arr[m]->name;
			arr[m]->name = k;
			k = arr[i]->year_of_create;
			arr[i]->year_of_create = arr[m]->year_of_create;
			arr[m]->year_of_create = k;
			k = arr[i]->count_of_pages;
			arr[i]->count_of_pages = arr[m]->count_of_pages;
			arr[m]->count_of_pages = k;
			s = arr[i]->edition;
			arr[i]->edition = arr[m]->edition;
			arr[m]->edition = s;
		}
	}
}

void edit_element(book **&arr, size_t cap)
{
	int count;
	cout << "What line are u want to edit? Enter her code: " << endl;
	string line;
	cin >> line;
	for (int i = 0; i < cap; i++)
	{
		if (arr[i]->code == line)
		{
			count = i;
		}
	}
	cout << "Enter the name of edit section: autor / name / year of create / count of pages / edition" << endl;
	string section;
	cin.ignore();
	getline(cin, section);
	if (section.at(0) == 'a')
	{
		cout << "Enter the new information for this section: " << endl;
		getline(cin, arr[count]->autor);
	}
	else
	{
		if (section.at(0) == 'n')
		{
			cout << "Enter the new information for this section: " << endl;
			getline(cin, arr[count]->name);
		}
		else
		{
			if (section.at(0) == 'y')
			{
				cout << "Enter the new information for this section: " << endl;
				getline(cin, arr[count]->year_of_create);
			}
			else
			{
				if (section.at(0) == 'c')
				{
					cout << "Enter the new information for this section: " << endl;
					getline(cin, arr[count]->count_of_pages);
				}
				else
				{
					if (section.at(0) == 'e')
					{
						cout << "Enter the new information for this section: " << endl;
						cin >> arr[count]->edition;
					}
				}
			}
		}
	}
}

void new_end(book **&arr, int &number)
{
	string k = arr[0]->code;
	book **tmp = new book *[number + 1];
	for (int i = 0; i < number + 1; i++)
	{
		tmp[i] = new book;
	}
	for (int i = 0; i < number; i++)
	{
		tmp[i]->code = arr[i]->code;
		tmp[i]->autor = arr[i]->autor;
		tmp[i]->name = arr[i]->name;
		tmp[i]->year_of_create = arr[i]->year_of_create;
		tmp[i]->count_of_pages = arr[i]->count_of_pages;
		tmp[i]->edition = arr[i]->edition;
	}
	delete[] arr; // а где delete каждой книги, если они копируются в новые?
	arr = tmp;
	cout << "enter the new elements" << endl;
	cin >> arr[number]->code;
	cin.ignore();
	getline(cin, arr[number]->autor);
	getline(cin, arr[number]->name);
	getline(cin, arr[number]->year_of_create);
	getline(cin, arr[number]->count_of_pages);
	cin >> arr[number]->edition;
	number++;
	arr[0]->code = k;
}

void delete_element(book **&arr, int &number)
{
	string ccode;
	int m;
	book **tmp = new book *[number - 1];
	for (int i = 0; i < number - 1; i++)
	{
		tmp[i] = new book;
	}
	cout << "Enter the code of line to be removed" << endl;
	cin >> ccode;
	for (int i = 0; i < number - 1; i++)
	{
		if (arr[i]->code == ccode)
		{
			m = i;
		}
	}
	for (int i = 0, s = 0; i < number; i++)
	{
		if (m != i)
		{
			tmp[s]->code = arr[i]->code;
			tmp[s]->autor = arr[i]->autor;
			tmp[s]->name = arr[i]->name;
			tmp[s]->year_of_create = arr[i]->year_of_create;
			tmp[s]->count_of_pages = arr[i]->count_of_pages;
			tmp[s]->edition = arr[i]->edition;
			s++;
		}
		else
		{
			m = -1;
			s = i;
		}
	}
	delete[] arr;
	arr = tmp;
	number--;
}

void inserting_element(book **&arr, int &number)
{
	string ccode;
	int m;
	cout << "After which line to insert a new one? Enter the code of line" << endl;
	cin >> ccode;
	for (int i = 0; i < number; i++)
	{
		if (arr[i]->code == ccode)
		{
			m = i;
		}
	}
	book **tmp = new book *[number + 1];
	for (int i = 0; i < number + 1; i++)
	{
		tmp[i] = new book;
	}
	for (int i = 0, s = 0; i < number + 1; i++)
	{
		if (m + 1 != i)
		{
			tmp[i]->code = arr[s]->code;
			tmp[i]->autor = arr[s]->autor;
			tmp[i]->name = arr[s]->name;
			tmp[i]->year_of_create = arr[s]->year_of_create;
			tmp[i]->count_of_pages = arr[s]->count_of_pages;
			tmp[i]->edition = arr[s]->edition;
			s++;
		}
	}
	delete[] arr;
	arr = tmp;
	cout << "enter the new elements" << endl;
	cin.ignore();
	getline(cin, arr[m + 1]->code);
	getline(cin, arr[m + 1]->autor);
	getline(cin, arr[m + 1]->name);
	getline(cin, arr[m + 1]->year_of_create);
	getline(cin, arr[m + 1]->count_of_pages);
	cin >> arr[m + 1]->edition;
	number++;
}

void write_in_file(book **&arr, size_t number)
{
	ofstream oFile("new file.txt");
	ofstream out;
	out.open("new file.txt");
	for (int i = 0; i < number; i++)
	{
		out << arr[i]->code << " " << arr[i]->autor << " " << arr[i]->name << " " << arr[i]->year_of_create << " " << arr[i]->count_of_pages << " " << arr[i]->edition << endl;
	}
	out.close();
}

void read_of_file(book **&arr, size_t number)
{
	ifstream enter;
	enter.open("newlab6.txt");
	for (int i = 0; i < number; i++)
	{
		int count = 0, words = -1;
		string k = "";
		string ccode;
		getline(enter, ccode);
		for (int l = 0; l < ccode.length(); l++)
		{
			if (count == 2)
			{
				count = 0;
				k = "";
			}
			if (ccode[l] == '"')
			{
				count++;
			}
			if (count == 1 and ccode[l] != '"')
			{
				k = k + ccode[l];
			}
			if (count == 2)
			{
				words++;
				switch (words)
				{
				case 0:
					arr[i]->code = k;
					break;
				case 1:
					arr[i]->autor = k;
					break;
				case 2:
					arr[i]->name = k;
					break;
				case 3:
					arr[i]->year_of_create = k;
					break;
				case 4:
					arr[i]->count_of_pages = k;
					break;
				case 5:
					arr[i]->edition = stoi(k);
					break;
				default:
					break;
				}
			}
		}
	}
}

void print(book **&arr, size_t number)
{
	for (int i = 0; i < number; i++)
	{
		cout << arr[i]->code << " " << arr[i]->autor << " " << arr[i]->name << " " << arr[i]->year_of_create << " " << arr[i]->count_of_pages << " " << arr[i]->edition << endl;
	}
}

void delete_arr(book **&arr)
{
	//FIXME: delete arr[i];
	delete[] arr;
}
