#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
// #include <stdio.h>
#include "kniga.h"


void Output(kniga **& library, int & size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "�����: " << library[i]->avtor << std::endl;
        std::cout << "��������: " << library[i]->nazv << std::endl;
        std::cout << "���: " << library[i]->god << std::endl;
        std::cout << "�������: " << library[i]->izdanie << std::endl;
        std::cout << "�������: " << library[i]->str << std::endl;
        std::cout << "�����: " << library[i]->tir << std::endl;
        std::cout << "------------------------------------------" << std::endl << std::endl;
    }
} 

kniga ** PushBack(kniga ** & library, int & size)
{
    char musor[2] = {};
    kniga** librarycopy = nullptr;
    librarycopy = new kniga * [size+1];
    // почему +2?
    for (int i = 0; i < size + 2; i++)
    {
        librarycopy[i] = new kniga;
    }
    
    for (int i = 0; i < size; i++)
    {
        librarycopy[i]->avtor = library[i]->avtor;
        librarycopy[i]->nazv = library[i]->nazv;
        librarycopy[i]->god = library[i]->god;
        librarycopy[i]->izdanie = library[i]->izdanie;
        librarycopy[i]->str = library[i]->str;
        librarycopy[i]->tir = library[i]->tir;
    }   

    // где delete[] library[i]; ?
    delete[] library;

    librarycopy[size]->avtor = new char[40];
    std::cout << "������� ������ - ";
    std::cin.getline(librarycopy[size]->avtor, 40);

    librarycopy[size]->nazv = new char[40];
    std::cout << "������� �������� ����� - ";
    std::cin.getline(librarycopy[size]->nazv, 40);

    librarycopy[size]->izdanie = new char[30];
    std::cout << "������� ������� - ";
    std::cin.getline(librarycopy[size]->izdanie, 30);

    std::cout << "������� ��� - ";
    std::cin >> librarycopy[size]->god;

    std::cout << "������� �������� - ";
    std::cin >> librarycopy[size]->str;

    std::cout << "������� ����� - ";
    std::cin >> librarycopy[size]->tir;

    size = size++;
    std::cin.getline(musor, 2);
    return librarycopy;

}

void SearchBook(kniga **& library, int & size)
{
    int menu = 0;
   
    int flagfind = 0;
    char musor[2] = {};
    std::cout << "1. ����� �� ����� ������" << std::endl;
    std::cout << "2. ����� �� �������� �����" << std::endl;
    std::cout << "3. ���������� �����" << std::endl;
    std::cin >> menu;

    while (1)
    {
        if (menu == 1)
        {
            char avtor[40] = {};
            std::cout << "������� ��� ������ - ";
            std::cin.getline(avtor, 40);
            std::cin.getline(avtor, 40);
            for (int i = 0; i < size; i++)
            {
                if (!strcmp(avtor, library[i]->avtor))
                {
                    flagfind = 1;
                    std::cout << "�����: " << library[i]->nazv << ", " << library[i]->god << " ��� �������." << std::endl;
                }
            }
            if (!flagfind)
            {
                std::cout << "�� ����� ������ �� ������� �� ����� �����. ��������� ������������ �����" << std::endl;
            }
            
        }
        else if (menu == 2)
        {
            char avtor[40] = {};
            std::cout << "������� �������� ����� - ";
            std::cin.getline(avtor, 40);
            std::cin.getline(avtor, 40);
            for (int i = 0; i < size; i++)
            {
                if (!strcmp(avtor, library[i]->nazv))
                {
                    flagfind = 1;
                    std::cout << "�����: " << library[i]->avtor << ", " << library[i]->god << " ��� �������." << std::endl;
                }
            }
            if (!flagfind)
            {
                std::cout << "�� ���� ����� ������ �� �������. ��������� ������������ �����" << std::endl;
            }
        }
        else if (menu == 3)
        {
            std::cin.getline(musor, 2);
            return;
        }
        flagfind = 0;
        std::cout << std::endl << "1. ����� �� ����� ������" << std::endl;
        std::cout << "2. ����� �� �������� �����" << std::endl;
        std::cout << "3. ���������� �����" << std::endl << std::endl;
        std::cin >> menu;
    }

}

void DeleteBook(kniga**& library, int & size)
{
   
    char buf[50];
    int save = -1;
    std::cout << "������� �������� �����, ������� ����� ������� - ";

    std::cin.getline(buf, 50);
    
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(buf, library[i]->nazv))
        {
            save = i;
            break;
        }
    }

    if (save == -1)
    {
        return;
    }
    if (library[save + 1]->nazv == NULL) // надо проверять, если save + 1 не выходит за пределы массива
    {
        library[save]->avtor = nullptr;
        library[save]->nazv = nullptr;
        library[save]->god = 0;
        library[save]->izdanie = nullptr;
        library[save]->str = 0;
        library[save]->tir = 0;
    }
    else
    {
        for (int i = save; i < size-1; i++)
        {
            if (library[i + 1]->nazv != NULL)
            {
                library[i]->avtor = library[i + 1]->avtor;
                library[i]->nazv = library[i + 1]->nazv;
                library[i]->god = library[i + 1]->god;
                library[i]->izdanie = library[i + 1]->izdanie;
                library[i]->str = library[i + 1]->str;
                library[i]->tir = library[i + 1]->tir;
                
            }

        }
        library[size - 1]->avtor = nullptr;
        library[size - 1]->nazv = nullptr;
        library[size - 1]->god = 0;
        library[size - 1]->izdanie = nullptr;
        library[size - 1]->str = 0;
        library[size - 1]->tir = 0;
       
    }
    delete library[size - 1];
    size = size--;
}


