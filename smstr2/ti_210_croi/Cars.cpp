#include "Cars.h"
#include <iostream>

// аналог. работе Пынзару
using namespace std; // так делать не надо

void CarsEnter(Cars *(&c), int &n)
{
    cout << "Enter amount of date: ";
    cin >> n;

    c = new Cars[n]; // желательно проверять был ли он уже выделен до вызова функции
    for (int i = 0; i < n; i++)
    {
        cout << "Enter model: ";
        cin >> c[i]._model;
        cout << "Enter country: ";
        cin >> c[i]._country;
        cout << "Enter year: ";
        cin >> c[i]._year;
        cout << "Enter hp: ";
        cin >> c[i]._power;
        cout << "Enter price: ";
        cin >> c[i]._price;

        cout << "________________________________" << endl;
    }
}

void ReadingCars(Cars *(&c), int &n, string fileName)
{
    fstream reading(fileName);

    if (reading)
    {
        reading >> n;
        c = new Cars[n];

        for (int i = 0; i < n; i++)
        {

            reading >> c[i]._model;

            reading >> c[i]._country;

            reading >> c[i]._year;

            reading >> c[i]._power;
            reading >> c[i]._price;
        }
        cout << "Dates were complete" << endl;
    }
    else
        cout << "Error openning file" << endl;

    reading.close(); // это надо внутри if
}

void Print(Cars *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Date number" << i + 1 << ":" << endl;

        cout << "Model of car: " << c[i]._model << " " << endl;
        cout << "Country: " << c[i]._country << endl;
        cout << "Year: " << c[i]._year << endl;
        cout << "Power: " << c[i]._power << endl;
        cout << "Price: " << c[i]._price << endl;
        cout << "_________________" << endl;
    }
}

void CarsChange(Cars *(&c), int n)
{
    int b;
    cout << "Enter number of element (from 1 to " << n << "): ";
    cin >> b;
    b--;

    if (b >= 0 && b < n)
    {
        cout << "Enter model of car: ";
        cin >> c[b]._model;
        cout << "Enter country: ";
        cin >> c[b]._country;
        cout << "Enter year: ";
        cin >> c[b]._year;
        cout << "Enter power: ";
        cin >> c[b]._power;
        cout << "Enter price: ";
        cin >> c[b]._price;
    }
    else
        cout << "Number is not correct" << endl;
}

void DeleteCars(Cars *(&c), int &n)
{
    int b;
    cout << "Enter number of element (from 1 to " << n << "): ";
    cin >> b;
    b--;

    if (b >= 0 && b < n)
    {
        // зачем копировать два раза?
		// где delete [] c?
        Cars *buf = new Cars[n];
        Copy(buf, c, n);
        --n;
        c = new Cars[n];
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
        cout << "Dates deleted" << endl;
    }
    else
        cout << "Number is not correct" << endl;
}

void Copy(Cars *(&c_n), Cars *(c_o), int n)
{
    for (int i = 0; i < n; i++)
    {
        c_n[i] = c_o[i];
    }
}

void AddCars(Cars *(&c), int &n)
{
    Cars *buf;
    buf = new Cars[n];

    Copy(buf, c, n);

    n++;
    c = new Cars[n];

    Copy(c, buf, --n);
    cout << "Enter model of car: ";
    cin >> c[n]._model;
    cout << "Enter country: ";
    cin >> c[n]._country;
    cout << "Enter year: ";
    cin >> c[n]._year;
    cout << "Enter power: ";
    cin >> c[n]._power;
    cout << "Enter price: ";
    cin >> c[n]._price;

    cout << "Dates added" << endl;
    delete[] buf;
}

void CarsSort(Cars *c, int n)
{
    Cars buf;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (c[i]._model > c[j]._model)
            {
                Copy(buf, c[j]);
                Copy(c[j], c[i]);
                Copy(c[i], buf);
            }
        }
    }
    cout << "Dates were sort" << endl;
}

void Copy(Cars &c_n, Cars &c_o)
{
    c_n._model = c_o._model;
    c_n._country = c_o._country;
    c_n._year = c_o._year;
    c_n._power = c_o._power;
    c_n._price = c_o._price;
}

void SavingCars(Cars *c, int n, string fileName)
{
    ofstream record(fileName, ios::out);
    if (record)
    {
        record << n << endl;
        for (int i = 0; i < n; i++)
        {
            record << c[i]._model << endl;
            record << c[i]._country << endl;
            record << c[i]._year << " ";
            record << c[i]._power << " ";
            record << c[i]._price << " ";
            /*if (i<n-1)
            record << c[i]._price << endl;
            else
            record << c[i]._price;
            */
        }
    }
    else
        cout << "Error openning file" << endl;
    record.close();
}
