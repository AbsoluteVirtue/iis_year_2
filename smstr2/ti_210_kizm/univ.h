// где защита от множественного импортирования
// библиотеки лучше не включать там, где они не используются
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct University{
    char name[50];  // так лучше не делать, если оно не используется для принудительного ограничения ввода
    char adress[50];
    unsigned short phoneNum;
    unsigned short faculty;
    unsigned peopleNum;
};

int Menu(void);

void kboard_input(int n, struct University* pUniversity);
void loop_input(struct University* pUniversity);
struct University* input(void); 
void display(struct University* pUniversity);

int sort_array(struct University* pUniversity);   
int facultycmp(const void* a, const void* b);
int namecmp(const void* a, const void* b);

void delete_element(struct University* pUniversity);
struct University* add_element(struct University* pUniversity);
void modify_array(struct University* pUniversity);
void search_element(struct University* pUniversity);  

void save_in_file(struct University* pUniversity);
struct University* read_file(struct University* pUniversity);
void rename_file(void);
void delete_file(void);
