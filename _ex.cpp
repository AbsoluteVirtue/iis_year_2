#include <iostream>
#include <fstream>
#include <string>

#include "list.h"


int main(int argc, char const *argv[])
{
	list l(argv[1]);

	node *second = new node(argv[2]);

	l.head->next = second;

	node *third = new node(argv[3]);

	l.head->next->next = third;

	std::swap(second->data, third->data);

	l.print();

	return 0;
}
