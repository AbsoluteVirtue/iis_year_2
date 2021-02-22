#include "Countries.h"
#include <iostream>

// аналог. работе Кроитора
using namespace std; // так делать не надо

void countriesEnter(Countries *(&c), int &n)
{
	cout << "Vvedite kol-vo dannih: ";
	cin >> n;

	c = new Countries[n]; // желательно проверять был ли он уже выделен до вызова функции
	for (int i = 0; i < n; i++)
	{
		cout << "Vvedite stranu: ";
		cin >> c[i]._Country;
		cout << "Vvedite stolitsu: ";
		cin >> c[i]._Capital;
		cout << "Vvedite ploshadi: ";
		cin >> c[i]._Area;
		cout << "Vvedite naselenie: ";
		cin >> c[i]._Populations;
		cout << "Vvedite VVP na dushu : ";
		cin >> c[i]._VVP;
		cout << "^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^" << endl;
	}
}

void Readingcountries(Countries *(&c), int &n, string nameoffile)
{
	fstream reading(nameoffile);
	if (reading)
	{
		reading >> n;
		c = new Countries[n];

		for (int i = 0; i < n; i++)
		{
			reading >> c[i]._Country;
			reading >> c[i]._Capital;
			reading >> c[i]._Area;
			reading >> c[i]._Populations;
			reading >> c[i]._VVP;
		}
		cout << "Danie schitani" << endl;
	}
	else
		cout << "Error otkritiea" << endl;

	reading.close(); // это надо внутри if
}

void Print(Countries *c, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dannie " << i + 1 << ":" << endl;
		cout << "Nazvanie strani: " << c[i]._Country << " " << endl;
		cout << "stolitsa: " << c[i]._Capital << endl;
		cout << "ploshadi: " << c[i]._Area << endl;
		cout << "naselenie: " << c[i]._Populations << endl;
		cout << "VVP na dushu: " << c[i]._VVP << endl;
		cout << "^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^_^" << endl;
	}
}

void countriesChange(Countries *(&c), int n)
{
	int b;
	cout << "Vvedite nomer elementa ot 1 do " << n << ": ";
	cin >> b;
	b--;

	if (b >= 0 && b < n)
	{
		cout << "Vvedite stranu: ";
		cin >> c[b]._Country;
		cout << "Vvedite stolitsu: ";
		cin >> c[b]._Capital;
		cout << "Vvedite ploshadi: ";
		cin >> c[b]._Area;
		cout << "Vvedite naselenie: ";
		cin >> c[b]._Populations;
		cout << "Vvedite VVP na dushu: ";
		cin >> c[b]._VVP;
	}
	else
		cout << "Error number" << endl;
}

void Deletecountries(Countries *(&c), int &n)
{
	int b;
	cout << "Vvedite nomer elementa ot 1 do " << n << ": ";
	cin >> b;
	b--;

	if (b >= 0 && b < n)
	{
		// зачем копировать два раза?
		// где delete [] c?
		Countries *buf = new Countries[n];
		Copy(buf, c, n);
		--n;
		c = new Countries[n];
		int q = 0;
		for (int i = 0; i <= n; i++)
		{
			if (i != b)
			{
				c[q] = buf[i];
				++q;
			}
		}
		delete[] buf;
		cout << "Dannie udaleni" << endl;
	}
	else
		cout << "Error number" << endl;
}

void Copy(Countries *(&c_n), Countries *(c_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		c_n[i] = c_o[i];
	}
}

void Addcountries(Countries *(&c), int &n)
{
	Countries *buf;
	buf = new Countries[n];

	Copy(buf, c, n);

	n++;
	c = new Countries[n];

	Copy(c, buf, --n);
	cout << "Vvedite stranu :";
	cin >> c[n]._Country;
	cout << "Vvedite stolitsu: ";
	cin >> c[n]._Capital;
	cout << "Vvedite ploshadi: ";
	cin >> c[n]._Area;
	cout << "Vvedite naselenie: ";
	cin >> c[n]._Populations;
	cout << "Vvedite VVP na dushu: ";
	cin >> c[n]._VVP;

	cout << "Dannie dobavleni" << endl;
	delete[] buf;
}

void countriesSort(Countries *c, int n)
{
	Countries buf;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (c[i]._Country > c[j]._Country)
			{
				Copy(buf, c[j]);
				Copy(c[j], c[i]);
				Copy(c[i], buf);
			}
		}
	}
	cout << "Dannie otsortirovani" << endl;
}

void Copy(Countries &c_n, Countries &c_o)
{
	c_n._Country = c_o._Country;
	c_n._Capital = c_o._Capital;
	c_n._Area = c_o._Area;
	c_n._Populations = c_o._Populations;
	c_n._VVP = c_o._VVP;
}

void Savingcountries(Countries *c, int n, string nameoffile)
{
	ofstream record(nameoffile, ios::out);
	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << c[i]._Country << endl;
			record << c[i]._Capital << endl;
			record << c[i]._Area << " ";
			record << c[i]._Populations << " ";
			record << c[i]._VVP << " ";
		}
	}
	else
		cout << "Error open file" << endl;
	record.close();
}
