#include "Data.h"

// аналог. работе Пынзару
using namespace std;

void DataEntry(Data *(&d), int &n)
{
	cout << "Введите количество данных: ";
	cin >> n;

	d = new Data[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "Введите название фильма: ";
		cin >> d[i].Film_title;
		cout << "Введите страну: ";
		cin >> d[i].Country;
		cout << "Введите продюсера: ";
		cin >> d[i].Producer;
		cout << "Введите жанр: ";
		cin >> d[i].Genre;
		cout << "Введите год: ";
		cin >> d[i].Year;
	}
}

void ReadingData(Data *(&d), int &n, string fileName)
{
	ifstream reading(fileName);
	if (reading)
	{
		reading >> n;
		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reading >> d[i].Film_title;
			reading >> d[i].Country;
			reading >> d[i].Producer;
			reading >> d[i].Genre;
			reading >> d[i].Year;
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}

void PrintData(Data *d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " Название фильма: " << d[i].Film_title << endl;
		cout << " Страна: " << d[i].Country << endl;
		cout << "Продюсер: " << d[i].Producer << endl;
		cout << "Жанр: " << d[i].Genre << endl;
		cout << "Год: " << d[i].Year << endl;
	}
}

void DataChange(Data *(&d), int n)
{
	int _n;
	cout << "Введите номер элемента ( от 1 до 50" << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	if (_n >= 0 && _n < n)
	{
		cout << "Введите название фильма: ";
		cin >> d[_n].Film_title;
		cout << "Введите страну: ";
		cin >> d[_n].Country;
		cout << "Введите продюсера:  ";
		cin >> d[_n].Producer;
		cout << "Введите жанр: ";
		cin >> d[_n].Genre;
		cout << "Введите год: ";
		cin >> d[_n].Year;

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введен неверно" << endl;
}

void DeleteData(Data *(&d), int &n)
{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "):";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Data *buf = new Data[n];
		Copy(buf, d, n);
		--n;
		if (_n >= 0 && _n < n)
		{
			Data *buf = new Data[n];
			Copy(buf, d, n);
			--n;
			d = new Data[n];
			int q = 0;
			for (int i = 0; i <= n; i++)
			{
				if (i != _n)
				{
					d[q] = buf[i];
					++q;
				}
			}
			delete[] buf;

			cout << "Данные удалены!" << endl;
		}
		else
			cout << "Номер введен неверно!" << endl;
	}
}

void Copy(Data *(&d_n), Data *(&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void Copy(Data &d_n, Data &d_o)
{
	d_n.Film_title = d_o.Film_title;
	d_n.Country = d_o.Country;
	d_n.Producer = d_o.Producer;
	d_n.Genre = d_o.Genre;
	d_n.Year = d_o.Year;
}

void AddDate(Data *(&d), int &n)
{
	Data *buf;
	buf = new Data(); // почему не массив?

	Copy(buf, d, n);

	n++;
	d = new Data();

	Copy(d, buf, --n);
	cout << " Введите название фильма: ";
	cin >> d[n].Film_title;
	cout << "Введите страну: ";
	cin >> d[n].Country;
	cout << "Введите продюсера:  ";
	cin >> d[n].Producer;
	cout << "Введите жанр: ";
	cin >> d[n].Genre;
	cout << "Введите год: ";
	cin >> d[n].Year;

	cout << "Данные добавлены!" << endl;

	delete buf; // потому что не массив
}

void DataSorting(Data *d, int n)
{
	Data buf;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i].Film_title > d[j].Film_title)
			{
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	cout << "Данные отсортированы!" << endl;
}

void SavingData(Data *d, int n, string fileName)
{
	ofstream record(fileName, ios::out);

	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << d[i].Film_title << endl;
			record << d[i].Country << endl;
			record << d[i].Producer << endl;
			record << d[i].Genre << endl;
			record << d[i].Year << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}
