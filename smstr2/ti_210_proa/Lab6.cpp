#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "mLibrary.h"

#define symbols_of_file 1000
#define lines_of_file 12




int main(){

    movie **moviesForToday=nullptr;

    FILE* text = fopen("C:\\Users\\Hi-tech\\Desktop\\Hell\\Movies.txt", "r");

    memoAlloc(moviesForToday,lines_of_file);

    readMassEl(moviesForToday,symbols_of_file,lines_of_file,&text);

    addEl(moviesForToday,lines_of_file);

    massSort(moviesForToday,lines_of_file+1);

    insertEl(moviesForToday,lines_of_file+1);

    massSort(moviesForToday,lines_of_file+2);

    massElDelete(moviesForToday,lines_of_file+2);

    std::string rec=("C:\\Users\\Hi-tech\\Desktop\\Hell\\Movies2.txt");

    recMassInFile(moviesForToday,lines_of_file+2,&rec);

    freeMemo(moviesForToday,lines_of_file+2);
    
    return 0;
}
