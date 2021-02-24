
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Muzeu.h"

// где массив указателей?

void MemoryAllocation(struct Muzeu *&m, int &K)
{
	m = new Muzeu[K];
	if (m == NULL) // эта проверка не сработает, нужно так: new (std::nothrow) Muzeu[K];
	{
		printf("\n Memoria dinamica nu este impartita");
		exit(1);
	}
	else
	{
		printf("\n Memoria e impartita de %d bytes", K * sizeof(Muzeu));
	}
}

void DeleteMemory(struct Muzeu *&m)
{
	delete[] m;
	m = 0;
}

void EnterElements(struct Muzeu *&m, int K)
{
	for (int i = 0; i < K; i++)
	{
		printf("\n");
		scanf("%s", &m[i].denumire);
		scanf("%s", &m[i].adresa);
		scanf("%d", &m[i].telefon);
		scanf("%d", &m[i].cantitate);
		scanf("%d", &m[i].pret);
	}
}

void OutPutElements(struct Muzeu *&m, int K)
{

	for (int i = 0; i < K; i++)
	{
		printf("\n");

		printf("%s", m[i].denumire);
		printf("%s", m[i].adresa);
		printf("%d", m[i].telefon);
		printf("%d", m[i].cantitate);
		printf("%d\n", m[i].pret);
	}
}

void ReadFromFile(struct Muzeu *&m, int K)
{
	FILE *file;
	file = fopen("Muzeu.txt", "r"); // не стоит хардкодить название файла
	for (int i = 0; i < K; i++)		// чтение должно работать независимо от количества строк в файле
	{
		fscanf(file, "%s", &m[i].denumire, 255);
		fscanf(file, "%s", &m[i].adresa, 255);
		fscanf(file, "%d", &m[i].telefon);
		fscanf(file, "%d", &m[i].cantitate);
		fscanf(file, "%d", &m[i].pret);
	}
	fclose(file);
}

void WritetoFile(struct Muzeu *&m, int K)
{
	FILE *file;
	file = fopen("Muzeu.txt", "w");
	for (int i = 0; i < K; i++)
	{
		fprintf(file, "%s ", m[i].denumire);
		fprintf(file, "%s ", m[i].adresa);
		fprintf(file, "%d ", m[i].telefon);
		fprintf(file, "%d ", m[i].cantitate);
		fprintf(file, "%d\n ", m[i].pret);
	}
	fclose(file);
}

void SearchElement(struct Muzeu *&m, int K)
{
	int choice = 0;

	// должно быть вне функции
	printf("Alegeti un mod prin care puteti afla muzeul:\n");
	printf("1.Denumire muzeului\n");
	printf("2.Adresa muzeului\n");
	printf("3.Pretul biletului\n");
	printf("Alegerea voastra:");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	{
		// вместо копирования кода для каждого варианта надо было его вынести в функцию
		Muzeu c;
		bool fun = false;
		printf("Scrieti denumire muzeului:");
		scanf("%s", c.denumire, 255);
		printf("\n");

		for (int i = 0; i < K; i++)
		{
			if (!(strcmp(m[i].denumire, c.denumire)))
			{
				printf("|\n");

				printf("%s", &m[i].denumire);
				printf("%s", &m[i].adresa);
				printf("%d", &m[i].telefon);
				printf("%d", &m[i].cantitate);
				printf("%d\n", &m[i].pret);
				fun = true;
			}
		}
		if (fun == false)
		{
			printf("Acasta denumire nu exista! ");
		}
	}
	break;
	case 2:
	{
		Muzeu c;
		bool fun = false;
		printf("Scrieti adresa muzeului:");
		scanf("%s", c.adresa, 255);
		printf("\n");

		for (int i = 0; i < K; i++)
		{
			if (!(strcmp(m[i].adresa, c.adresa)))
			{
				printf("\n");

				printf("%s", m[i].denumire);
				printf("%s", m[i].adresa);
				printf("%d", m[i].telefon);
				printf("%d", m[i].cantitate);
				printf("%d\n", m[i].pret);
				fun = true;
			}
		}
		if (fun == false)
		{
			printf("Aceasta adresa nu exista!");
		}
	}
	break;
	case 3:
	{
		int a = 0;
		bool fun = false;
		printf("Scrieti pretul biletului:");
		scanf("%d", &a);
		printf("\n");

		for (int i = 0; i < K; i++)
		{
			if (a > 0 && a == m[i].pret)
			{
				printf("\n");

				printf("%s", m[i].denumire);
				printf("%s", m[i].adresa);
				printf("%d", m[i].telefon);
				printf("%d", m[i].cantitate);
				printf("%d\n", m[i].pret);
				fun = true;
			}
		}
		if (fun == false)
		{
			printf("Acest pret nu exista!");
		}
	}
	break;
	default:
		printf("Acest punct nu exista");
		break;
	}
}

