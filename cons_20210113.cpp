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

int main(int argc, char const *argv[])
{
    return 0;
}
