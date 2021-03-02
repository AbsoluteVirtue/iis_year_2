#include <iostream>
#include <string>

struct T
{
	std::string s{""};
};

struct List
{
	List * next{nullptr};
	T * data{nullptr};

	void print()
	{
		for (List * tmp = this; tmp; tmp = tmp->next)
		{
			std::cout << tmp->data->s << "\n";
		}
	}

	void edit(size_t pos, const std::string & str)
	{
		size_t i = 0;
		for (List * tmp = this; tmp; tmp = tmp->next) 
		{
			if (i == pos)
			{
				tmp->data->s = str;
				break;
			}
			++i;
		}
	}

	const T * find(const std::string & str)
	{
		for (List * tmp = this; tmp; tmp = tmp->next)
		{
			if (tmp->data->s.substr(1, 4) == str) 
				return tmp->data;
		}
		return nullptr;
	}

	static void clear(List * & h)
	{
		while (h)
		{
			List * tmp = h->next;
			delete h;
			h = tmp;
		}
	}

	static void split(List * h, List * & l, List * & r)
	{
		List * left = h->next;
		List * right = h;

		while(left) 
		{
			left = left->next;
			if (left)
			{
				right = right->next;
				left = left->next;
			}
		}

		l = h;
		r = right->next;
		right->next = nullptr;
	}

	static void merge(List * & h, List * & l, List * & r)
	{
		List * tmp = nullptr;

		if (!l)
		{
			h = r;
			return;
		}
		else if (!r)
		{
			h = l;
			return;
		}

		if (l->data->s <= r->data->s)
		{
			tmp = l;
			merge(tmp->next, l->next, r);
		}
		else
		{
			tmp = r;
			merge(tmp->next, l->next, r->next);
		}
		h = tmp;
	}

	static void reverse(List * & source)
	{
		if (!source || !source->next) return;

		for (List * i = source; i; i = i->next)
		{
			for (List * tmp = i->next; tmp; tmp = tmp->next)
			{
				std::swap(i->data, tmp->data);
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	List * head = new List;

	head->data = new T({"Rest1"});

	head->next = new List;
	
	head->next->data = new T({"Best2"});

	head->print();

	List::reverse(head);

	head->print();

	List::clear(head);

	return 0;
}
