#include <iostream>
#include <fstream>
#include <string>
#include <forward_list>
#include <vector>

struct T
{
	std::string s;

	T(const std::string str = ""): s(str) {}
};

struct node
{
	T * data{nullptr};
	node * next{nullptr};

	node(): data(new T) {}
	node(T * obj): data(obj) {}
	~node();

	void print();
};

struct list
{
	node * head{nullptr};
	size_t size{0};

	list() {}
	list(const std::string filename, const std::string header = "", const std::string footer = "");
	~list();

	void print();
	void push_front(T * obj);
	void pop_front();
	void edit_front(const std::string str);
	void erase(const size_t pos);
};

int main(int argc, char const *argv[])
{
	list l;

	for (int i = 1; i < argc; i++)
	{
		l.push_front(new T(argv[i]));
	}

	l.print();

	l.erase(0);

	l.print();

	l.erase(4);

	l.print();

	return 0;
}

node::~node()
{
	delete data;
}

list::~list()
{
	while (head)
	{
		node * tmp = head->next;
		delete head;
		head = tmp;
	}
}

list::list(const std::string filename, const std::string header, const std::string footer)
{
	std::ifstream in;
	in.open(filename);
	if (!in.is_open()) return;

	std::string line;
	node * tmp = new node;
	while (std::getline(in, line))
	{
		if (header != "" && (line.substr(1, header.length()) == header)) continue;

		tmp->data = new T;
		tmp->data->s = line;
		if (!head)
		{
			head = tmp;
		}

		if(footer != "" && (line.substr(1, footer.length()) == footer))
			break;

		tmp->next = new node;
		tmp = tmp->next;
		++size;
	}
	in.close();
}

void node::print()
{
	std::cout << data->s;
}

void list::print()
{
	for (node * tmp = head; tmp; tmp = tmp->next)
	{
		tmp->print();
		std::cout << "\t";
	}
	std::cout << "\n";
}

void list::push_front(T * obj)
{
	node * tmp = head;
	head = new node(obj);
	head->next = tmp;
	++size;
}

void list::edit_front(const std::string str)
{
	if( head ) head->data->s = str;
}

void list::erase(const size_t pos) 
{
	if (pos >= size) return;

	node * tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++, tmp = tmp->next)
		{
			;
		}
		node * curr = tmp->next;
		tmp->next = curr->next;
		delete curr;
	}
	--size;
}

void list::pop_front()
{
	this->erase(0);
}
