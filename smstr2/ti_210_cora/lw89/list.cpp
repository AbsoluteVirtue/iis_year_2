#include <iostream>
#include <fstream>

#include "list.h"

List::Node *List::findPrevious(int index)
{

	if (index < 0 || index > _size)
	{
		return nullptr;
	}

	Node *previous = this->Head;

	for (int i = 0; i < index - 1; ++i)
	{
		previous = previous->Next;
	}

	return previous;
}

List::List()
{
	_size = 0;
	Head = nullptr;
}

List::~List()
{
	clear();
}

int List::size()
{
	return _size;
}

void List::push_back(Product data)
{
	if (Head == nullptr)
	{
		Head = new Node(data);
	}
	else
	{

		Node *current = this->Head;

		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		current->Next = new Node(data);
	}

	_size++;
}

void List::pop_back()
{
	removeAt(_size - 1);
}

void List::push_front(Product data)
{
	Head = new Node(data, Head);
	_size++;
}

void List::pop_front()
{
	Node *tmp = Head;

	Head = Head->Next;

	delete tmp;
	_size--;
}

void List::clear()
{
	while (_size)
	{
		pop_front();
	}
}

void List::insert(Product data, int index)
{
	if (index < 0 || index > _size)
	{
		return;
	}

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node *previous = findPrevious(index);

		previous->Next = new Node(data, previous->Next);
		_size++;
	}
}

void List::removeAt(int index)
{
	if (index < 0 || index > _size - 1)
	{
		return;
	}

	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = findPrevious(index);

		Node *toDelete = previous->Next;
		previous->Next = toDelete->Next;

		delete toDelete;
		_size--;
	}
}

List::Node *List::begin()
{
	return Head;
}

List::Node *List::end()
{
	return findPrevious(_size);
}

void List::fileOut(std::string filename)
{
	std::ofstream fout;
	fout.open(filename);

	Node *current = this->Head;

	while (current != nullptr)
	{

		fout << current->Data.name << "\n";
		fout << current->Data.country << "\n";
		fout << current->Data.maker << "\n";
		fout << current->Data.vendorCode << "\n";
		fout << current->Data.price << "\n";
		fout << std::endl;

		current = current->Next;
	}

	fout.close();
}

void List::fileIn(std::string filename)
{
	std::ifstream fin;
	fin.open(filename);

	if (!fin.is_open())
	{
		return;
	}

	std::string str;
	Product tmp;
	int it = 1;

	while (std::getline(fin, str, '\n'))
	{
		switch (it)
		{
		case 1:
			tmp.name = str;
			++it;
			break;
		case 2:
			tmp.country = str;
			++it;
			break;
		case 3:
			tmp.maker = str;
			++it;
			break;
		case 4:
			tmp.vendorCode = str;
			++it;
			break;
		case 5:
			tmp.price = std::stoi(str);
			++it;
			push_back(tmp);
			break;
		case 6:
			it = 1;
			break;
		}
	}
	fin.close();
}

void List::swap(int index1, int index2)
{
	if (index1 == index2)
	{
		return;
	}

	Product tmp1 = findPrevious(index1 + 1)->Data;
	Product tmp2 = findPrevious(index2 + 1)->Data;

	removeAt(index1);
	insert(tmp2, index1);

	removeAt(index2);
	insert(tmp1, index2);
}

void List::sort()
{
	for (int i = 0; i < _size; ++i)
	{
		int ctr = 0;

		for (Node *j = Head; j != end(); j = j->Next)
		{
			if (ctr == ctr + 1)
			{
				break;
			}

			if (j->Data.name > j->Next->Data.name)
			{
				swap(ctr, ctr + 1);
			}
			ctr++;
		}
	}
}

void List::editData(int index)
{
	Product tmp = findPrevious(index + 1)->Data;
	find(index);

	while (true)
	{
		int num;
		std::cout << "Enter number (1-5) to change data or any other to exit: ";
		std::cin >> num;
		std::cout << std::endl;

		switch (num)
		{
		case 1:
			std::cout << "Change name of product: ";
			std::cin >> tmp.name;
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Change country of product: ";
			std::cin >> tmp.country;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "Change maker of product: ";
			std::cin >> tmp.maker;
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "Change vendor code of product: ";
			std::cin >> tmp.vendorCode;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << "Change price of product: ";
			std::cin >> tmp.price;
			std::cout << std::endl;
			break;
		default:
			removeAt(index);
			insert(tmp, index);

			return;
		}
	}
}

void List::find(int index)
{
	std::cout << "Data of " << index << "'nd element is: " << std::endl;
	printElem(index);
}

void List::print()
{
	Node *current = this->Head;

	while (current != nullptr)
	{

		std::cout << current->Data.name << std::endl;
		std::cout << current->Data.country << std::endl;
		std::cout << current->Data.maker << std::endl;
		std::cout << current->Data.vendorCode << std::endl;
		std::cout << current->Data.price << std::endl;
		std::cout << std::endl;

		current = current->Next;
	}
}

void List::printElem(int index)
{
	Node *tmp = findPrevious(index + 1);

	std::cout << "1." << tmp->Data.name << std::endl;
	std::cout << "2." << tmp->Data.country << std::endl;
	std::cout << "3." << tmp->Data.maker << std::endl;
	std::cout << "4." << tmp->Data.vendorCode << std::endl;
	std::cout << "5." << tmp->Data.price << std::endl;
	std::cout << std::endl;
}

void List::input()
{
	std::cout << "Enter number of elements: ";
	int num;
	std::cin >> num;

	for (int i = 0; i < num; ++i)
	{
		Product tmp;
		std::cout << "Enter name: ";
		std::cin >> tmp.name;
		std::cout << "Enter country: ";
		std::cin >> tmp.country;
		std::cout << "Enter maker: ";
		std::cin >> tmp.maker;
		std::cout << "Enter vendor code: ";
		std::cin >> tmp.vendorCode;
		std::cout << "Enter price: ";
		std::cin >> tmp.price;
		push_back(tmp);
	}
}

void List::uniteList(List &lst)
{
	Node *current = lst.Head;

	while (current != nullptr)
	{
		Product tmp = current->Data;
		push_back(tmp);

		current = current->Next;
	}
}

void List::devideList(List &lst, int index)
{
	Node *previous = findPrevious(index);

	if (lst.Head == nullptr)
	{
		lst.Head = previous->Next;
		previous->Next = nullptr;

		lst._size += _size - index;
		_size = _size - (_size - index);
	}
	else
	{
		Node *current = lst.Head;

		while (current->Next != nullptr)
		{
			current = current->Next;
		}

		current->Next = previous->Next;
		previous->Next = nullptr;

		lst._size += _size - index;
		_size = _size - (_size - index);
	}
}
