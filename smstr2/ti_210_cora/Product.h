#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

struct Product {
	std::string name = "";
	std::string country = "";
	std::string maker = "";
	std::string vendorCode = "";
	int price = 0;
};

#endif