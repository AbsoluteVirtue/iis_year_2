#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>

struct T 
{
	std::string str;
};

struct node
{
	T data;
	node * next{nullptr};

	node()
	{
		std::cout << "ctor\n";
	}
};

struct list 
{
	node * h = nullptr;

	~list();
	list(const int n, char const *argv[]);

	void print();
	void swap();
};

int main(int argc, char const *argv[])
{
	list l1(argc, argv);

	l1.print();

	return 0;
}

list::~list()
{
	std::cout << "dtor\n";
	while (this->h)
	{
		node *tmp = this->h->next;
        delete  this->h;
        this->h = tmp;
	}
}

list::list(const int n, char const *argv[])
{
	node * tmp = nullptr;
	node * head = nullptr;
	for (int i = 1; i < n; i++, head = head->next)
	{
		T test;
		test.str = argv[i];

		head = new node;

		head->data = test;

		if (tmp)
		{
			tmp->next = head;
		}
		tmp = head;
		if (!this->h)
		{
			this->h = head;
		}
	}
}

void list::print()
{
	node * tmp = this->h;
	while(tmp)
	{
		std::cout << tmp->data.str << "\n";

		tmp = tmp->next;
	}
}
