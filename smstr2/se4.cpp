#include <iostream>
#include <fstream>
#include <string>

struct T
{
	std::string s{""};
};

struct node
{
	T * data{nullptr};
	node * next{nullptr};

	node(): data(new T) {}
	~node();
};

struct list
{
	node * head{nullptr};
	size_t size{0};

	list();
	list(const std::string filename, const std::string header = "", const std::string footer = "");
	~list();

	void print();
};

int main(int argc, char const *argv[])
{
	list l;

	l.head->data->s = "Test";

	l.print();

	return 0;
}

node::~node()
{
	delete data;
	delete next;
}

list::~list()
{
	delete head;
}

list::list(): head(new node)
{
	++size;
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

void list::print()
{
	for (node * tmp = head; tmp; tmp = tmp->next)
	{
		std::cout << tmp->data->s << "\n";
	}
}
