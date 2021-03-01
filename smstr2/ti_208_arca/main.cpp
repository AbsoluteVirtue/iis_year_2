#include <iostream>
#include <vector>
#include <string>

using namespace std; // так не надо делать

void F1_Keyboard_Input();
void F2_Find_Element();
void F3_Sort_Array();
void F3_by_Year();
void F3_by_Price();
void F4_Edit_Element();
void F5_New_Element_at_The_End();
void F6_Delete_Element();
void F7_Paste_Element();
void F8_Show_Array();
void F9_Clear_Array();
void F10_Exit();

// нет чтения из файла

struct Phone
{
	string brand;
	string model;
	int price;
	int year;
};

vector<Phone> Array_of_Phones; // нет указателей, глобальная переменная исключает использование библиотеки

#pragma region main

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "    ����� " << endl;
	cout << "��� ���� ������� 1 " << endl;
	cout << "��� ������ ������� 2 " << endl;
	cout << "��� �����: ";
	cin >> a;
	if (a == 1)
	{
		int b = 0;
		while (b != 10)
		{
			cout << endl;
			cout << "1)��� ����� � ���������� ������� 1" << endl;
			cout << "2)��� ������ �������� ������� 2" << endl;
			cout << "3)��� ���������� ������� 3" << endl;
			cout << "4)��� ��������� ���������� �������� ������� 4" << endl;
			cout << "5)��� ���������� ������ �������� � ����� ������� 5" << endl;
			cout << "6)��� �������� ���������� �������� ������� 6" << endl;
			cout << "7)��� ������� �������� ������� 7" << endl;
			cout << "8)��� ������ ������� �������� ������� 8" << endl;
			cout << "9)��� ������� �������� ������� �������� ������� 9" << endl;
			cout << "10)��� ������ ������� 10" << endl;
			cout << "��� �����: ";
			cin >> b;
			cout << endl;
			if (b == 1)
			{
				F1_Keyboard_Input();
			}
			else if (b == 2)
			{
				F2_Find_Element();
			}
			else if (b == 3)
			{
				F3_Sort_Array();
			}
			else if (b == 4)
			{
				F4_Edit_Element();
			}
			else if (b == 5)
			{
				F5_New_Element_at_The_End();
			}
			else if (b == 6)
			{
				F6_Delete_Element();
			}
			else if (b == 7)
			{
				F7_Paste_Element();
			}
			else if (b == 8)
			{
				F8_Show_Array();
			}
			else if (b == 9)
			{
				F9_Clear_Array();
			}
			else if (b == 10)
			{
				F10_Exit();
			}
		}
	}
	else if (a == 2)
	{
		exit(0);
	}
	return 0;
}

void F1_Keyboard_Input() // не надо было делать
{
	int n;
	cout << " ������� ���������� ��������� ������� ������ ��������: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		struct Phone NewOne;
		cout << "������� �����: ";
		cin >> NewOne.brand;
		cout << endl;
		cout << "������� ������: ";
		cin >> NewOne.model;
		cout << endl;
		cout << "������� ����: ";
		cin >> NewOne.price;
		cout << endl;
		cout << "������� ���: ";
		cin >> NewOne.year;
		cout << endl;
		Array_of_Phones.push_back(NewOne);
	}
}

void F3_Sort_Array()
{
	cout << "��� ���������� �� ���� ������� 1" << endl;
	cout << "��� ���������� �� ���� ������� 2" << endl;
	int x;
	cin >> x;
	if (x == 1)
	{
		F3_by_Price();
	}
	else if (x == 2)
	{
		F3_by_Year();
	}
}

#pragma endregion

void F2_Find_Element()
{
	// не смешивать ввод и изменение данных
	int x;
	cout << "����� ������� �� ������ �����: ";
	cin >> x; // проверка выхода за пределы массива где?
	cout << endl;
	cout << "�����:" << Array_of_Phones[x - 1].brand;
	cout << endl;
	cout << "������: " << Array_of_Phones[x - 1].model;
	cout << endl;
	cout << "����: " << Array_of_Phones[x - 1].price;
	cout << endl;
	cout << "���: " << Array_of_Phones[x - 1].year;
	cout << endl;
}

