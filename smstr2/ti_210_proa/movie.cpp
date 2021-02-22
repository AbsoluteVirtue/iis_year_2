#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "movie.h"

void movie::print()
{
    std::cout << "Название:" << this->name << "\n";
    std::cout << "Страна:" << this->country << "\n";
    std::cout << "Режиссёр:" << this->producer << "\n";
    std::cout << "Жанр:" << this->genre << "\n";
    std::cout << "Год:" << this->year << "\n";
}

void memoAlloc(movie **&mov, const int amountOfMovies)
{
    mov = new movie *[amountOfMovies];
    for (int i = 0; i < amountOfMovies; ++i)
    {
        mov[i] = new movie;
    }
}

void addEl(movie **&mov, const int amountOfMovies)
{
    movie **newMov = nullptr;
    movie *mass = nullptr;
    bool full = true;
    std::cout << "Введите данные нового фильма:\n\n";
    std::cout << "Название: ";
    std::string search;
    std::cin >> search;
    int i = 0;
    while (1)
    {
        if ((*mov[i]).name == search)
        {
            std::cout << "Такой фильм уже есть\n";
            return;
        }

        if (i >= amountOfMovies - 1 || (*mov[i]).name == "")
            break;

        ++i;
    }

    while (1)
    {
        if ((*mov[i]).name == "") // ???
        {
            mass = mov[i];
            full = false;
            break;
        }

        if (i >= amountOfMovies - 1)
            break;

        ++i;
    }

    if (full)
    {
        newMov = new movie *[amountOfMovies + 1];
        i = 0;
        while (1)
        {
            newMov[i] = new movie; // ???
            if (i >= amountOfMovies)
                break;

            *newMov[i] = *mov[i]; // ???
            delete mov[i];
            ++i;
        }

        delete[] mov;
        mass = newMov[amountOfMovies];
        mov = newMov;
    }

    (*mass).name = search;
    std::cout << "Страна: ";
    std::cin >> (*mass).country;
    std::cout << "Режиссёр: ";
    std::cin >> (*mass).producer;
    std::cout << "Жанр: ";
    std::cin >> (*mass).genre;
    std::cout << "Год: ";
    std::cin >> (*mass).year;
}

void massSearch(movie **&mov, const int amountOfMovies)
{
    std::cout << "Введите название фильма, который хотите найти: ";
    std::string search;
    std::cin >> search;
    std::cout << "\n";

    int i = 0;
    while (1)
    {
        if ((*mov[i]).name == search)
        {
            (*mov[i]).print();
            break;
        }

        if ((*mov[i]).name == "" || i >= amountOfMovies - 1)
        {
            std::cout << "Не найден фильм с таким названием";
            return;
        }

        ++i;
    }
}

void massSort(movie **&mov, const int amountOfMovies)
{
    movie *intermideateRec;
    int i = 0;
    while ((*mov[i]).name != "")
    {
        int j = 0;
        while ((*mov[i]).name != "")
        {
            if ((*mov[i]).name < (*mov[j]).name)
            {
                intermideateRec = mov[i];
                mov[i] = mov[j];
                mov[j] = intermideateRec;
            }
            if (j >= amountOfMovies - 1)
                break;

            ++j;
        }

        if (i >= amountOfMovies - 1)
            break;

        ++i;
    }
}

void massElEdit(movie **&mov, const int amountOfMovies)
{
    std::cout << "Введите название фильма,данные которого хотите изменить: ";
    std::string search;
    std::cin >> search;
    std::cout << "\n";

    int i = 0;
    while (1)
    {
        if (search == (*mov[i]).name)
        {
            std::cout << "Название: ";
            std::cin >> (*mov[i]).name;
            std::cout << "Страна: ";
            std::cin >> (*mov[i]).country;
            std::cout << "Режиссёр: ";
            std::cin >> (*mov[i]).producer;
            std::cout << "Жанр: ";
            std::cin >> (*mov[i]).genre;
            std::cout << "Год: ";
            std::cin >> (*mov[i]).year;
            break;
        }

        if ((*mov[i]).name == "" || i >= amountOfMovies - 1)
        {
            std::cout << "Такого фильма нет\n";
            break;
        }
        ++i;
    }
}

void massElDelete(movie **&mov, const int amountOfMovies)
{
    std::cout << "Введите название фильма,данные которого хотите удалить: ";
    std::string search;
    std::cin >> search;
    std::cout << "\n";
    int i = 0, found = 0;
    while (1)
    {
        if ((*mov[i]).name == search)
        {
            break;
        }

        if ((*mov[i]).name == "" || i >= amountOfMovies - 1)
        {
            std::cout << "Не найден фильм с таким названием";
            return;
        }
        ++i;
    }

    while (1)
    {
        if (i >= amountOfMovies - 1 || (*mov[i + 1]).name == "")
        {
            found = i;
            break;
        }
        *mov[i] = *mov[i + 1];
        ++i;
    }
    //FIXME: delete mov[found]
    (*mov[found]).name = "";
    (*mov[found]).country = "";
    (*mov[found]).producer = "";
    (*mov[found]).genre = "";
    (*mov[found]).year = 0;
}

