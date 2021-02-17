#include "lab6_dern_lib.h"

int stateMenu;
int MENU()
{
	cout << "Выберите действие:" << endl;
	cout << "(0)  Конец работы" << endl; 
	cout << "(1)  Ввод элементов массива с клавиатуры" << endl; 
	cout << "(2)  Поиск элемента массива" << endl; 
	cout << "(3)  Сортировка массива" << endl;
	cout << "(4)  Редактирование элемента массива" << endl; 
	cout << "(5)  Добавление нового элемента в конец" << endl; 
	cout << "(6)  Удаление указанного элемента из массива" << endl; 
	cout << "(7)  Вставка нового элемента" << endl; 
	cout << "(8)  Запись элементов массива в файл" << endl; 
	cout << "(9)  Считывание элементов массива из файла" << endl; 
	cout << "(10) Вывод элементов массива на экран" << endl; 
	cout << "(11) Освобождение памяти, выделенной для массива" << endl<<endl;
	cout << "Ваш выбор: " << endl;
	
	cin >> stateMenu;
	return stateMenu;
}

int main()
{
	int n = 0; // кол-во элементов массива
	
	kniga ** spisok = nullptr; // создание ссылки для массива структур
	string fileName = "file.txt"; // ссылка на файл для чтения/записи
	MENU();
	while (stateMenu != 0)
	{
		switch (stateMenu)
		{
		case 0: // выход из программы
			cout << "Успешное завершение программы" << endl;
			return 0;

		case 1: // заполнение массива с клавиатуры
			system("cls");
			if (n == 0)
			{
				Manual_input(spisok, n);
			}
			else cout << "Данные уже существуют" << endl;
			break;

		case 2: // поиск элементов массива
			system("cls");
			if (n != 0)
			{
				Search(spisok, n);
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;

		case 3: // сортировка массива
			system("cls");
			if (n != 0)
			{
				Sort_Data(spisok, n);
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;

		case 4: // редактирование элементов массива
			system("cls");
			if (n != 0)
			{
				Change_Data(spisok, n);
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;

		case 5: // добавление элемента в конец массива
			system("cls");
			Add_end(spisok, n);
			break;

		case 6: // удаление элемента массива
			system("cls");
			if (n != 0)
			{
				Delete_one(spisok, n);
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;

		case 7: // добавление элемента в массив
			system("cls");
			if (n != 0)
			{
				Add_new(spisok, n);
				cout << "Новый элемент добавлен" << endl;
			}
			else cout << "Данные не обнаружены. Заполните массив" << endl;
			break;
			
		case 8: // запись массива в файл
			system("cls");
			if (n != 0)
			{
				Recording_Data(spisok, n, fileName);
			}
			else cout << "Данные не обнаружены. Заполните массив" << endl;

		case 9: // чтение массива из файла
			if (n == 0)
			{
				Reading_Data(spisok, n, fileName);
			}
			break;

		case 10: // вывод массива на экран
			system("cls");
			if (n != 0)
			{
				Print(spisok, n);
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;

		case 11: // освобождение памяти, выделенной для массива
			system("cls");
			if (n != 0)
			{
				Delete_all(spisok, n);
				cout << "Память освобождена" << endl;
			}
			else cout << "Данные не обнаружены. Заполните массив";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
		MENU();
	}

	system("pause");
}