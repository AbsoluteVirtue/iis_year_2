#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "univ.h"

extern int N; // лучше передавать как аргумент

void kboard_input(int n, struct University *pUniversity)
{
	char str[210];

	printf("Name: ");
	scanf("%s", str);
	strcpy((pUniversity + n)->name, str);

	printf("Adress: ");
	scanf("%s", str);
	strcpy((pUniversity + n)->adress, str);

	printf("Telephone: ");
	scanf("%hu", &(pUniversity + n)->phoneNum);
	printf("faculty: ");
	scanf("%hu", &(pUniversity + n)->faculty);
	printf("People number: ");
	scanf("%u", &(pUniversity + n)->peopleNum);

	printf("\n");
}

void loop_input(struct University *pUniversity)
{
	for (int i = 0; i < N; i++)
	{
		printf("University number #%d :\n", i + 1);
		kboard_input(i, pUniversity);
	}
}

struct University *input()
{
	int excep = N; // а первоначальное значение N чему равно?
	printf("Enter number of University: ");
	scanf("%d", &N); // про ввод с клавиатуры уже много раз говорили
	if (N <= 0)
	{
		printf("The number of University must be positive!\n");
		N = excep;
	}
	struct University *pUniversity = (struct University *)malloc(N * sizeof(struct University));
	// желательно проверять указатель, если память действительно была выделена
	loop_input(pUniversity);
	return pUniversity;
}

void display(struct University *pUniversity)
{
	if (N == 0)
	{
		printf("OS didn't gave you memory.\n");
	}
	printf("List of University: \n"
		   "|  Nr  | University name\t\t\t| Adress\t\t\t\t| Telephone\t| faculty\t| People |\n"
		   "|------|--------------------------------|----------------------------------            -----|---------------|-------|--------|\n");
	int UniversityNumber = 0; // зачем переменная?
	for (int i = 0; i < N; i++)
	{
		printf("| %3d  | %-30s | %-37s | %-13s | %3hu   | %4u   |\n",
			   i + 1,
			   (pUniversity + i)->name,
			   (pUniversity + i)->adress,
			   (pUniversity + i)->phoneNum,
			   (pUniversity + i)->faculty,
			   (pUniversity + i)->peopleNum);
		UniversityNumber++;
	}
	printf("|------------------------------------------------------------------------    ----------------------------------------|\n");
	printf("%d University found\n", UniversityNumber);
}

int facultycmp(const void *a, const void *b)
{
	return ((University *)a)->faculty - ((University *)b)->faculty;
}

int namecmp(const void *a, const void *b)
{
	return strcmp(((University *)a)->name, ((University *)b)->name);
}

int sort_array(struct University *pUniversity)
{
	int option = 0;
	printf("Select the method to sort: \n"
		   "1 -- Sort by faculty\n"
		   "2 -- Sort by name");
	scanf("%d", &option);
	if (option == 1)
		qsort(pUniversity, N, sizeof(struct University), facultycmp);
	else if (option == 2)
		qsort(pUniversity, N, sizeof(struct University), namecmp);
	else
		printf("Incorrect option!");
	display(pUniversity);
}

void delete_element(struct University *pUniversity)
{
	int del;
	printf("Enter the University number you want to delete: ");
	scanf("%d", &del);
	if (del < 1 || del > N)
	{
		printf("Inexistent University number.\n");
		return;
	}
	del--;
	for (int i = del; i < N - 1; i++)
		pUniversity[i] = pUniversity[i + 1];
	pUniversity = (struct University *)realloc(pUniversity, --N * sizeof(struct University)); // не стоит делать каждый раз, неэффективное использвоание
	printf("University #%d was successfully eliminated!\n", ++del);
}

struct University *add_element(struct University *pUniversity)
{
	pUniversity = (struct University *)realloc(pUniversity, ++N * sizeof(struct University));
	printf("Enter data about University No#%d: \n", N + 1);
	kboard_input(N - 1, pUniversity);
	return pUniversity;
}

void modify_array(struct University *pUniversity)
{
	int num;
	printf("Enter element to modify: ");
	scanf("%d", &num);
	printf("Enter data about University No#%d: \n", num);
	num--;
	kboard_input(num, pUniversity);
}

void search_element(struct University *pUniversity)
{
	char localName[30];
	bool show = true;
	printf("Enter University name: ");
	scanf("%s", &localName);
	for (int i = 0; i < N; ++i)
	{
		if (strcmp(pUniversity[i].name, localName) == 0)
			printf("| %3d  | %-30s | %-37s | %-13hu | %3hu   | %4u   |\n",
				   i + 1,
				   pUniversity[i].name,
				   pUniversity[i].adress,
				   pUniversity[i].phoneNum,
				   pUniversity[i].faculty,
				   pUniversity[i].peopleNum);
		else
			show = false;
	}
	if (!show)
		printf("Non-existent name University.\n");
}

void save_in_file(struct University *pUniversity)
{
	char filename[30];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE *file = fopen(filename, "wbx");
	if (!file)
	{
		perror("Error open file");
	}
	else
	{
		fwrite(&N, sizeof(int), 1, file);
		fwrite(pUniversity, sizeof(struct University), N, file);
		printf("Data is saved successfully\n");

		if (fclose(file) != 0)
			perror("Error close file");
	}
}

struct University *read_file(struct University *pUniversity)
{
	char filename[30];
	printf("Enter file name: ");
	scanf("%s", filename);
	FILE *file = fopen(filename, "rb");
	if (!file)
		perror("Error open file");
	else
	{
		fread(&N, sizeof(int), 1, file);
		pUniversity = (struct University *)malloc(N * sizeof(struct University));
		fread(pUniversity, sizeof(struct University), N, file);
		display(pUniversity);
		printf("Successfully print\n");

		if (fclose(file) != 0)
			perror("Error close file");
	}
	return pUniversity;
}

void rename_file()
{
	char oldName[30], newName[30];
	printf("Type current file name: ");
	scanf("%s", oldName);
	printf("Type new file name: ");
	scanf("%s", newName);
	if ((rename(oldName, newName)) == 0)
		printf("Successfully renamed");
	else
		perror("Unable to rename the file");
}

void delete_file()
{
	int result;
	char fileName[30];
	printf("Type file name: ");
	scanf("%s", fileName);
	if (remove(fileName) == 0)
		printf("Deleted successfully");
	else
		perror("Unable to delete the file");
}

int Menu()
{
	system("pause");
	system("cls");
	printf("1. Input\n"
		   "2. Display\n"
		   "3. Sort by faculty/name\n"
		   "4. Delete University\n"
		   "5. Add University\n"
		   "6. Search by name\n"
		   "7. Modify array\n"
		   "8. Free allocated memory\n"
		   "-----------------------------------------------------------------------\n"
		   "| 11. Save in file | "
		   "22. Read file |"
		   "33. Rename file | "
		   "44. Delete file |\n"
		   "-----------------------------------------------------------------------\n"
		   "0. Exit\n");
	int m;
	scanf("%d", &m);
	return m;
}
