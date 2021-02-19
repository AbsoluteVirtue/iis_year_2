#include <iostream>
#include <string>  
#include <sstream>    
#include <vector>
#include <fstream>

#include"Function.h"

void Manual_input(kniga** (&spisok), int(&count))
{
	cout << "������� ���������� ������:  ";
	int tp = 0;
	cin >> tp; if (tp != 0) { count = tp; } else {cout << "error input";}
	spisok = new kniga*[count];
	for (int i = 0; i < count; i++)
	{
		spisok[i] = new kniga;
		cout << "��������� ������ � (" << i + 1 << ") �����" << endl;
		string tmp = {};
		cout << "����� - "; cin >> tmp; if (!tmp.empty()) { spisok[i]->author = tmp; tmp = {}; }
		else { cout << "error input"; return; }
		cout << "������������ - "; cin >> tmp; if (!tmp.empty()) { spisok[i]->name = tmp; tmp = {}; }
		else { cout << "error input"; return; }
		int temp = 0;
		cout << "���� ������� - "; cin >> temp; if (temp != 0) { spisok[i]->year = temp; temp = 0; }
		else { cout << "error input"; return; }
		cout << "���-�� ������� - "; cin >> temp; if (temp != 0) { spisok[i]->pages = temp; temp = 0; }
		else { cout << "error input"; return; }
		cout << "����� - "; cin >> temp; if (temp != 0) { spisok[i]->circulation = temp; temp = 0; }
		else { cout << "error input"; return; }
		cout << endl;

		cout << "������ ������� ���������" << endl;
	}
}

void Search(kniga** (&spisok), int n)
{
	bool flag = 0;
	string str = {};
	cout << "������� ������������ �����" << endl; cin >> str;
	for (int i = 0; i < n; i++)
	{
		if (str == spisok[i]->name)
		{
			cout << "���������� ������" << endl;
			spisok[i]->_print();
			flag = 1; // FIXME: flag++
		}
	}
	if (flag == 0) cout << "������ �� �������";
}

void Sort_Data(kniga** (&spisok), int(&n))
{
	cout << "���������� �� �������������" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (spisok[i]->name[0] > spisok[i + 1]->name[0])
			{
				kniga *tmp = spisok[i];
				spisok[i] = spisok[i + 1];
				spisok[i + 1] = tmp;
			}
		}
	}
	cout << "������ �������������" << endl;
}

void Change_Data(kniga** (&spisok), int(n))
{
	int k;
	cout << "�������� ������� ��� �������������� - ";
	cin >> k;
	k--;
	if (k >= 0 && k <= n)
	{
		cout << "��������� ����� ������ � (" << k + 1 << ") �����" << endl;
		cout << "����� - "; cin >> spisok[k]->author;
		cout << "������������ - "; cin >> spisok[k]->name;
		cout << "���� ������� - "; cin >> spisok[k]->year;
		cout << "���-�� ������� - "; cin >> spisok[k]->pages;
		cout << "����� - "; cin >> spisok[k]->circulation;
		cout << endl;

		cout << "������ ������� ��������" << endl;
	}
}

void Add_end(kniga** (&spisok), int(&n))
{
	kniga** tmp = new kniga*[++n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = new kniga;
		if (i < n - 1)
		{
			tmp[i]->author = spisok[i]->author;
			tmp[i]->name = spisok[i]->name;
			tmp[i]->year = spisok[i]->year;
			tmp[i]->pages = spisok[i]->pages;
			tmp[i]->circulation = spisok[i]->circulation;
		}
		else if (i == n - 1)
		{
			cout << "���� ������ ���������� ��������:" << endl;
			cout << "����� - "; cin >> tmp[n - 1]->author;
			cout << "������������ - "; cin >> tmp[n - 1]->name;
			cout << "���� ������� - "; cin >> tmp[n - 1]->year;
			cout << "���-�� ������� - "; cin >> tmp[n - 1]->pages;
			cout << "����� - "; cin >> tmp[n - 1]->circulation;
			cout << endl;
		}
	}
	Delete_all(spisok, n);
	spisok = tmp;
	system("cls");
	cout << "����� ������� �������� � �����" << endl;
}

