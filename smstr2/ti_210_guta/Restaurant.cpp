#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <string.h>

#include "Restaurant.h"

void dyn_mem(int *object_size, pRestaurant *&_P_OBJECT) {
    _P_OBJECT= new pRestaurant[*object_size];

    for(int i = 0; i < *object_size; i++) {
        _P_OBJECT[i] = new Restaurant;
    }
}

void file_read(pRestaurant *_P_OBJECT, FILE *file_name) {
    char buf[66];
    char *token;
    const char *delim = "\";\n";
    int i, j = 0;

    while(fgets(buf, 66, file_name) != NULL)
    {
        token = strtok(buf, delim);
        i = 0;
        while(token) 
        {
            switch (i)
            {
                case 0 :
                    _P_OBJECT[j]->NAME = token;
                    break;
                case 1 : 
                    _P_OBJECT[j]->ADRESS = token;
                    break;
                case 2 : 
                    _P_OBJECT[j]->phone = token;
                    break;
                case 3 : 
                    _P_OBJECT[j]->category = token;
                    break;
                case 4 : 
                    _P_OBJECT[j]->places = token;
                    break;
                case 5 : 
                    _P_OBJECT[j]->spec = token;
                    break;
            }
            token = strtok(NULL, delim);
            i++;
        }
        j++;
    }
}


void _search(int *object_size, pRestaurant *_P_OBJECT) {
    // воод данных надо отделять от работы функции
    cout << "Введите название ресторана, информацию о котором хотите увидеть ";
    char tmp_NAME[100];
    cin >> tmp_NAME;
    int num, i;
    bool is = false;

    for(i = 0; i < *object_size; i++)
    {
        if(_P_OBJECT[i]->NAME == tmp_NAME)
        {
            single_out(i, _P_OBJECT);
            is = true;
            break;
        }
    }
    if(is == false)
    {
        cout << "Было введено несуществующее название";
    }
    cout << "\n\n";
}


void _sort(int *object_size, pRestaurant *_P_OBJECT) {
    cout << "По какому элементу хотите отсортировать массив: \n Имя - 0\n Адрес - 1\n Телефон - 2\n Категория - 3\n Кол-во мест - 4\n Специализация - 5\n";
    int spec, i;
    pRestaurant _P_OBJECT_CPY;

    cin >> spec;

    switch (spec)
    {
    case 1:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->ADRESS < _P_OBJECT[j+1]->ADRESS) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;
    
    case 2:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->phone < _P_OBJECT[j+1]->phone) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;

    case 3:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->category < _P_OBJECT[j+1]->category) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;

    case 4:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->places < _P_OBJECT[j+1]->places) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;

    case 5:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->spec < _P_OBJECT[j+1]->spec) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;

    case 0:
        for(i = 0; i < *object_size; i++) {
            for(int j = 0; j < (*object_size - i - 1); j++) {
                if(_P_OBJECT[j]->NAME < _P_OBJECT[j+1]->NAME) {
                    _P_OBJECT_CPY = _P_OBJECT[j];
                    _P_OBJECT[j] = _P_OBJECT[j+1];
                    _P_OBJECT[j+1] = _P_OBJECT_CPY;
                }
            }
        }
        break;
    
    default:
        cout << "Было введено неверное значение\n";
        break;
    }
    delete[] _P_OBJECT_CPY;
}


void option_change(int *object_size, pRestaurant *_P_OBJECT) {
    cout << "Введите название ресторана, данные которого хотите изменить ";
    char tmp_NAME[100];
    cin >> tmp_NAME;
    int num, i;
    bool is = false;

    for(i = 0; i < *object_size; i++)
    {
        if(_P_OBJECT[i]->NAME == tmp_NAME)
        {
            num = i;
            is = true;
            break;
        }
    }
    if(is == false)
    {
        cout << "Было введено несуществующее название";
        return;
    }

    cout << "Введите параметр, который хотите изменить :\n Имя - 0\n Адрес - 1\n Телефон - 2\n Категория - 3\n Кол-во мест - 4\n Специализация - 5\n";
    cin >> i;
        cout << "Введите ";
        char tmp_opt[100];

        switch (i)
        {
            case 0 :
                cin >> tmp_opt; 
                _P_OBJECT[num]->NAME = tmp_opt;
                break;
            case 1 : 
                cin >> tmp_opt; 
                _P_OBJECT[num]->ADRESS = tmp_opt;
                break;
            case 2 :    
                cin >> tmp_opt; 
                _P_OBJECT[num]->phone = tmp_opt;
                break;
            case 3 : 
                cin >> tmp_opt; 
                _P_OBJECT[num]->category = tmp_opt;
                break;
            case 4 : 
                cin >> tmp_opt; 
                _P_OBJECT[num]->places = tmp_opt;
                break;
            case 5 : 
                cin >> tmp_opt; 
                _P_OBJECT[num]->spec = tmp_opt;
                break;
            default : 
                cout << "Было введено несуществующее значение";
                break;
        }

    cout << "\n\n";
}


void _push_back(int *object_size, pRestaurant *&_P_OBJECT) {
    cout << "Добавление нового элемента\n";
    *object_size += 1;

    pRestaurant *_P_OBJECT_CPY;
    dyn_mem(object_size, _P_OBJECT_CPY);

    for(int i = 0; i < *object_size - 1; i++)
    {
        _P_OBJECT_CPY[i] = _P_OBJECT[i];
    }

    delete []_P_OBJECT;

    struct_inputn(*object_size - 1, _P_OBJECT_CPY);

    dyn_mem(object_size, _P_OBJECT); // второе выделение памяти не нужно

    for(int i = 0; i < *object_size; i++)
    {
        _P_OBJECT[i] = _P_OBJECT_CPY[i];
    }
    
    delete []_P_OBJECT_CPY;
    
    cout << "\n\n";
}


