#include <iostream>
#include <fstream>
#include <string>

struct T
{
	std::string s{""};
};


int main(int argc, char const *argv[])
{
	List * head = nullptr;
	
	std::ifstream in;
	in.open("census.csv");
	if (!in.is_open()) return 1;

	List * tmp = nullptr;
	std::string line;
	while (std::getline(in, line))
	{
		if (line.substr(1, 4) == "Code") continue;

	}


	return 0;
}
