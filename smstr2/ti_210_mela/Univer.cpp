#include <iostream>
#include <string>
#include <fstream>
#include "Univer.h"

// аналог. работе Кормана
basee::~basee() {
	delete[] array;
}

void basee::push_back(Univer Dobavl) {

	Univer* tmp = new Univer[size + 1];

	if (tmp == NULL) {
		return;
	}

	for (int a = 0; a < size; a++) {
		tmp[a] = array[a];
	}

	tmp[size] = Dobavl;
	size++;
	delete[] array;
	array = tmp;
}

void basee::print(int pos) {
	std::cout << array[pos].name << " - Nazvanie\n";
	std::cout << array[pos].adres << " - Adres\n";
	std::cout << array[pos].nomer << " - Nomer telefona\n";
	std::cout << array[pos].kol << " - Kol-vo fakultetov\n";
	std::cout << array[pos].stud << " - Kol-vo studentov\n";
	std::cout << std::endl;
}

void basee::onScreen() {
	for (int a = 0; a < size; ++a) {
		print(a);
	}
}

void basee::poiskElem(int pos) {
	if (pos > size || pos < 0) {
		return;
	}

	print(pos - 1);
}

void basee::sortirovka() {
	for (int i = 0; i < size; ++i) {

		for (int j = i + 1; j < size; ++j) {

			if (array[i].name > array[j].name) {
				std::string tmp = array[i].name;
				array[i].name = array[j].name;
				array[j].name = tmp;
			}
		}
	}
}

void basee::edit(int pos) {
	if (pos > size || pos <= 0) {
		return;
	}

	poiskElem(pos);
	while (true) {
		int num;
		std::cout << "Vvedite nomer ot 1 do 5 dlea izmenenia dannih: ";
		std::cin >> num;

		if (num < 1 || num > 5) {
			return;
		}

		switch (num) {
		case 1:
			std::cout << "Change name of university: ";
			std::getline(std::cin, array[pos].name);
			std::cin >> array[pos].name;
			break;
		case 2:
			std::cout << "Change adres of university: ";
			std::cin >> array[pos].adres;
			break;
		case 3:
			std::cout << "Change telephone of university: ";
			std::cin >> array[pos].nomer;
			break;
		case 4:
			std::cout << "Change number of faculties: ";
			std::cin >> array[pos].kol;
			break;
		case 5:
			std::cout << "Change number of students: ";
			std::cin >> array[pos].stud;
			break;
		}
	}

}

void basee::erase(int poz)
{
	// раз уж копируете, то - без ошибок
	Univer* tmp = (Univer*)calloc((size - 1), sizeof(Univer));
	if (tmp == NULL) {
		return;
	}

	for (int a = 0; a < size; a++) {
		if (a < poz - 1) {
			array[a] = tmp[a];
		}
		else if (a == poz - 1) {
			continue;
		}
		else {
			array[a] = tmp[a - 1];
		}
	}
	size--;
	free(array);
	array = tmp;
}

void basee::vstavka(int poz, Univer Dobavl)
{
	Univer* tmp = (Univer*)calloc((size + 1), sizeof(Univer));
	if (tmp == NULL) {
		return;
	}

	for (int a = 0; a < size; a++) {
		if (a < poz - 1) {
			array[a] = tmp[a];
		}
		else if (a == poz - 1) {
			tmp[a] = Dobavl;
		}
		else {
			array[a] = tmp[a + 1];
		}
	}
	size++;
	free(array);
	array = tmp;
}

void basee::iz_file()
{
	std::ifstream f_in;
	f_in.open("baza.txt");
	std::string str;
	Univer tmp;
	int it = 1;
	while (std::getline(f_in, str))
	{
		switch (it) {
		case 1:
			tmp.name = str;
			++it;
			break;
		case 2:
			tmp.adres = str;
			++it;
			break;
		case 3:
			tmp.nomer = std::stoi(str);
			++it;
			break;
		case 4:
			tmp.kol = std::stoi(str);
			++it;
			break;
		case 5:
			tmp.stud = std::stoi(str);
			++it;
			push_back(tmp);
			break;
		case 6:
			it = 1;
			break;
		}
	}
	f_in.close();
}

void basee::in_file()
{
	std::string path = "baza.txt"; // не надо хард-кодить данные
	std::ofstream fout;
	fout.open(path);

	{
		for (int a = 0; a < size; ++a) {
			fout << array[a].name << "\n";
			fout << array[a].adres << "\n";
			fout << array[a].nomer << "\n";
			fout << array[a].kol << "\n";
			fout << array[a].stud << "\n";
			fout << std::endl;
		}

	}
	fout.close();
}