void F4_Edit_Element()
{
	int x;
	cout << "������� ������� ������� ������ ��������: ";
	cin >> x;
	struct Phone NewOne; // не нужна новая структура
	cout << "������� �����: ";
	cin >> NewOne.brand;
	cout << endl;
	cout << "������� ������: ";
	cin >> NewOne.model;
	cout << endl;
	cout << "������� ����: ";
	cin >> NewOne.price;
	cout << endl;
	cout << "������� ���: ";
	cin >> NewOne.year;
	cout << endl;
	Array_of_Phones[x - 1].brand = NewOne.brand;
	Array_of_Phones[x - 1].model = NewOne.model;
	Array_of_Phones[x - 1].price = NewOne.price;
	Array_of_Phones[x - 1].year = NewOne.year;
}

void F5_New_Element_at_The_End()
{
	struct Phone NewOne;
	cout << "������� �����: ";
	cin >> NewOne.brand;
	cout << endl;
	cout << "������� ������: ";
	cin >> NewOne.model;
	cout << endl;
	cout << "������� ����: ";
	cin >> NewOne.price;
	cout << endl;
	cout << "������� ���: ";
	cin >> NewOne.year;
	cout << endl;
	Array_of_Phones.push_back(NewOne);
	cout << endl;
}

void F6_Delete_Element()
{
	int x, y; // зачем переменная y?
	cout << "������� �������, ������� ������ �������: ";
	cin >> x;
	Array_of_Phones.erase(Array_of_Phones.begin() + (x - 1));
}

void F7_Paste_Element()
{
	int i = 0;
	cout << "����� ������ �������� ������ �������� �����: ";
	cin >> i;
	struct Phone NewOne;
	cout << "������� �����: ";
	cin >> NewOne.brand;
	cout << endl;
	cout << "������� ������: ";
	cin >> NewOne.model;
	cout << endl;
	cout << "������� ����: ";
	cin >> NewOne.price;
	cout << endl;
	cout << "������� ���: ";
	cin >> NewOne.year;
	cout << endl;
	Array_of_Phones.insert(Array_of_Phones.begin() + i, NewOne);
	cout << endl;
}

void F8_Show_Array()
{
	cout << endl;
	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		cout << "�� " << i + 1 << ")" << endl;
		cout << "�����:  " << Array_of_Phones[i].brand;
		cout << endl;
		cout << "������: " << Array_of_Phones[i].model;
		cout << endl;
		cout << "����:   " << Array_of_Phones[i].price << "$";
		cout << endl;
		cout << "���:    " << Array_of_Phones[i].year << " ���";
		cout << endl;
	}
}

void F9_Clear_Array()
{
	Array_of_Phones.clear();
}

void F10_Exit()
{
	exit(0);
}

void F3_by_Price()
{
	// не стоит так усложнять, можно обойтись std::sort(...)
	struct Phone Temp;
	struct Phone Sorted_Array[Array_of_Phones.size()];
	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		Sorted_Array[i].brand = Array_of_Phones[i].brand;
		Sorted_Array[i].model = Array_of_Phones[i].model;
		Sorted_Array[i].price = Array_of_Phones[i].price;
		Sorted_Array[i].year = Array_of_Phones[i].year;
	}
	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		for (int j = i + 1; j < Array_of_Phones.size(); j++)
		{
			if (Sorted_Array[i].price > Sorted_Array[j].price)
			{
				Temp = Sorted_Array[i];
				Sorted_Array[i] = Sorted_Array[j];
				Sorted_Array[j] = Temp;
			}
		}
	}

	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		Array_of_Phones[i].brand = Sorted_Array[i].brand;
		Array_of_Phones[i].model = Sorted_Array[i].model;
		Array_of_Phones[i].price = Sorted_Array[i].price;
		Array_of_Phones[i].year = Sorted_Array[i].year;
	}
}

void F3_by_Year()
{
	struct Phone Temp;
	struct Phone Sorted_Array[Array_of_Phones.size()];
	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		Sorted_Array[i].brand = Array_of_Phones[i].brand;
		Sorted_Array[i].model = Array_of_Phones[i].model;
		Sorted_Array[i].price = Array_of_Phones[i].price;
		Sorted_Array[i].year = Array_of_Phones[i].year;
	}
	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		for (int j = i + 1; j < Array_of_Phones.size(); j++)
		{
			if (Sorted_Array[i].year > Sorted_Array[j].year)
			{
				Temp = Sorted_Array[i];
				Sorted_Array[i] = Sorted_Array[j];
				Sorted_Array[j] = Temp;
			}
		}
	}

	for (int i = 0; i < Array_of_Phones.size(); i++)
	{
		Array_of_Phones[i].brand = Sorted_Array[i].brand;
		Array_of_Phones[i].model = Sorted_Array[i].model;
		Array_of_Phones[i].price = Sorted_Array[i].price;
		Array_of_Phones[i].year = Sorted_Array[i].year;
	}
}
