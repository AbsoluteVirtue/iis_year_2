#include <iostream>
#include <fstream>
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

	node(const std::string s = "")
	{
		data = new T(s);
	}

	~node()
	{
		delete data;
		delete next;
	}
};

struct list
{
	node *head{nullptr};
	size_t size{0};

	void print()
	{
		for (node *tmp = head; tmp; tmp = tmp->next)
		{
			std::cout << tmp->data->s << "\n";
		}
	}

	list(const std::string s = "")
	{
		head = new node(s);
		++size;
	}

	~list()
	{
		delete head;
		size = 0;
	}

	void clear()
	{
		while (head)
		{
			node *tmp = head->next;
			delete head;
			head = tmp;
		}
	}
};

int main(int argc, char const *argv[])
{
	list l("test");

	node *second = new node("rest");

	l.head->next = second;

	node *third = new node("best");

	l.head->next->next = third;

	std::swap(second->data, third->data);

	l.print();

	return 0;
}
