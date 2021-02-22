// защита от множественных включений в объектный файл?
#include <iostream>

struct computer{
    char* model{nullptr};
    char* processor{NULL};
    int memory {0};
    int speed {0};
    int price {0};
};

// массив указателей где?
struct vector{
    int size{0};
    computer* first{NULL};
    computer* last{NULL};
    computer* position{NULL};

    void print();
    void resize(bool extra_mem, int free_slots);
    void create();
    void open(FILE * input);
    void find_model(char* str);
    void edit(int number, computer element);
    void del(int number);
    void push_back(computer element);
    void insert(int number, computer element);
    void sort_price();
    void output(FILE * output);
    void clean_up();
};
