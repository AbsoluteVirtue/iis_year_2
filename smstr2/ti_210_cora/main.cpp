#include <iostream>
#include "Base.h"

int main() {

	Product x = { "IceCream", "USA", "Dood", "X-004", 100 };
	Product y = { "Morogenoie", "USSR", "Ebou", "Y-004", 40 };
	Product z = { "Ingetata", "Moldova", "Joc", "Z-004", 2 };
	Product a = { "FREA", "FHAF", "yer", "HG-432", 13891 };

	Base arr;
	arr.push_back(x);
	arr.push_back(y);
	arr.push_back(z);
	arr.push_back(a);
	arr.erase(1);
	arr.onScreen();
	std::cout << std::endl << std::endl;
	arr.insert(4, x);
	arr.onScreen();
	std::cout << std::endl << std::endl;
	/*arr.edit(4);
	arr.onScreen();*/
	/*arr.onFile("output.txt");*/
	arr.fromFile("input.txt");
	/*arr.onScreen();
	arr.sort();*/
	arr.onScreen();
	/*arr.fromKeyboard();
	arr.onScreen();*/


	return 0;
}