#ifndef Basee_H
#define Basee_H

struct Univer {
	std::string name = "";
	std::string adres = "";
	int nomer = 0;
	int kol = 0;
	int stud = 0;
};

class basee {
	Univer* array = nullptr; // массив указателей где?
	int size = 0;

public:

	~basee();
	void print(int pos);
	void onScreen();
	void poiskElem(int pos);
	void sortirovka();
	void edit(int pos);
	void push_back(Univer Dobavl);
	void erase(int pos);
	void vstavka(int poz, Univer Dobavl);
	void in_file();
	void iz_file();
};

#endif 