void SortMuzeu(struct Muzeu *&m, int K)
{
	// пора уже забыть о сортировке пузырьком
	Muzeu temp;
	for (int i = 0; i < K; i++)
	{
		for (int j = K - 1; j >= i + 1; j--)
		{
			if (m[j].pret > m[j - 1].pret)
			{
				temp = m[j];
				m[j] = m[j - 1];
				m[j - 1] = temp;
			}
		}
	}
}

void ReWriteElement(struct Muzeu *&m, int K)
{
	int ReWrite;
	printf("Scrieti numarul obiectului care doriti sa corectati:");
	scanf("%d", &ReWrite);
	if (ReWrite > 0 && ReWrite <= K)
	{
		// должно быть вне функции
		printf("Scrieti elementul nou...\n");
		printf("Scrieti denumire muzeului:");
		scanf("%s", &m[ReWrite - 1].denumire, 255);
		printf("Scrieti adresa:");
		scanf("%s", &m[ReWrite - 1].adresa, 255);
		printf("Scrieti telefonul muzeului:");
		scanf("%d", &m[ReWrite - 1].telefon);
		printf("Scrieti cantitate exponatelor:");
		scanf("%d", &m[ReWrite - 1].cantitate);
		printf("Scrieti pretul biletului:");
		scanf("%d", &m[ReWrite - 1].pret);
	}
	else
	{
		printf("Acest element nu exista!");
	}
}

void AddNewElement(struct Muzeu *&m, int K)
{
	Muzeu *NewMuzeu = new Muzeu[K + sizeof(1)]; // sizeof не нужен, new принимает количество элементов, а не байтов
	for (int i = 0; i < K; i++)
	{
		NewMuzeu[i] = m[i];
	}

	// должно быть вне функции
	printf("Scrieti un element nou...\n");
	printf("Scrieti denumire muzeului:");
	scanf("%s", &NewMuzeu[K].denumire, 255);
	printf("Scrieti adresa muzeului:");
	scanf("%s", &NewMuzeu[K].adresa, 255);
	printf("Scrieti telefonul muzeului:");
	scanf("%d", &NewMuzeu[K].telefon);
	printf("Scrieti cantitete exponatelor:");
	scanf("%d", &NewMuzeu[K].cantitate);
	printf("Scrieti pretul biletului:");
	scanf("%d", &NewMuzeu[K].pret);

	K++;
	delete[] m;
	m = NewMuzeu;
}

void DeleteElement(struct Muzeu *&m, int K)
{
	int i = 0;
	K--;
	Muzeu *NewMuzeu = new Muzeu[K];
	
	// должно быть вне функции
	printf("Scrieti numarul elementului care doriti sa stergeti:");
	scanf("%d", &i);
	if (i > K) // >=
	{
		printf("Acest element nu exista!\n");
	}
	else
	{
		for (i; i < K; i++)
		{
			m[i] = m[i + 1];
		}

		for (int i = 0; i < K; i++)
		{
			NewMuzeu[i] = m[i];
		}

		delete[] m;
		m = NewMuzeu;
	}
}

void InsertElement(struct Muzeu *&m, int K)
{
	int pos = 0;

	// должно быть вне функции
	printf("Scrieti numarul elementului sub care trebuie sa puneti un element nou :");
	scanf("%d", &pos);

	pos--;
	Muzeu *NewMuzeu = new Muzeu[K + sizeof(1)];
	for (int i = 0; i < K; i++)
	{
		if (i < pos)
		{
			NewMuzeu[i] = m[i];
		}
		else
		{
			NewMuzeu[i + 1] = m[i];
		}
	}

	// должно быть вне функции
	printf("Scrieti un element nou...\n");
	printf("Scrieti denumire muzeului:");
	scanf("%s", NewMuzeu[pos].denumire, 255);
	printf("Scrieti adresa muzeului:");
	scanf("%s", NewMuzeu[pos].adresa, 255);
	printf("Scrieti telefonul muzeului:");
	scanf("%d", &NewMuzeu[pos].telefon);
	printf("Scrieti cantitate exponatelor:");
	scanf("%d", &NewMuzeu[pos].cantitate);
	printf("Scrieti pretul biletului:");
	scanf("%d", &NewMuzeu[pos].pret);

	K++;
	delete[] m;
	m = NewMuzeu;
}
