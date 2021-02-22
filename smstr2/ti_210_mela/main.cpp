#include <iostream>
#include "Univer.h"

int main() {
	Univer x = { "UTM", "Rishkanovka", 02556453, 10, 1000 };
	Univer y = { "GOS", "Centru", 0222312, 5, 500 };
	Univer z = { "ULIM", "Botanika", 02365645, 8, 1300 };

	basee uni;
	uni.push_back(x);
	uni.push_back(y);
	uni.push_back(z);
	uni.onScreen();

	return 0;
}