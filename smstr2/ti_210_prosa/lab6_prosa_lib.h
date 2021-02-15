#ifndef __MLIBRARY_H__
#define __MLIBRARY_H__
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

struct movie {

	std::string name{""};
	std::string country{""};
	std::string producer{""};
	std::string genre{""};
	int year{ 0 };
    
    void print();

};

movie* memoAlloc(movie* mov,const int amountOfMovies);
void massSearch(movie* mov,const int amountOfMovies);
void massSort(movie* mov,const int amountOfMovies);
void massElEdit(movie* mov,const int amountOfMovies);
movie* addEl(movie* mov,const int amountOfMovies);
int massElDelete(movie* mov,const int amountOfMovies);
movie* insertEl(movie* mov,const int amountOfMovies);
int recMassInFile(movie* mov,const int amountOfMovies,std::string* filePath);
int readMassEl(movie* mov,const int amountOfMovies,FILE** in);
void freeMemo(movie* mov);

#endif