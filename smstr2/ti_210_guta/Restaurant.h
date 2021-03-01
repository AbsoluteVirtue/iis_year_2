#ifndef _Funct.h_

#define _Funct .h_

#include <string>

using namespace std; // так не надо делать, особенно в заголовочном файле

struct Restaurant
{
    string NAME = "";
    string ADRESS = "";
    string phone = "";
    string category = "";
    string places = "";
    string spec = "";
};

typedef Restaurant* pRestaurant;

void file_read(pRestaurant *_P_OBJECT, FILE *file_name);
void option_change(int object_size, pRestaurant *_P_OBJECT);
void _search(int object_size, pRestaurant *_P_OBJECT);
void _sort(int *object_size, pRestaurant *_P_OBJECT);
void _push_back(int *object_size, pRestaurant *&_P_OBJECT);
void _erase(int *object_size, pRestaurant *&_P_OBJECT);
void _push(int *object_size, pRestaurant *&_P_OBJECT);
void struct_inputn(int object_number, pRestaurant *&_P_OBJECT);
void single_out(int object_number, pRestaurant *_P_OBJECT);
void all_out(int *object_size, pRestaurant *_P_OBJECT);

#endif
