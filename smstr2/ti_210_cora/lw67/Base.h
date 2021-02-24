#ifndef Base_H
#define Base_H
#include "Product.h"

class Base {
	Product* array = nullptr; // массив указателей
	int size = 0;
public:
	~Base();
	// можно было бы через конструкторы реализовать
	void fromKeyboard();
	void print(int pos);
	void onScreen();
	void findElem(int pos);
	void sort();
	void edit(int pos);
	void push_back(Product added);
	void erase(int pos);
	void insert(int pos, Product added);
	void onFile(std::string fileName);
	void fromFile(std::string fileName);
};

#endif 