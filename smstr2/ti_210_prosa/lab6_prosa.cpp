#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "lab6_prosa_lib.h"

#define symbols_of_file 1000
#define lines_of_file 13

int main(){

    movie *moviesForToday=nullptr;

    FILE* text = fopen("mov.txt", "r");

    moviesForToday=memoAlloc(moviesForToday,lines_of_file);

    readMassEl(moviesForToday,symbols_of_file,&text);

    moviesForToday=addEl(moviesForToday,lines_of_file);

    massSort(moviesForToday,lines_of_file);

    moviesForToday=insertEl(moviesForToday,lines_of_file+1);

    massSort(moviesForToday,lines_of_file+1);

    massElDelete(moviesForToday,lines_of_file+2);

    std::string rec=("mov2.txt");

    recMassInFile(moviesForToday,lines_of_file+2,&rec);

    freeMemo(moviesForToday);
    
    return 0;
}