void SortLibrary(kniga**& library, int & size)
{
    int menu = 0;
    kniga* bufer;
    char musor[5];
    std::cout << std::endl << "1. ��� ���������� �� ���������� ������� " << std::endl;
    std::cout << "2. ��� ���������� �� ���� ������� " << std::endl;
    std::cout << "3. ��� ���������� �� ������ " << std::endl;
    std::cout << "4. ����� " << std::endl;
    std::cin >> menu;
    while (1)
    {
        if (menu == 1)
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    if (i + 1 < size)
                    {
                        if (library[i]->str > library[i + 1]->str)
                        {
                            bufer = library[i];
                            library[i] = library[i + 1];
                            library[i + 1] = bufer;

                        }
                    }

                }
            }

            Output(library,size);
        }
        else if (menu == 2)
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    if (i + 1 < size)
                    {
                        if (library[i]->god > library[i + 1]->god)
                        {
                            bufer = library[i];
                            library[i] = library[i + 1];
                            library[i + 1] = bufer;

                        }
                    }

                }
            }
            Output(library,size);
        }
        else if (menu == 3)
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size; i++)
                {
                    if (i + 1 < size)
                    {
                        if (library[i]->tir > library[i + 1]->tir)
                        {
                            bufer = library[i];
                            library[i] = library[i + 1];
                            library[i + 1] = bufer;

                        }
                    }

                }
            }
            Output(library,size);
        }
        else if (menu == 4)
        {
            std::cin.getline(musor, 5);
            return;
        }
        std::cout << std::endl << "1. ��� ���������� �� ���������� ������� " << std::endl;
        std::cout << "2. ��� ���������� �� ���� ������� " << std::endl;
        std::cout << "3. ��� ���������� �� ������ " << std::endl;
        std::cout << "4. ����� " << std::endl;
        std::cin >> menu;
    }
}

kniga** finput(kniga** & library, int & size)
{
    FILE* fp;
    char tok[2] = ",";
    char* strsep = {};
    char* str = nullptr;
    str = (char*)malloc(100);
    int i = 0;

    fp = fopen("lib.txt", "r");

    library = new kniga * [size];
    i = 0;
    while (fgets(str, 100, fp))
    {
        library[i] = new kniga;
        strsep = strtok(str, tok);
        while (strsep)
        {
            if (library[i]->avtor == nullptr)
            {
                library[i]->avtor = new char[strlen(strsep) + 1];
                strcpy(library[i]->avtor, strsep);
            }
            else if (library[i]->nazv == nullptr)
            {
                library[i]->nazv = new char[strlen(strsep) + 1];
                strcpy(library[i]->nazv, strsep);
            }
            else if (library[i]->god == 0)
            {
                library[i]->god = (int)atol(strsep);
            }
            else if (library[i]->izdanie == nullptr)
            {
                library[i]->izdanie = new char[strlen(strsep) + 1];
                strcpy(library[i]->izdanie, strsep);
            }
            else if (library[i]->str == 0)
            {
                library[i]->str = (int)atol(strsep);
            }
            else if (library[i]->tir == 0)
            {
                library[i]->tir = (int)atol(strsep);
            }

            strsep = strtok(NULL, tok);
        }
        ++i;

    }
    fclose(fp);
    return library;
}

void EditBook(kniga **& library, int & size)
{
    char buf[8][50] = {};
    
    std::cout << "������� �������� �����, ������� ����� ��������������� - ";
    std::cin.getline(buf[0], 50);

    for (int i = 0; i < size; i++)
    {
        if (!strcmp(buf[0], library[i]->nazv))
        {
            std::cout << "������� ����� �������� ��� �������������� ����. � ������, ���� �������� ���� �� �����, ������� ������� '-' " << std::endl;
            std::cout << "������� ������ - ";

            std::cin.getline(buf[1], 50);
            library[i]->avtor = (strcmp(buf[1], "-")) ? strcpy(library[i]->avtor, buf[1]) : library[i]->avtor;

            std::cout << "������� �������� ����� - ";
            std::cin.getline(buf[2], 50);
            library[i]->nazv = (strcmp(buf[2], "-")) ? strcpy(library[i]->nazv, buf[2]) : library[i]->nazv;
            
            std::cout << "������� ������� - ";
            std::cin.getline(buf[3], 50);
            library[i]->izdanie = (strcmp(buf[3], "-")) ? strcpy(library[i]->izdanie, buf[3]) : library[i]->izdanie;

            std::cout << "������� ��� - ";
            std::cin >> buf[4]; 
            library[i]->god = (strcmp(buf[4], "-")) ? (int)atol(buf[4]) : library[i]->god;

            std::cout << "������� �������� - ";
            std::cin >> buf[5];
            library[i]->str = (strcmp(buf[5], "-")) ? (int)atol(buf[5]) : library[i]->str;

            std::cout << "������� ����� - ";
            std::cin >> buf[6];
            library[i]->tir = (strcmp(buf[6], "-")) ? (int)atol(buf[6]) : library[i]->tir;

            std::cin.getline(buf[7], 50);

            Output(library,size);
            return;
        }
    }
}
