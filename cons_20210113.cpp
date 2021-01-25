#include <cstring>
#include <ciso646>
#include <cstdio>
#include <cmath>

void ten()
{
    const char *delim = " ,./\n\t!@#$%^&*()_-+=";
    char str[] = "vu, truye, asfa, aa, asdadaf. asfaa, oo, as, aa";
    char *token = strtok(str, delim);
    size_t counter = 0;
    while (token)
    {
        if (!strcmp(token, "vu") or !strcmp(token, "aa"))
        {
            counter++;
        }
        token = strtok(NULL, delim);
    }
    printf("%d", counter);
}

char *_strcat(char *dest, const char *src, size_t n)
{
    size_t i, j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != n; j++)
    {
        if (src[j] == '\0')
            break;
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';
    return dest;
}

double binary()
{
    const char *bin = "1010";
    double res = 0;
    for (int i = 0, j = strlen(bin) - 1; j >= 0; ++i, --j)
    {
        if (bin[j] == '1')
            res += pow(2, i);
    }
    return res;
}

int main()
{

    int a[100], n, i, n1, n2; //a[n1]<=a[n2]

    // ВВОД ДАННЫХ

    n1 = 0;
    n2 = 1;

    if (a[n1] > a[n2])

        n1 = 1, n2 = 0;

    for (i = 2; i < n; i++)

        if (a[i] < a[n1])
        {

            n2 = n1;

            n1 = i;
        }
        else if (a[i] < a[n2])

            n2 = i;

    printf("%d  %d", n1, n2);
}
