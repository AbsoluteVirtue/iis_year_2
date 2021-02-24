#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

#include "flight.h"

using namespace std; // !!!

void DynamicMemory(flight **&Array, int &a)
{
	FILE *input = fopen("avia.csv", "r"); // не надо хард-кодить название файла
	char line[255] = {};
	while (fgets(line, 100, input))
	{
		a++;
	}
	Array = new flight *[a];
}

void fileread(flight **&Array)
{
	char line[100] = {};
	int i = 0;
	FILE *input = fopen("avia.csv", "r");
	while (fgets(line, 100, input))
	{
		const char *delim = ",\"\n";
		char *token = strtok(line, delim);
		flight *tmp = new flight;
		while (token != NULL)
		{
			tmp->number = token;
			token = strtok(NULL, delim);
			tmp->destination = token;
			token = strtok(NULL, delim);
			tmp->departing_time = token;
			token = strtok(NULL, delim);
			tmp->arriving_time = token;
			token = strtok(NULL, delim);
			tmp->cost = token;
			token = strtok(NULL, delim);
		}
		Array[i] = tmp;
		i++;
	}
}

void SearchSchedule(flight **&Array, int a)
{
	int choice = 0;
	std::string n;
	int flag = 0;
	while (1)
	{
		choice = 0;
		cout << "Vvedite chto jelaete naiti" << endl;
		cout << "1. Nomer" << endl;
		cout << "2. Napravlenie" << endl;
		cout << "3. Vremea Otpravki" << endl;
		cout << "4. Vremea Pribitia" << endl;
		cout << "5. Cena" << endl;
		cin >> choice;
		if ((choice < 1) || (choice > 5))
			cout << "vvedite nomer iz reada" << endl;
		else
			break;
	}
	if (choice == 1)
	{
		while (flag != 1)
		{
			cout << "Vvedite vash nomer marshruta" << endl;
			cin >> n;
			int i = 0;
			for (; i < a; i++)
			{
				if (Array[i]->number == n)
				{
					// повторяющиеся куски кода лучше выносить в отдельные функции
					std::string k;
					k = Array[i]->cost;
					k = Array[i]->arriving_time + "," + k;
					k = Array[i]->departing_time + "," + k;
					k = Array[i]->destination + "," + k;
					k = Array[i]->number + "," + k;
					cout << k << endl;
					flag++;
					break;
				}
			}
			if (flag != 1)
				cout << "Netu takogo Nomera! Vvedite eshe raz" << endl;
		}
	}
	if (choice == 2)
	{
		while (flag != 1)
		{
			cout << "Vvedite vashe napravlenie" << endl;
			cin >> n;
			int i = 0;
			for (; i < a; i++)
			{
				if (Array[i]->destination == n)
				{
					std::string k;
					k = Array[i]->cost;
					k = Array[i]->arriving_time + "," + k;
					k = Array[i]->departing_time + "," + k;
					k = Array[i]->destination + "," + k;
					k = Array[i]->number + "," + k;
					cout << k << endl;
					flag++;
					break;
				}
			}
			if (flag != 1)
				cout << "Netu takogo Napravlenia! Vvedite eshe raz" << endl;
		}
	}
	if (choice == 3)
	{
		while (flag != 1)
		{
			cout << "Vvedite vashe vreamea otpravki" << endl;
			cin >> n;
			int i = 0;
			for (; i < a; i++)
			{
				if (Array[i]->departing_time == n)
				{
					std::string k;
					k = Array[i]->cost;
					k = Array[i]->arriving_time + "," + k;
					k = Array[i]->departing_time + "," + k;
					k = Array[i]->destination + "," + k;
					k = Array[i]->number + "," + k;
					cout << k << endl;
					flag++;
					break;
				}
			}
			if (flag != 1)
				cout << "Netu takogo! Vvedite eshe raz" << endl;
		}
	}
	if (choice == 4)
	{
		while (flag != 1)
		{
			cout << "Vvedite vashe vremea pribitia marshruta" << endl;
			cin >> n;
			int i = 0;
			for (; i < a; i++)
			{
				if (Array[i]->arriving_time == n)
				{
					std::string k;
					k = Array[i]->cost;
					k = Array[i]->arriving_time + "," + k;
					k = Array[i]->departing_time + "," + k;
					k = Array[i]->destination + "," + k;
					k = Array[i]->number + "," + k;
					cout << k << endl;
					flag++;
					break;
				}
			}
			if (flag != 1)
				cout << "Netu takogo! Vvedite eshe raz" << endl;
		}
	}
	if (choice == 5)
	{
		while (flag != 1)
		{
			cout << "Vvedite vashu cenu marshruta" << endl;
			cin >> n;
			int i = 0;
			for (; i < a; i++)
			{
				if (Array[i]->cost == n)
				{
					std::string k;
					k = Array[i]->cost;
					k = Array[i]->arriving_time + "," + k;
					k = Array[i]->departing_time + "," + k;
					k = Array[i]->destination + "," + k;
					k = Array[i]->number + "," + k;
					cout << k << endl;
					flag++;
					break;
				}
			}
			if (flag != 1)
				cout << "Netu takogo! Vvedite eshe raz" << endl;
		}
	}
}

