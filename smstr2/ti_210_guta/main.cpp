#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <string.h>
#include "Restaurant.h"
#include "Restaurant.cpp" // надо было компилировать файл

main() {
    setlocale(LC_ALL, "Rus");
    setlocale(0, "");
    FILE *fin = fopen("\\base.csv", "r");

    if (fin == NULL)
    {
        printf("Нет входного файла с данными");
        return 1;
    }

    FILE *fout = fopen("\\output.csv", "w");

    if (fout == NULL)
    {
        printf("Нет файла вывода");
        return 1;
    }
    
    int *prow_amt, row_amt = 4;
    prow_amt = &row_amt;
    pRestaurant *pRest = NULL;

    cout << "\tМЕНЮ ОПЕРАЦИЙ\n" << endl;
    cout << "1. Динамическое выделение памяти для массива структур.\n2. Считывание элементов массива из файла.\n3. Поиск элемента массива.\n4. Сортировка массива.\n5. Редактирование элемента массива.\n6. Добавление нового элемента в конец.\n7. Удаление указанного элемента из массива.\n8. Вставка нового элемента.\n9. Запись элементов массива в файл. \n10. Вывод элементов массива на экран.\n11. Освобождение памяти, выделенной для массива.\n12. Окончание работы программы.\n\n" << endl;

    int opt;
    bool read = false, deleted = false, is_out = false;
    
    while(1)
    {
        cout << "Опция "; cin >> opt; cout << endl;

        if(opt == 12) break;

        if(opt > 12 | opt < 1) {
            cout << "Было введено неверное значение\n"; 
            continue;
        }
        if(pRest == NULL & opt != 1) {
            cout << "Память для массива не выделена, для работы с массивом необходимо её выделить\n";
            continue;
        } else if(read == false & (opt != 1 & opt != 2)) {
            cout << "Массив пуст\n";
            continue;
        } else if(deleted == true & opt != 1) {
            cout << "Массив был удалён\n";
            continue;
        } else if(is_out == true & opt == 9) {
            cout << "Вывод структуры в файл уже был произведён\n";
            continue;
        }

        switch (opt)
        {
            case 1:{
                dyn_mem(prow_amt, pRest);
                deleted = false;
                break;
                }

            case 2: 
                file_read(pRest, fin);
                read = true;
                break;

            case 3:
                _search(prow_amt, pRest);
                break;

            case 4:
                _sort(prow_amt, pRest);
                break;

            case 5:
                option_change(prow_amt, pRest);
                break;
            
            case 6:
                _push_back(prow_amt, pRest);
                break;
            
            case 7:
                _erase(prow_amt, pRest);
                break;

            case 8:
                _push(prow_amt, pRest);
                break;
            
            case 9:
                file_out(prow_amt, pRest, fout);
                is_out = true;
                break;

            case 10:
                all_out(prow_amt, pRest);
                break;

            case 11:
                delete []pRest;
                deleted = true;
                break;

            default:
                cout << "Было введено неверное значение\n";
                break;
        }
    }


    fclose(fin);
    fclose(fout);
}