void Delete_one(kniga** (&spisok), int(&n))
{
	if (n == 1)
	{
		Delete_all(spisok, n);
		cout << "������ ������" << endl;
		return;
	}
	else
	{
		int k, _n = n;
		cout << "������� ����� ������������ ���������� ��������: ";
		cin >> k;
		k--;
		kniga** tmp = new kniga*[--n];
		if (k < 0 && k > n) cout << "������ �����" << endl;
		else
		{
			for (int i = 0; i < _n; i++)
			{
				if (i != k) { tmp[i] = new kniga; }

				if (i < k)
				{
					tmp[i]->author = spisok[i]->author;
					tmp[i]->name = spisok[i]->name;
					tmp[i]->year = spisok[i]->year;
					tmp[i]->pages = spisok[i]->pages;
					tmp[i]->circulation = spisok[i]->circulation;
				}

				else if (i > k)
				{
					tmp[i - 1]->author = spisok[i]->author;
					tmp[i - 1]->name = spisok[i]->name;
					tmp[i - 1]->year = spisok[i]->year;
					tmp[i - 1]->pages = spisok[i]->pages;
					tmp[i - 1]->circulation = spisok[i]->circulation;
				}
			}
			Delete_all(spisok, n);
			spisok = tmp;
			cout << "������� ������ ������" << endl;
		}
	}
}

void Add_new(kniga** (&spisok), int(&n))
{
	int k;
	cout << "������� ����� ������������ ������������ ��������: "; 
	cin >> k;
	k--;
	if (!(k > 0 && k <= n)) cout << "������ �����" << endl;
	else
	{
		kniga** tmp = new kniga*[++n];
		for (int i = 0; i < n; i++)
		{
			tmp[i] = new kniga;
			if (i < k)
			{
				tmp[i]->author = spisok[i]->author;
				tmp[i]->name = spisok[i]->name;
				tmp[i]->year = spisok[i]->year;
				tmp[i]->pages = spisok[i]->pages;
				tmp[i]->circulation = spisok[i]->circulation;
			}
			else if (i == k)
			{
				cout << "���� ������ ���������� ��������:" << endl;
				cout << "����� - "; cin >> tmp[i]->author;
				cout << "������������ - "; cin >> tmp[i]->name;
				cout << "���� ������� - "; cin >> tmp[i]->year;
				cout << "���-�� ������� - "; cin >> tmp[i]->pages;
				cout << "����� - "; cin >> tmp[i]->circulation;
				cout << endl;
			}
			else
			{
				tmp[i]->author = spisok[i - 1]->author;
				tmp[i]->name = spisok[i - 1]->name;
				tmp[i]->year = spisok[i - 1]->year;
				tmp[i]->pages = spisok[i - 1]->pages;
				tmp[i]->circulation = spisok[i - 1]->circulation;
			}
		}
		Delete_all(spisok, n);
		spisok = tmp;
	}
}

void Recording_Data(kniga** (&spisok), int(&n), string fileName)
{
	ofstream record(fileName, ios::out);
	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << spisok[i]->author << " ";
			record << spisok[i]->name << " ";
			record << spisok[i]->year << " ";
			record << spisok[i]->pages << " ";

			if (i < n - 1)
			{
				record << spisok[i]->circulation << endl;
			}
			else
			{
				record << spisok[i]->circulation;
			}
		}
		record.close();
		cout << "������ ����� ������� ���������";
	}
	else cout << "������ �������� �����";
}

void Reading_Data(kniga** (&spisok), int(&n), string fileName)
{
	int i = 0;
	ifstream reading(fileName);
	if (reading)
	{
		reading >> n;
		spisok = new kniga*[n];

		for (int i = 0; i < n; i++)
		{
			spisok[i] = new kniga;
			reading >> spisok[i]->author;
			reading >> spisok[i]->name;
			reading >> spisok[i]->year;
			reading >> spisok[i]->pages;
			reading >> spisok[i]->circulation;
		}
		cout << "������ �������" << endl;
	}
	else
		cout << "������ �������� �����" << endl;
	reading.close();
}

void Print(kniga** (&spisok), int(n))
{
	for (int i = 0; i < n; i++)
	{
		cout << "������� - " << i + 1 << endl;
		spisok[i]->_print();
		cout << endl;
	}
}

void Delete_all(kniga** (&spisok), int(&n))
{
	if (spisok)
	{
		for (int i = 0; i < n; i++)
		{
			delete spisok[i];
		}
		delete[] spisok;
		n = 0;
	}
}
