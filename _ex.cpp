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
};

void print(node* &head) 
{
	for (node * tmp = head; tmp; tmp = tmp->next)
	{
		std::cout << tmp->data->s << "\n";
	}
}

int main(int argc, char const *argv[])
{
	node * head = new node;

	head->data = new T;
	head->data->s = "test";

	node * second = new node;
	second->data = new T;
	second->data->s = "rest";

	head->next = second;

	node * third = new node;
	third->data = new T;
	third->data->s = "best";

	head->next->next = third;

	std::swap(second->data, third->data);

	print(head);

	return 0;
}
