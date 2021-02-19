#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "functions.h"

char buf[30];

void menu()
{
    printf("Выберете один из пунктов меню\n");
    printf("1.Динамическое выделение памяти для массива структур.\n");
    printf("2.Ввод элементов массива с клавиатуры.\n");
    printf("3.Поиск элемента массива.\n");
    printf("4.Сортировка массива.\n");
    printf("5.Редактирование элемента массива.\n");
    printf("6.Добавление нового элемента в конец.\n");
    printf("7.Удаление указанного элемента из массива.\n");
    printf("8.Вставка нового элемента.\n");
    printf("9.Запись элементов массива в файл.\n");
    printf("10.Считывание элементов массива из файла.\n");
    printf("11.Вывод элементов массива на экран.\n");
    printf("12.Освобождение памяти, выделенной для массива.\n");
    printf("13.Окончание работы программы.\n");
}

void strucalloc(FILM **&STRPOINT, const int SIZE_MS)
{
    printf("выбрано выделение памяти\n");
    STRPOINT = (FILM **)malloc(SIZE_MS * sizeof(struct FILM *));
    for (size_t i = 0; i < SIZE_MS; i++)
        STRPOINT[i] = (FILM *)malloc(sizeof(struct FILM));
}

void strucfree(FILM **&STRPOINT, const int SIZE_MS)
{
    if (STRPOINT[0]->nam == NULL)
    {
        printf("память уже очищена\n");
        return;
    }

    for (int i = 0; i < SIZE_MS; i++)
    {
        free(STRPOINT[i]->nam);
        STRPOINT[i]->nam = NULL;
        free(STRPOINT[i]->country);
        STRPOINT[i]->country = NULL;
        free(STRPOINT[i]->janr);
        STRPOINT[i]->janr = NULL;
        free(STRPOINT[i]->reg);
        STRPOINT[i]->reg = NULL;
        free(STRPOINT[i]);
        STRPOINT[i] = NULL;
    }
    free(STRPOINT);
    STRPOINT = NULL;
}

void strucinp(FILM **&STRPOINT, int i)
{
    printf("введите название страны в которой был снят фильм\n");
    char bufer[100];
    gets(bufer);
    int b = strlen(bufer);
    //FIXME: b + 1
    STRPOINT[i]->country = (char *)malloc(b);
    strncpy(STRPOINT[i]->country, bufer, b);
    memset(bufer, '\000', 100);

    printf("введите название фильма\n");
    gets(bufer);
    b = strlen(bufer);
    STRPOINT[i]->nam = (char *)malloc(b);
    strncpy(STRPOINT[i]->nam, bufer, b);
    memset(bufer, '\000', 100);

    printf("введите жанр фильма\n");
    gets(bufer);
    b = strlen(bufer);
    STRPOINT[i]->janr = (char *)malloc(b);
    strncpy(STRPOINT[i]->janr, bufer, b);
    memset(bufer, '\000', 100);

    printf("введите имя режиссёра фильма\n");
    gets(bufer);
    b = strlen(bufer);
    STRPOINT[i]->reg = (char *)malloc(b);
    strncpy(STRPOINT[i]->reg, bufer, b);
    memset(bufer, '\000', 100);

    printf("введите год выпуска фильма в прокат\n");
    myscan(&STRPOINT[i]->year);
}

void strucoutp(FILM **STRPOINT, int i)
{
    if (STRPOINT[i]->nam != NULL)
    {
        printf(" название фильма:%s\n", STRPOINT[i]->nam);
        printf(" название страны ,в которой был снят фильм:%s\n", STRPOINT[i]->country);
        printf(" название жанра фильма:%s\n", STRPOINT[i]->janr);
        printf(" имя режиссёра фильма:%s\n", STRPOINT[i]->reg);
        printf(" год выпуска фильма в прокат:%d\n", STRPOINT[i]->year);
        printf("-----------------------------------------------------\n");
    }
}

void search(FILM **STRPOINT, const int SIZE_MS)
{
    const char *cancel = {"cancel"}; // ???
    while (strcmp(buf, cancel) != 0)
    {
        memset(buf, '\000', 30);
        printf("поиск:");
        gets(buf); // FIXME: Windows only
        int BUF_SIZE = 0;
        int bil = 0;
        BUF_SIZE = strlen(buf);
        for (int i = 0; i < SIZE_MS; i++)
        {
            if (strncmp(STRPOINT[i]->nam, buf, BUF_SIZE) == 0 || strncmp(STRPOINT[i]->country, buf, BUF_SIZE) == 0 || strncmp(STRPOINT[i]->janr, buf, BUF_SIZE) == 0 || strncmp(STRPOINT[i]->reg, buf, BUF_SIZE) == 0 || atoi(buf) == STRPOINT[i]->year)
            {
                printf("Фильм и данные о нём найдены:\n");
                strucoutp(STRPOINT, i);
                bil = 1;
            }
        }
        if (bil == 0 && strcmp(buf, cancel) != 0)
            printf("Фильм ,который соотвествует запросу не найден.\n");
        if (strcmp(buf, cancel) != 0)
            printf("для завершения поиска введите ''cancel''\n");
        else if (strcmp(buf, cancel) == 0)
            printf("поиск завершен.");
    }
}

