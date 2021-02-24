// импортирование должно быть там, где библиотеки используются
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>
#include <iostream>
#include <conio.h>
#include <time.h>

struct Muzeu
{
	// так делать не надо
	char denumire[255];
	char adresa[255];
	int telefon;
	int cantitate;
	int pret;
};

void MemoryAllocation(struct Muzeu *&m, int &K);
void DeleteMemory(struct Muzeu *&m);

void EnterElements(struct Muzeu* &m,  int K);
void OutPutElements(struct Muzeu* &m,  int K);

void ReadFromFile(struct Muzeu* &m,  int K);
void WritetoFile(struct Muzeu* &m,  int K);

void SearchElement(struct Muzeu* &m,  int K);
void SortMuzeu(struct Muzeu* &m,  int K);

void ReWriteElement(struct Muzeu* &m,  int K);
void AddNewElement (struct Muzeu*& m,  int K);

void DeleteElement(struct Muzeu*& m,  int K);
void InsertElement(struct Muzeu*& m,  int K);
