#include <iostream>
#include "list.h"

int main() {

	Product x = { "IceCream", "USA", "Dood", "X-004", 100 };
	Product y = { "Morogenoie", "USSR", "Ebou", "Y-004", 40 };
	Product z = { "Ingetata", "Moldova", "Joc", "Z-004", 2 };
	Product a = { "FREA", "FHAF", "yer", "HG-432", 13891 };

	List lst;

	//lst.push_back(x);
	//lst.push_back(y);
	//lst.push_back(z);
	//lst.push_back(a);

	lst.fileIn("input.txt");
	/*lst.fileOut("output.txt");*/

	lst.print();

	return 0;
}