void strucsort(struct FILM **&STRPOINT, const int SIZE_MS)
{
    int sort_end = 1; // ???
    struct FILM *tmp;
    printf("выбрана сортировка массива структур\nсортировка осуществляется по возрастанию года выпуска фильма в прокат\n");
    for (int j = 0; j < SIZE_MS - 1; j++)
        for (int i = 0; i < SIZE_MS - 1; i++)
        {
            if ((STRPOINT[i]->year) > (STRPOINT[i + 1]->year))
            {
                tmp = STRPOINT[i];
                STRPOINT[i] = STRPOINT[i + 1];
                STRPOINT[i + 1] = tmp;
                sort_end = 1;
            }
        }
}

void strucread_f(struct FILM **&STRPOINT, const char *file_name, const int SIZE_MS)
{
    FILE *inf;
    inf = fopen(file_name, "r");
    if (inf == NULL)
    {
        printf("ошибка открытия файла!");
    }
    else
    {
        int i = 0;
        for (int i = 0; i < SIZE_MS; i++)
        {
            char bufer[100];
            memset(bufer, '\000', 100);
            fgets(bufer, 100, inf);
            if (bufer[0] == '\000')
                break;
            int b = strlen(bufer);
            STRPOINT[i]->nam = (char *)malloc(b - 1); // ???
            strncpy(STRPOINT[i]->nam, bufer, b - 1);
            memset(bufer, '\000', 100);

            fgets(bufer, 100, inf);
            b = strlen(bufer);
            STRPOINT[i]->country = (char *)malloc(b - 1);
            strncpy(STRPOINT[i]->country, bufer, b - 1);
            memset(bufer, '\000', 100);

            fgets(bufer, 100, inf);
            b = strlen(bufer);
            STRPOINT[i]->reg = (char *)malloc(b - 1);
            strncpy(STRPOINT[i]->reg, bufer, b - 1);
            memset(bufer, '\000', 100);

            fgets(bufer, 100, inf);
            b = strlen(bufer);
            STRPOINT[i]->janr = (char *)malloc(b - 1);
            strncpy(STRPOINT[i]->janr, bufer, b - 1);
            memset(bufer, '\000', 100);

            fgets(bufer, 100, inf);
            STRPOINT[i]->year = atoi(bufer);
            memset(bufer, '\000', 100);
        }
    }
    fclose(inf);
}

void strured(struct FILM **&STRPOINT, const int numred)
{
    if (STRPOINT[numred]->nam != NULL)
    {
        free(STRPOINT[numred]->nam);
        free(STRPOINT[numred]->country);
        free(STRPOINT[numred]->janr);
        free(STRPOINT[numred]->reg);
    }
    strucinp(STRPOINT, numred);
}

void myscan(int *number)
{
    memset(buf, '\000', 30);
    gets(buf);
    (*number) = atoi(buf);
}

void add_element(struct FILM **&STRPOINT, int *SIZE_MS)
{
    struct FILM **TEMP;
    (*SIZE_MS)++;
    TEMP = (FILM **)malloc((*SIZE_MS) * sizeof(struct FILM *));
    TEMP[(*SIZE_MS) - 1] = (FILM *)malloc(sizeof(struct FILM));
    for (int i = 0; i < (*SIZE_MS) - 1; i++)
    {
        TEMP[i] = STRPOINT[i];
    }
    free(STRPOINT);
    strucinp(TEMP, (*SIZE_MS) - 1);
    STRPOINT = TEMP;
}

void del_element(struct FILM **&STRPOINT, const int delnum, int *SIZE_MS)
{
    free(STRPOINT[delnum]);
    for (int i = delnum; i < (*SIZE_MS) - 1; i++)
        STRPOINT[i] = STRPOINT[i + 1];
    STRPOINT[(*SIZE_MS) - 1] = NULL;
    (*SIZE_MS)--;
}

void _del_element(struct FILM **&STRPOINT, const int numofdel, const int firstdel, int *SIZE_MS)
{
    for (int i = firstdel; i < numofdel; i++)
    {
        free(STRPOINT[i]);
    }
    for (int i = firstdel; i + numofdel < *SIZE_MS; i++)
    {
        (STRPOINT[i]) = (STRPOINT[i + numofdel]);
    }
    for (int i = *SIZE_MS - numofdel; i < *SIZE_MS; i++)
    {
        STRPOINT[i] = NULL;
    }
    (*SIZE_MS) -= numofdel;
}

void paste_element(struct FILM **&STRPOINT, const int pastenum, int *SIZE_MS)
{
    int j = 0;
    (*SIZE_MS)++;
    struct FILM **TEMP = (FILM **)malloc((*SIZE_MS) * sizeof(struct FILM *));
    TEMP[pastenum] = (FILM *)malloc(sizeof(struct FILM));
    for (int i = 0; i < (*SIZE_MS); i++)
    {
        if (i != pastenum)
        {
            TEMP[i] = STRPOINT[j];
            j++;
        }
    }
    free(STRPOINT);
    strucinp(TEMP, pastenum);
    STRPOINT = TEMP;
}

void strucfprintf(struct FILM **STRPOINT, const char *file_name, const int SIZE_MS)
{
    FILE *structinf;
    structinf = fopen(file_name, "w");
    if (structinf == NULL)
        printf("ошибка открытия файла\n");
    else
    {
        for (int i = 0; i < SIZE_MS; i++)
        {
            fprintf(structinf, "%s\n", STRPOINT[i]->country);
            fprintf(structinf, "%s\n", STRPOINT[i]->nam);
            fprintf(structinf, "%s\n", STRPOINT[i]->reg);
            fprintf(structinf, "%s\n", STRPOINT[i]->janr);
            fprintf(structinf, "%d\n", STRPOINT[i]->year);
        }
        fclose(structinf);
    }
}
