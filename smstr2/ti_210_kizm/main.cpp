// https://repl.it/@EverSoAnxious/MDA#main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "univ.h"

int N = 0;

int main(){
    struct University* pUniversity = NULL;

    read_file(pUniversity);

    int m;
    puts("This is a work schedule with University.");
    do{
        m = Menu();
        switch(m){
            case 1: pUniversity = input(); break;
            case 2: display(pUniversity); break;
            case 3: sort_array(pUniversity); break;
            case 4: delete_element(pUniversity); break;
            case 5: pUniversity = add_element(pUniversity); break;
            case 6: search_element(pUniversity); break;
            case 7: modify_array(pUniversity); break;
            case 8: if(pUniversity){free(pUniversity); N = 0;} break;
            case 0: if(pUniversity){free(pUniversity); N = 0;} break;
            case 11: save_in_file(pUniversity); break;
            case 22: pUniversity = read_file(pUniversity); break;
            case 33: rename_file(); break;
            case 44: delete_file(); break;
            default: puts("Incorrect option! Try again!!\n");
        }
    }while(m != 0);
    return 0;
}