void PrintStruct(flight **&Array, int a)
{
	for (int i = 0; i < a; i++)
	{
		std::string n;
		n = Array[i]->cost;
		n = Array[i]->arriving_time + "," + n;
		n = Array[i]->departing_time + "," + n;
		n = Array[i]->destination + "," + n;
		n = Array[i]->number + "," + n;
		cout << n << endl;
	}
}

#pragma region sort

//Компаратор для Сортировки номер полета по названию по возрастанию
bool compareAscendingNumber(flight *lhs, flight *rhs)
{
	return lhs->number < rhs->number;
}
//Компаратор для Сортировки номер полета по названию по убыванию
bool compareDescendingNumber(flight *lhs, flight *rhs)
{
	return lhs->number > rhs->number;
}
//Компаратор для Сортировки направления полета по возрастанию
bool compareAscendingDestination(flight *lhs, flight *rhs)
{
	return lhs->destination < rhs->destination;
}
//Компаратор для Сортировки направления полета по убыванию
bool compareDescendingDestination(flight *lhs, flight *rhs)
{
	return lhs->destination > rhs->destination;
}
//Компаратор для Сортировки времени начала полета по возрастанию
bool compareAscendingDepTime(flight *lhs, flight *rhs)
{
	return lhs->departing_time < rhs->departing_time;
}
//Компаратор для Сортировки времени начала полета по убыванию
bool compareDescendingDepTime(flight *lhs, flight *rhs)
{
	return lhs->departing_time > rhs->departing_time;
}
//Компаратор для Сортировки времени конца полета по возрастанию
bool compareAscendingArrTime(flight *lhs, flight *rhs)
{
	return lhs->arriving_time < rhs->arriving_time;
}
//Компаратор для Сортировки времени конца полета по убыванию
bool compareDescendingArrTime(flight *lhs, flight *rhs)
{
	return lhs->arriving_time > rhs->arriving_time;
}
//Компаратор для Сортировки цены полета по возрастанию
bool compareAscendingCost(flight *lhs, flight *rhs)
{
	return lhs->cost < rhs->cost;
}
//Компаратор для Сортировки цены полета по убыванию
bool compareDescendingCost(flight *lhs, flight *rhs)
{
	return lhs->cost > rhs->cost;
}

void ScheduleSort(flight **&Array, int a)
{
	int ad;
	while (1)
	{
		ad = 0;
		cout << "Kak Sortirovati?" << endl;
		cout << "1. Vozrastanie po nomeru" << endl;
		cout << "2. Ubivanie po nomeru" << endl;
		cout << "3. Vozrastanie po napravleniu" << endl;
		cout << "4. Ubivanie po napravleniu" << endl;
		cout << "5. Vozrastanie po nachalu poleta" << endl;
		cout << "6. Ubivanie po nachalu poleta" << endl;
		cout << "7. Vozrastanie po kontu poleta" << endl;
		cout << "8. Ubivanie po kontu poleta" << endl;
		cout << "9. Vozrastanie po cene" << endl;
		cout << "10. Ubivanie po cene" << endl;
		cin >> ad;
		if ((ad < 1) || (ad > 11))
			cout << "vvedite nomer iz reada" << endl;
		else
			break;
	}
	if (ad == 1)
		std::sort(Array, Array + a, compareAscendingNumber);
	if (ad == 2)
		std::sort(Array, Array + a, compareDescendingNumber);
	if (ad == 3)
		std::sort(Array, Array + a, compareAscendingDestination);
	if (ad == 4)
		std::sort(Array, Array + a, compareDescendingDestination);
	if (ad == 5)
		std::sort(Array, Array + a, compareAscendingDepTime);
	if (ad == 6)
		std::sort(Array, Array + a, compareDescendingDepTime);
	if (ad == 7)
		std::sort(Array, Array + a, compareAscendingArrTime);
	if (ad == 8)
		std::sort(Array, Array + a, compareDescendingArrTime);
	if (ad == 9)
		std::sort(Array, Array + a, compareAscendingCost);
	if (ad == 10)
		std::sort(Array, Array + a, compareDescendingCost);
}

