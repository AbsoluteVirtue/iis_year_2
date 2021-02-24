#ifndef Delim_
#define Delim_

// не нужно включать заголовочные файлы, которые не имеют отношения к коду
#include <bits/stdc++.h>

struct tovar
{
    std::string nazvanie{};
    std::string country{};
    std::string proizvoditel{};
    std::string rod_izdelia_tovara{};
    int price = 0;
};

void dinamiceskoe_videlenie_pamiati(tovar *&novii_massif, int &a);
void vvod_massiva_s_klav_(tovar *&novii_massiv, const int &a);
void poisk_elementa_massiva(tovar *&novii_massiv, const int &a);
void sortirovka(tovar *&novii_massiv, const int &a);
void redaktirovanie_elementov(tovar *&novii_massiv, const int &a);
void push_back(tovar *&novii_massiv, int &a);
void delete_element(tovar *&novii_massiv, int &a);
void vstavka_novogo_elementa(tovar *&novii_massiv, int &a);
void zapiss_elementov_v_fail(tovar *&novii_massiv, int &a, const char *nazvanie_faila);
void scitivanie_elementov_iz_faila(tovar *&novii_massif, const char *name_of_file, const int &a);
void vivod_massiva_na_ekran(tovar *&novii_massiv, int &a);
void osvobojdenie_pamiati(tovar *&novii_massiv, int &a);

#endif