void insertEl(movie **&mov, const int amountOfMovies)
{
    movie **newMov = nullptr;
    movie notReal;
    bool full = true;
    std::cout << "Введите данные нового фильма:\n\n";
    std::cout << "Название: ";
    std::cin >> notReal.name;
    std::cout << "Страна: ";
    std::cin >> notReal.country;
    std::cout << "Режиссёр: ";
    std::cin >> notReal.producer;
    std::cout << "Жанр: ";
    std::cin >> notReal.genre;
    std::cout << "Год: ";
    std::cin >> notReal.year;
    int i = 0;
    while (1)
    {
        if ((*mov[i]).name == notReal.name)
        {
            std::cout << "Такой фильм уже есть\n";
            return;
        }

        if (i >= amountOfMovies - 1 || (*mov[i]).name == "")
            break;

        ++i;
    }

    std::cout << "Введите название фильма,после которого хотите вставить новый фильм: ";
    std::string search;
    std::cin >> search;
    std::cout << "\n";
    i = 0;
    int found = 0;
    while (1)
    {
        if (search == (*mov[i]).name)
        {
            found = i;
            break;
        }

        if (i >= amountOfMovies - 1 || (*mov[i]).name == "")
        {
            std::cout << "Такого фильма нет.\n";
            return;
        }
        ++i;
    }

    while (1)
    {
        if ((*mov[i]).name == "")
        {
            full = false;
            break;
        }
        if (i >= amountOfMovies - 1)
            break;

        ++i;
    }

    if (full)
    {
        newMov = new movie *[amountOfMovies + 1];
        i = 0;
        while (1)
        {
            newMov[i] = new movie;
            if (i >= amountOfMovies)
                break;

            *newMov[i] = *mov[i];
            delete mov[i];
            ++i;
        }

        delete[] mov;
        mov = newMov;
        i = amountOfMovies;
    }

    if (i != amountOfMovies)
    {
        while (1)
        {
            if ((*mov[i]).name != "")
                break;

            --i;
        }
    }

    while (1)
    {
        *mov[i] = *(mov[i - 1]);
        if (i <= found + 1 || i <= 0)
        {
            *mov[i] = notReal;
            break;
        }
        --i;
    }
}

void recMassInFile(movie **&mov, const int amountOfMovies, std::string *filePath)
{
    if ((*mov[0]).name == "")
    {
        std::cout << "В библиотеке нет ни одного фильма\n";
        return;
    }

    std::ofstream rez;
    rez.open(*filePath);
    int i = 0;
    while (rez.is_open())
    {
        if (i >= amountOfMovies - 1)
            break;

        rez << (*mov[i]).name << "\t";
        rez << (*mov[i]).country << "\t";
        rez << (*mov[i]).producer << "\t";
        rez << (*mov[i]).genre << "\t";
        rez << (*mov[i]).year << "\n";

        ++i;
    }
}

int readMassEl(movie **&mov, const int amountOfSymbols, int amountOfFilms, FILE **in)
{
    if (*in == NULL)
    {
        std::cout << "Файл пустой\n";
        return 1;
    }

    char *buf = new char[amountOfSymbols];
    const char *delim = ",\"; \'";
    int i = 0, j = 0, sizeOfMass = 0;
    while (fgets(buf, amountOfSymbols, *in) && j < amountOfFilms)
    {
        char *token = strtok(buf, delim);
        int fullCount = 0;
        while (fullCount < 5)
        {
            int full = 1;
            while (full)
            {
                token = strtok(token, delim);
                if ((*mov[j]).name == "")
                {
                    (*mov[j]).name = token;
                    int count = strlen(token);
                    // ???
                    for (int z = 0; z <= count; ++z)
                    {
                        if ((*mov[j]).name[z] == *token)
                        {
                            *token = '\0';
                            ++token;
                        }
                    }

                    ++token;
                    full = 0;
                    fullCount++;
                }
                else if ((*mov[j]).country == "")
                {
                    (*mov[j]).country = token;
                    int count = strlen(token);
                    for (int z = 0; z <= count; ++z)
                    {
                        if ((*mov[j]).country[z] == *token)
                        {
                            *token = '\0';
                            ++token;
                        }
                    }
                    ++token;
                    full = 0;
                    fullCount++;
                }
                else if ((*mov[j]).producer == "")
                {
                    (*mov[j]).producer = token;
                    int count = strlen(token);
                    for (int z = 0; z <= count; ++z)
                    {
                        if ((*mov[j]).producer[z] == *token)
                        {
                            *token = '\0';
                            ++token;
                        }
                    }
                    ++token;
                    full = 0;
                    fullCount++;
                }
                else if ((*mov[j]).genre == "")
                {
                    (*mov[j]).genre = token;
                    int count = strlen(token);
                    for (int z = 0; z <= count; ++z)
                    {
                        if ((*mov[j]).genre[z] == *token)
                        {
                            *token = '\0';
                            ++token;
                        }
                    }
                    ++token;
                    full = 0;
                    fullCount++;
                }
                else if ((*mov[j]).year == 0)
                {
                    (*mov[j]).year = (int)atol(token);
                    full = 0;
                    fullCount++;
                }
            }
        }
        ++j;
    }
    delete[] buf;
    return 0;
}

void freeMemo(movie **&mov, const int amountOfMovies)
{
    int i = 0;
    while (1)
    {
        delete mov[i];
        if (i >= amountOfMovies - 1)
            break;

        ++i;
    }
    delete[] mov;
    mov = nullptr;
}
