#include <iostream>
#include <string>

struct T
{
	std::string a;
	std::string b;
	std::string c;
	std::string d;
};

struct node
{
	node *next{nullptr};

	T data;
};

void print(node *tmp);
node *search(node *tmp, const std::string find);
std::string edit(node *tmp, const std::string find, const std::string str);
void clear(node *head);
node *sort(node *head);
void push_front(node * & head, const T & obj);

int main(int argc, char const *argv[])
{
	node *head = nullptr;

	push_front(head, {"Test1", "Test1", "Test1", "Test1"});
	push_front(head, {"Best1", "Best1", "Best1", "Best1"});
	push_front(head, {"Rest1", "Rest1", "Rest1", "Rest1"});

	print(head);

	node *sorted = sort(head);

	print(sorted);

	clear(sorted);

	return 0;
}

void push_front(node * & head, const T & obj)
{
	if (!head)
	{
		head = new node;
		head->data = obj;
	}
	else
	{
		node * tmp = head;
		head = new node;
		head->data = obj;
		head->next = tmp;
	}
}

node *split(node *head)
{
	node *midPrev = nullptr;
	while (head && head->next)
	{
		midPrev = (midPrev == nullptr) ? head : midPrev->next;
		head = head->next->next;
	}
	node *mid = midPrev->next;
	midPrev->next = nullptr;
	return mid;
}

node * merge(node *list1, node *list2)
{
	node * dummyHead = new node;
	node *ptr = dummyHead;

	while (list1 && list2)
	{
		if (list1->data.a < list2->data.a)
		{
			ptr->next = list1;
			list1 = list1->next;
		}
		else
		{
			ptr->next = list2;
			list2 = list2->next;
		}
		ptr = ptr->next;
	}
	if (list1)
		ptr->next = list1;
	else
		ptr->next = list2;

	return dummyHead->next;
}

node *sort(node *head)
{
	if (!head || !head->next)
		return head;

	node *mid = split(head);
	node *left = sort(head);
	node *right = sort(mid);
	return merge(left, right);
}

void print(node *tmp)
{
	while (tmp)
	{
		std::cout << tmp->data.a << " "
				  << tmp->data.b << " "
				  << tmp->data.c << " "
				  << tmp->data.d << "\n";

		tmp = tmp->next;
	}
}

node *search(node *tmp, const std::string find)
{
	for (; tmp; tmp = tmp->next)
	{
		if (find == tmp->data.a)
			return tmp;
	}
	return nullptr;
}

std::string edit(node *tmp, const std::string find, const std::string str)
{
	for (; tmp; tmp = tmp->next)
	{
		if (find == tmp->data.a)
		{
			std::string val = tmp->data.a;
			tmp->data.a = str;
			return val;
		}
	}
	return "";
}

void clear(node *head)
{
	while (head)
	{
		node *tmp = head->next;
		delete head;
		head = tmp;
	}
}
