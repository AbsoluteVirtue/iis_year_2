#include <iostream>
#include <string>
#include <fstream>
#include "Base.h"

// аналог. работе Мельника
Base::~Base() {
	delete[] array;
}

void Base::fromKeyboard() {

	std::cout << "Enter number of elements: ";
	int num;
	std::cin >> num;

	for (int i = 0; i < num; ++i) {
		Product tmp;
		std::cout << "Enter name: ";
		std::cin >> tmp.name;
		std::cout << "Enter country: ";
		std::cin >> tmp.country;
		std::cout << "Enter maker: ";
		std::cin >> tmp.maker;
		std::cout << "Enter vendor code: ";
		std::cin >> tmp.vendorCode;
		std::cout << "Enter price: ";
		std::cin >> tmp.price;
		push_back(tmp);
	}
}

void Base::print(int pos) {
	std::cout << array[pos].name << "\n";
	std::cout << array[pos].country << "\n";
	std::cout << array[pos].maker << "\n";
	std::cout << array[pos].vendorCode << "\n";
	std::cout << array[pos].price << "\n";
	std::cout << std::endl;
}

void Base::onScreen() {
	for (int i = 0; i < size; ++i) {
		print(i);
	}
}

void Base::findElem(int pos) {
	if (pos > size || pos < 0) {
		return;
	}

	print(pos - 1);
}

void Base::sort() {
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

void Base::edit(int pos) {
	if (pos > size || pos <= 0) {
		return;
	}

	findElem(pos);
	while (true) {
		int num;
		// лучше передавать в функцию в виде аргументов
		std::cout << "Enter number (1-5) to change data or any other to exit: ";
		std::cin >> num;

		if (num < 1 || num > 5) {
			return;
		}

		switch (num) {
		case 1:
			std::cout << "Change name of product: ";
			std::getline(std::cin, array[pos].name);
			break;
		case 2:
			std::cout << "Change country of product: ";
			std::cin >> array[pos].country;
			break;
		case 3:
			std::cout << "Change maker of product: ";
			std::cin >> array[pos].maker;
			break;
		case 4:
			std::cout << "Change vendor code of product: ";
			std::cin >> array[pos].vendorCode;
			break;
		case 5:
			std::cout << "Change price of product: ";
			std::cin >> array[pos].price;
			break;
		}
	}

}

void Base::push_back(Product added) {
	Product* tmp = new Product[size + 1];

	if (tmp == nullptr) {
		return;
	}

	for (int i = 0; i < size; ++i) {
		tmp[i] = array[i];
	}

	tmp[size] = added;
	delete[] array;

	array = tmp;
	size++;
}

void Base::erase(int pos) {
	if (pos > size || pos <= 0) {
		return;
	}

	Product* tmp = new Product[size - 1];

	if (tmp == nullptr) {
		return;
	}

	for (int i = 0; i < size; ++i) {

		if (i < pos - 1) {
			tmp[i] = array[i];
		}
		else {

			if (i + 1 == size) {
				break;
			}

			tmp[i] = array[i + 1];
		}

	}

	delete[] array;
	array = tmp;
	size--;
}

void Base::insert(int pos, Product added) {
	if (pos > size + 1 || pos <= 0) {
		return;
	}

	Product* tmp = new Product[size + 1];
	size++;

	if (tmp == nullptr) {
		return;
	}

	for (int i = 0; i < size; ++i) {

		if (i < pos - 1) {
			tmp[i] = array[i];
		}
		else if (i == pos - 1) {
			tmp[i] = added;
		}
		else {
			tmp[i] = array[i - 1];
		}

	}

	delete[] array;
	array = tmp;
}

void Base::onFile(std::string fileName) {
	std::ofstream fout;
	fout.open(fileName);

	for (int i = 0; i < size; ++i) {
		fout << array[i].name << "\n";
		fout << array[i].country << "\n";
		fout << array[i].maker << "\n";
		fout << array[i].vendorCode << "\n";
		fout << array[i].price << "\n";
		fout << std::endl;
	}

	fout.close();
}

void Base::fromFile(std::string fileName) {
	std::ifstream fin;
	fin.open(fileName);

	if (!fin.is_open()) {
		return;
	}

	std::string str;
	Product tmp;
	int it = 1;

	while (std::getline(fin, str, '\n')) {

		switch (it) {
		case 1:
			tmp.name = str;
			++it;
			break;
		case 2:
			tmp.country = str;
			++it;
			break;
		case 3:
			tmp.maker = str;
			++it;
			break;
		case 4:
			tmp.vendorCode = str;
			++it;
			break;
		case 5:
			tmp.price = std::stoi(str);
			++it;
			push_back(tmp);
			break;
		case 6:
			it = 1;
			break;
		}

	}

	fin.close();
}