#include "Countries.h"

int cmenu;
void Menu()
{
	cout << "Viberite deistvie:" << endl
		<< "(0) Vihod s programmi" << endl
		<< "(1) Vvod dannih" << endl
		<< "(2) Vivod dannih" << endl
		<< "(3) Izmenenie dannih" << endl
		<< "(4) Udalenie dannih" << endl
		<< "(5) Dobavlenie dannih" << endl
		<< "(6) Sortirovka dannih" << endl
		<< "(7) Sohranenie dannih" << endl
		<< "Vibiraite: ";
	cin >> cmenu;
}

int main() {
	Menu();
	int bmp;
	int kolvocountry = 0;
	string nameoffile;

	Countries* c = new Countries[kolvocountry];

	while (cmenu != 0)
	{
		switch (cmenu)
		{
		case 1:
			cout << "Hotite vvesti dannie vru4nuiu? (1-yes/2-from file): ";
			cin >> bmp;

			if (bmp == 1) {
				countriesEnter(c, kolvocountry);
			}
			else
			{


				Readingcountries(c, kolvocountry, "sda666.txt");
			}
			Menu();
			break;

		case 2:
			if (kolvocountry != 0) {
				Print(c, kolvocountry);
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		case 3:
			if (kolvocountry != 0) {
				countriesChange(c, kolvocountry);
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		case 4:
			if (kolvocountry != 0) {
				Deletecountries(c, kolvocountry);
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		case 5:
			if (kolvocountry != 0) {
				Addcountries(c, kolvocountry);
				kolvocountry++;
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		case 6:
			if (kolvocountry != 0) {
				countriesSort(c, kolvocountry);
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		case 7:
			cout << "Vvedite nazvanie faila: ";
			cin >> nameoffile;

			if (kolvocountry != 0) {
				Savingcountries(c, kolvocountry, nameoffile);
			}
			else
				cout << "Dannie pustie" << endl;
			Menu();
			break;

		default:
			cout << "Nevernoe deistvie =(" << endl;
			Menu();
			break;
		}
	}
}