#ifndef __MLIBRARY_H__
#define __MLIBRARY_H__

#include <string>

struct movie
{

	std::string name{""};
	std::string country{""};
	std::string producer{""};
	std::string genre{""};
	int year{0};

	void print();
};

void memoAlloc(movie **&mov, const int amountOfMovies);
void addEl(movie **&mov, const int amountOfMovies);
void massSearch(movie **&mov, const int amountOfMovies);
void massSort(movie **&mov, const int amountOfMovies);
void massElEdit(movie **&mov, const int amountOfMovies);
void massElDelete(movie **&mov, const int amountOfMovies);
void insertEl(movie **&mov, const int amountOfMovies);
void recMassInFile(movie **&mov, const int amountOfMovies, std::string *filePath);
int readMassEl(movie **&mov, const int amountOfMovies, int amountOfFilms, FILE **in);
void freeMemo(movie **&mov, const int amountOfMovies);

#endif
