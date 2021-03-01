#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

struct Predmet
{
	void print();
	void edit(const string &t, int y, const string &f, int h);

	string title{""};
	int year{0};
	string fakultet{""};
	int hours{0};
};

size_t find_name(const std::vector<Predmet *> &array, const std::string &n);

std::ostream &operator<<(std::ostream &out, Predmet *p)
{
	out << "Predmet(title: \"" << p->title << "\", year: " << p->year << ", faculty: \"" << p->fakultet << "\", hours: " << p->hours << ")";
	return out;
}

bool compare(Predmet *lhs, Predmet *rhs);
void del(std::vector<Predmet *> &array, const size_t idx);

int main()
{
	// надо было вынести в функцию:
	FILE *input = fopen("reportcard.csv", "r");
	if (input == NULL)
		return -1;

	vector<Predmet *> mass;
	char line[100] = {};

	while (fgets(line, 100, input))
	{
		const char *delim = ",\"\n";
		char *token = strtok(line, delim);
		if (!strcmp(token, "Code"))
		{

			continue;
		}
		Predmet *tmp = new Predmet;
		while (token)
		{
			if (tmp->title == "")
			{
				tmp->title = token;
			}
			else if (tmp->year == 0)
			{
				tmp->year = atoi(token);
			}
			else if (tmp->fakultet == "")
			{
				tmp->fakultet = token;
			}
			else if (tmp->hours == 0)
			{
				tmp->hours = atoi(token);
			}
			token = strtok(NULL, delim);
		}
		cout << tmp << "\n";
		mass.push_back(tmp);
	}
	fclose(input);

	mass.pop_back();

	sort(mass.begin(), mass.end(), compare);

	// mass.insert(mass.begin(), new Predmet("Физика",3,"IT",36)); // тут нужен конструктор для  Predmet, или исправить на:
	mass.insert(mass.begin(),  new Predmet({"Физика", 3, "IT", 36}));

	del(mass, 1);

	size_t idx = find_name(mass, "UTM");
	mass[idx]->print();
	mass[idx]->edit("Физика",3,"IT",36);

	// надо было вынести в функцию:
	ofstream fout("cppishd.txt", ios::binary);
	for (auto it : mass)
	{
		fout << it << "\n";
	}
	fout.close();

	// clear(mass); // ???

	return 0;
}

void del(std::vector<Predmet *> &array, const size_t idx)
{
	if (array.size() > idx)
		array.erase(array.begin() + idx);
	return;
}

bool compare(Predmet *lhs, Predmet *rhs)
{
	return lhs->title < rhs->title;
}

void Predmet::edit(const string &t, int y, const string &f, int h)
{
	title = t;
	year = y;
	fakultet = f;
	hours = h;
}

void Predmet::print()
{
	cout << title << " " << year << " " << fakultet << " " << hours << "\n";
}

size_t find_name(const std::vector<Predmet *> &array, const std::string &n)
{
	size_t i = 0;
	for (; i < array.size(); i++)
	{
		if (array[i]->title == n)
			break;
	}

	return i;
}