void _erase(int *object_size, pRestaurant *&_P_OBJECT) {
    cout << "Введите название элемента, который хотите удалить ";
    char tmp_NAME[100];
    cin >> tmp_NAME;
    int num, i;
    bool is = false;

    for(i = 0; i < *object_size; i++)
    {
        if(_P_OBJECT[i]->NAME == tmp_NAME)
        {
            num = i;
            is = true;
            break;
        }
    }
    if(is == false)
    {
        cout << "Было введено несуществующее название";
        return;
    }

    *object_size -= 1;

    pRestaurant *_P_OBJECT_CPY;
    dyn_mem(object_size, _P_OBJECT_CPY);

    if(num == *object_size)
    {
        for(i = 0; i < *object_size; i++)
        {
            _P_OBJECT_CPY[i] = _P_OBJECT[i];
        }
    } else
        {
            for(i = 0; i < num; i++) 
            {
                _P_OBJECT_CPY[i] = _P_OBJECT[i];
            }

            int j = num;
            for(i = num + 1; i < *object_size + 1; i++) 
            {
                _P_OBJECT_CPY[j] = _P_OBJECT[i];
                j++;
            }
        }

    delete []_P_OBJECT;
        
    dyn_mem(object_size, _P_OBJECT);

    for(int i = 0; i < *object_size; i++)
    {
        _P_OBJECT[i] = _P_OBJECT_CPY[i];
    }
    
    delete []_P_OBJECT_CPY;
}


void _push(int *object_size, pRestaurant *&_P_OBJECT) {
    cout << "Введите по какому номеру необходимо вставить элемент ";
    int num, i;
    cin >> num;
    if(num > *object_size | num < 0)
    {
        cout << "Было введено несуществующее значение";
        return;
    }

    *object_size += 1;

    pRestaurant *_P_OBJECT_CPY;
    dyn_mem(object_size, _P_OBJECT_CPY);

    if(num == *object_size)
    {
        for(i = 0; i < *object_size; i++)
        {
            _P_OBJECT_CPY[i] = _P_OBJECT[i];
        }
    } else
    {
        for(i = 0; i < num; i++) 
        {
            _P_OBJECT_CPY[i] = _P_OBJECT[i];
        }

        int j = num;
        for(i = num + 1; i < *object_size + 1; i++) 
        {
            _P_OBJECT_CPY[i] = _P_OBJECT[j];
            j++;
        }
    }

    struct_inputn(num, _P_OBJECT_CPY);

    delete []_P_OBJECT;
        
    dyn_mem(object_size, _P_OBJECT);

    for(int i = 0; i < *object_size; i++)
    {
        _P_OBJECT[i] = _P_OBJECT_CPY[i];
    }
    
    delete []_P_OBJECT_CPY;
}


void file_out(int *object_size, pRestaurant *_P_OBJECT, FILE *file_out) {
    for(int i = 0; i < *object_size; i++) 
    {
        fprintf(file_out, "%s;", _P_OBJECT[i]->NAME);
        fprintf(file_out, "%s;", _P_OBJECT[i]->ADRESS);
        fprintf(file_out, "%s;", _P_OBJECT[i]->phone);
        fprintf(file_out, "%s;", _P_OBJECT[i]->category);
        fprintf(file_out, "%s;", _P_OBJECT[i]->places);
        fprintf(file_out, "%s\n", _P_OBJECT[i]->spec);
    }
}


void struct_inputn(int object_number, pRestaurant *&_P_OBJECT) {
    char *tmp;
    std::cin.ignore(32767, '\n');
    cout << "\nВведите название "; getline(cin, _P_OBJECT[object_number]->NAME); 
    cout << "Введите адрес "; getline(cin, _P_OBJECT[object_number]->ADRESS); 
    cout << "Введите телефон "; getline(cin, _P_OBJECT[object_number]->phone); 
    cout << "Введите категорию "; getline(cin, _P_OBJECT[object_number]->category); 
    cout << "Введите количество мест "; getline(cin, _P_OBJECT[object_number]->places); 
    cout << "Введите специализацию "; getline(cin, _P_OBJECT[object_number]->spec);

}


void single_out(int object_number, pRestaurant *_P_OBJECT) {
    cout << "\nназвание " << _P_OBJECT[object_number]->NAME << "\nадрес " << _P_OBJECT[object_number]->ADRESS << "\nтелефон " << _P_OBJECT[object_number]->phone << "\nкатегория " << _P_OBJECT[object_number]->category << "\nколичество мест " << _P_OBJECT[object_number]->places << "\nспециализация " << _P_OBJECT[object_number]->spec;
}


void all_out(int *object_size, pRestaurant *_P_OBJECT) {
    int j;

    for(j = 0; j < *object_size; j++) 
    {
        cout << "\nназвание " << _P_OBJECT[j]->NAME << "\nадрес " << _P_OBJECT[j]->ADRESS << "\nтелефон " << _P_OBJECT[j]->phone << "\nкатегория " << _P_OBJECT[j]->category << "\nколичество мест " << _P_OBJECT[j]->places << "\nспециализация " << _P_OBJECT[j]->spec << "\n";
    }
}
