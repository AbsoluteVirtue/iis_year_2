#ifndef __PRODUCT__
#define __PRODUCT__

#include <string>

struct Product
{
	std::string name;
	std::string country;
	std::string manufacturer;
	std::string vender_code;
	int price;
};

void dynamic_memory(int & t, Product * & P);
Product * enter_keyboard(int t,Product * & P);
void search(Product * & P, int t);
Product * sort_array (Product * & P, int t);
Product * edit_array(int t,Product * & P);
Product * add(int *t, Product * & P);
Product * remove_element(int *t, Product * & P);
Product * insert_item(int *t,Product * & P);
void write_file(int *t,Product * & P);
void enter_file(int *t,Product * & P);
void display_array(Product * & P,int t);
Product* delete_memory(Product*  & P,int &t);

#endif
