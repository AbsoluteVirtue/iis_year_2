#include <iostream>
#include <string>

struct T
{
	std::string s;

	T(const std::string str) : s(str) {}
};

struct node
{
	T *data{nullptr};
	node *next{nullptr};

	node() = delete;
	node(std::string str)
	{
		this->data = new T(str);
	}
	~node()
	{
		delete this->data;
	}
};

struct list
{
	node * head{nullptr};

	list() = delete;
	list(std::string str)
	{
		this->head = new node(str);
	};
	~list() 
	{
		while (this->head)
		{
			node *tmp = this->head->next;
			delete this->head;
			this->head = tmp;
		}
	}

	void print();
};

void list::print()
{
	for (node *tmp = head; tmp; tmp = tmp->next)
	{
		std::cout << tmp->data->s << "\n";
	}
}