#pragma endregion

void Edit(flight **&Array, int a)
{
	int b = 0;
	// ввод надо разделять с редактированием
	std::string n;
	while (1)
	{
		b = 0;
		cout << "Kakuiu strochku jelaete izmeniti?" << endl;
		cin >> b;
		if (b >= a)
			cout << "Vi vveli nesushestvuiushuy strichku!" << endl;
		else
			break;
	}
	cout << "Izmenite nomer." << endl;
	cin >> n;
	Array[b]->number = n;
	cout << "Izmenite napravlenie" << endl;
	cin >> n;
	Array[b]->destination = n;
	cout << "Izmenite nachalo vremeni poleta" << endl;
	cin >> n;
	Array[b]->departing_time = n;
	cout << "Izmenite konet vremeni poleta" << endl;
	cin >> n;
	Array[b]->arriving_time = n;
	cout << "Izmenite cenu" << endl;
	cin >> n;

	Array[b]->cost = n;
}

void AddNewString(flight **&Array, int &a)
{
	a++;
	flight **tmp = new flight *[a];
	for (int i = 0; i < a - 1; i++)
	{
		tmp[i] = Array[i];
	}
	delete[] Array;
	Array = tmp;
	std::string n;
	flight *tmp1 = new flight;

	cout << "Dobavte nomer." << endl;
	cin >> n;
	tmp1->number = n;
	cout << "Dobavte napravlenie" << endl;
	cin >> n;
	tmp1->destination = n;
	cout << "Dobavte nachalo vremeni poleta" << endl;
	cin >> n;
	tmp1->departing_time = n;
	cout << "Dobavte konet vremeni poleta" << endl;
	cin >> n;
	tmp1->arriving_time = n;
	cout << "Dobavte cenu" << endl;
	cin >> n;
	tmp1->cost = n;

	Array[a - 1] = tmp1;
}

void Delete(flight **&Array, int &a)
{
	int d = 0;
	while (1)
	{
		d = 0;
		cout << "Vvedite nomer strochki kotoruy hotite udaliti?." << endl;
		cin >> d;
		if (d >= a)
			cout << "Vi vveli nesushestvuiushuy strichku!" << endl;
		else
			break;
	}
	a--;
	flight **tmp = new flight *[a];
	for (int i = 0; i < a; i++)
	{
		if (i < d)
			tmp[i] = Array[i];
		else
			tmp[i] = Array[i + 1];
	}
	delete[] Array;
	Array = tmp;
}

void Insert(flight **&Array, int &a)
{
	int ins = 0;
	while (1)
	{
		cout << "Vvedite nomer strochki kuda hotite dobaviti?" << endl;
		cin >> ins;
		if (ins > a)
			cout << "Vi vveli nesushestvuiushuy strichku!" << endl;
		else
			break;
	}
	a++;
	flight **tmp = new flight *[a];
	std::string n;
	flight *tmp1 = new flight;
	cout << "Dobavte nomer." << endl;
	cin >> n;
	tmp1->number = n;
	cout << "Dobavte napravlenie" << endl;
	cin >> n;
	tmp1->destination = n;
	cout << "Dobavte nachalo vremeni poleta" << endl;
	cin >> n;
	tmp1->departing_time = n;
	cout << "Dobavte konet vremeni poleta" << endl;
	cin >> n;
	tmp1->arriving_time = n;
	cout << "Dobavte cenu" << endl;
	cin >> n;
	tmp1->cost = n;
	for (int i = 0; i < a; i++)
	{
		if (i < ins)
			tmp[i] = Array[i];
		else if (i == ins)
			tmp[i] = tmp1;
		else
			tmp[i] = Array[i - 1];
	}
	delete[] Array;
	Array = tmp;
}

ofstream filew; // ???

void FileWrite(flight **&Array, int a)
{
	filew.open("avia redux.txt");
	for (int i = 0; i < a; i++)
	{
		std::string n;
		n = Array[i]->cost;
		n = Array[i]->arriving_time + "," + n;
		n = Array[i]->departing_time + "," + n;
		n = Array[i]->destination + "," + n;
		n = Array[i]->number + "," + n;
		filew << n << endl;
	}
}

void Free(flight **&Array, int a)
{
	// освобождать все указатели массива тоже надо
	delete[] Array;
	Array = NULL;
	a = 0;
}
