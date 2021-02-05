#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 10

typedef struct _time
{
    int days;
    int months;
    int years;
} time;

typedef struct _record
{
    time ts;
    char *name;
} record;

void _date_init(time *source)
{
    source->days = 1;
    source->months = 1;
    source->years = 1970;
}

int _compare(const void *a, const void *b);

int main(int argc, char const *argv[])
{
    if (argc != N + 1)
    {
        printf("wrong argument count");
        return 1;
    }

    record *array = (record *)calloc(N, sizeof(record));
    if (array == NULL)
    {
        return -1;
    }

    for (size_t i = 0; i < N; ++i)
    {
        time date;
        _date_init(&date);

        date.days += i;
        date.months += i;
        date.years += i;

        char *name = (char *)malloc(strlen(argv[i + 1]) + 1);
        strcpy(name, argv[i + 1]);

        record rec = {date, name};

        array[i] = rec;
    }

    qsort(array, N, sizeof(*array), _compare);

    for (size_t i = 0; i < N; ++i)
    {
        printf(
            "%d-%d-%d %s ",
            array[i].ts.years,
            array[i].ts.months,
            array[i].ts.days,
            array[i].name);
    }

    for (size_t i = 0; i < N; ++i)
    {
        free(array[i].name);
    }
    free(array);

    return 0;
}

int _compare(const void *a, const void *b)
{
    return strcmp(((record *)a)->name, ((record *)b)->name);
}
