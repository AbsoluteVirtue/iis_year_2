#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Data.h"

using namespace std;

int standart_Menu;

void Menu()
{
	cout << "Выберите действие: " << endl
		 << "(0) Выход из программы" << endl
		 << "(1) Ввод данных" << endl
		 << "(2) Вывод" << endl
		 << "(3) Изменение" << endl
		 << "(4) Удаление" << endl
		 << "(5) Добавление" << endl
		 << "(6) Сортировка" << endl
		 << "(7) Сохрание" << endl
		 << "Ваш выбор: ";
	cin >> standart_Menu;
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();

	int actions;
	int amountOfData = 0;
	string fileName;

	// почему не массив?
	Data *d = new Data();

	while (standart_Menu != 0)
	{
		switch (standart_Menu)
		{
		case 1:
			system("cls");
			cout << "Ввод вручную или из файла?: ";
			cin >> actions;

			system("cls");
			if (actions == 1)
			{
				DataEntry(d, amountOfData);
			}
			else
			{
				ReadingData(d, amountOfData, "struct.csv");
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfData != 0)
			{
				PrintData(d, amountOfData);
			}
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (amountOfData != 0)
			{
				DataChange(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			if (amountOfData != 0)
			{
				DeleteData(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (amountOfData != 0)
			{
				AddDate(d, amountOfData);
				amountOfData++;
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			if (amountOfData != 0)
			{
				DataSorting(d, amountOfData);
			}
			else
				cout << "Данные пусты" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");

			cout << "Введите название файда: ";
			cin >> fileName;

			if (amountOfData != 0)
			{
				SavingData(d, amountOfData, fileName);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}
