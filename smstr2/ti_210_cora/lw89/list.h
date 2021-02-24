#pragma once
#include "product.h"

class List {

private:
	struct Node {
		Product Data;
		Node* Next;

		Node(Product data, Node* next = nullptr) {
			Data = data;
			Next = next;
		}
	};

	int _size;
	Node* Head;

	Node* findPrevious(int index);

public:
	List();
	~List();
	int size();
	void push_back(Product data);
	void pop_back();
	void push_front(Product data);
	void pop_front();
	void clear();
	void insert(Product data, int index);
	void removeAt(int index);
	Node* begin();
	Node* end();
	void fileOut(std::string filename);
	void fileIn(std::string filename);
	void swap(int index1, int index2);
	void editData(int index);
	void sort();
	void find(int index);
	void print();
	void printElem(int index);
	void input();
	void uniteList(List& lst);
	void devideList(List& lst, int index);
	Product& operator[](const int index);
};
