#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

#include "Product.h"

using namespace std;

void dynamic_memory(int & t, Product * & P)
{
	P = new Product[t];
}

Product *enter_keyboard(int t, Product *P)
{
	for (int i = 0; i < t; i++)
	{
		cout << "\n\nEnter the information for " << i + 1 << " product:\n";
		cout << " 1)Name: ";
		cin >> P[i].name;
		cout << " 2)Country: ";
		cin >> P[i].country;
		cout << " 3)Manufacturer: ";
		cin >> P[i].manufacturer;
		cout << " 4)Vender code: ";
		cin >> P[i].vender_code;
		cout << " 5)Price: ";
		cin >> P[i].price;
		cout << "\n\n";
	}
	return P;
}

void search(Product *P, int t)
{
	int f;
	cout << "\n\nWhat product are you interested in?(From 1 to " << t << "): ";
	cin >> f;
	f -= 1;
	cout << "\n\nEnter the item number of the information you are interested in:\n";
	cout << " 1)Name\n";
	cout << " 2)Country\n";
	cout << " 3)Manufacturer\n";
	cout << " 4)Vender code\n";
	cout << " 5)Price\n";
	cout << "Your choise: ";
	cin >> t;
	if (t == 1)
		cout << "Name: " << P[f].name << endl;
	if (t == 2)
		cout << "Country: " << P[f].country << endl;
	if (t == 3)
		cout << "Manufacturer: " << P[f].manufacturer << endl;
	if (t == 4)
		cout << "Vender code: " << P[f].vender_code << endl;
	if (t == 5)
		cout << "Price: " << P[f].price << endl;
	cout << "\n\n";
}

Product *sort_array(Product *P, int t)
{
	int i, j, min;
	Product *tmp = new Product;

	for (i = 0; i < t - 1; i++)
	{
		min = i;

		for (j = i + 1; j < t; j++)
			if (P[j].price < P[min].price)
				min = j;

		if (min != i)
		{
			*tmp = P[i];
			P[i] = P[min];
			P[min] = *tmp;
		}
	}
	delete tmp;
	return P;
}

Product *edit_array(int t, Product *P)
{
	int f;
	cout << "What product would you like to edit?(From 1 to " << t << "): ";
	cin >> f;
	f -= 1;
	cout << "Enter the item you want to edit:\n";
	cout << " 1)Name\n";
	cout << " 2)Country\n";
	cout << " 3)Manufacturer\n";
	cout << " 4)Vender code\n";
	cout << " 5)Price\n";
	cout << "Your choise: ";
	cin >> t;
	if (t == 1)
	{
		cout << "Name of " << f + 1 << " product: ";
		cin >> P[f].name;
	}
	if (t == 2)
	{
		cout << "Country of " << f + 1 << " product: ";
		cin >> P[f].country;
	}
	if (t == 3)
	{
		cout << "Manufacturer of " << f + 1 << " product: ";
		cin >> P[f].manufacturer;
	}
	if (t == 4)
	{
		cout << "Vender code of " << f + 1 << " product: ";
		cin >> P[f].vender_code;
	}
	if (t == 5)
	{
		cout << "Price of " << f + 1 << " product: ";
		cin >> P[f].price;
	}
	cout << "\n\n";
	return P;
}

Product *add(int *t, Product *P)
{
	Product *B;
	*t += 1;
	B = new Product[*t];
	for (int i = 0; i < (*t - 1); i++)
	{
		B[i] = P[i];
	}
	delete[] P;

	cout << "Enter the details of the new item:\n";
	cout << " 1)Name: ";
	cin >> B[*t - 1].name;
	cout << " 2)Country: ";
	cin >> B[*t - 1].country;
	cout << " 3)Manufacturer: ";
	cin >> B[*t - 1].manufacturer;
	cout << " 4)Vender code: ";
	cin >> B[*t - 1].vender_code;
	cout << " 5)Price: ";
	cin >> B[*t - 1].price;
	cout << "\n\n";

	return B;
}

Product *remove_element(int *t, Product *P)
{
	Product *B;
	*t -= 1;
	B = new Product[*t];
	int n;
	cout << "Enter the number of the element to be deleted (from 1 to " << *t + 1 << "): ";
	cin >> n;
	for (int i = 0; i < *t; i++)
	{
		if (i != n)
			B[i] = P[i];

		if (i == n)
			break;
	}
	for (int i = n; i < *t; i++)
	{
		B[i] = P[i + 1];
	}
	delete[] P;
	cout << "\n\n";
	return B;
}

Product *insert_item(int *t, Product *P)
{
	int n, i;
	Product *B;
	cout << "\n\nWhat is the order of the new element? (from 1 to " << *t << "): ";
	cin >> n;
	n -= 1;
	*t += 1;
	B = new Product[*t];
	for (i = 0; i < *t - 1; i++)
	{
		if (i == n)
			break;
		else
			B[i] = P[i];
	}
	cout << "\n\nEnter the details of the new item:\n";
	cout << " 1)Name: ";
	cin >> B[i].name;
	cout << " 2)Country: ";
	cin >> B[i].country;
	cout << " 3)Manufacturer: ";
	cin >> B[i].manufacturer;
	cout << " 4)Vender code: ";
	cin >> B[i].vender_code;
	cout << " 5)Price: ";
	cin >> B[i].price;
	for (int i = n; i < *t - n; i++)
	{
		B[i + 1] = P[i];
	}
	delete[] P;
	cout << "\n\n";
	return B;
}

void write_file(int *t, Product *P)
{

	ofstream fout("output.txt");
	for (int i = 0; i < *t; i++)
		fout << P[i].name << " " << P[i].country << " " << P[i].manufacturer << " " << P[i].vender_code << " " << P[i].price << endl;
	fout.close();
	cout << "\n\n";
}

void enter_file(int *t, Product ** & P)
{
	ifstream fin("input.txt");
	if (!fin.is_open())
	{
		cout << "\n\nFile open error\n";
		return;
	}
	for (int i = 0; i < *t; i++)
	{
		fin >> P[i]->name;
		fin >> P[i]->country;
		fin >> P[i]->manufacturer;
		fin >> P[i]->vender_code;
		fin >> P[i]->price;
	}

	fin.close();
	cout << "\n\n";
}

void display_array(Product *P, int t)
{
	for (int i = 0; i < t; i++)
	{
		cout << "\n\nProduct #" << i + 1;
		cout << "\nName: " << P[i].name;
		cout << "\nCountry: " << P[i].country;
		cout << "\nManufacturer: " << P[i].manufacturer;
		cout << "\nVender code: " << P[i].vender_code;
		cout << "\nPrice: " << P[i].price;
	}
	cout << "\n\n";
}

Product *delete_memory(Product *P, int &t)
{
	delete[] P;
	t = 0;
	cout << "\n\nMemory deleted\n";
	cout << "\n\n";
	return P;
}
