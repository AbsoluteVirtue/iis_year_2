#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ERROR 100000.

int scan_1()
{
    char line[256];
    int i;
    if (fgets(line, sizeof(line), stdin))
    {
        int res = sscanf(line, "%d", &i);
        if (1 != res)
        {
            printf("error!");
            return 0;
        }
        return res;
    }
    return -1;
}

void print(const char *str)
{
    for (int idx = 0; str[idx]; idx += 1)
    {
        printf("%c", str[idx]);
    }
}

float function_set(float x, float a, float b, float c, int debug)
{
    float result = 0.0;
    if ((x + a) < 0.0 && c == 0.0)
    {
        result = (1.0 / (a * x)) - b;
    }
    else if ((x + a) > 0.0 && c != 0.0)
    {
        if (!sin(x))
        {
            return ERROR;
        }
        result = (x - a) / sin(x);
    }
    else
    {
        result = (x * 10.0) / (c - 6.0);
    };

    if (debug)
        if (!(((int)floor(a) | (int)floor(b)) & ((int)floor(a) | (int)floor(c))))
        { // 00001010 & 00000100 = 00000000
            printf("integral value");
        }
        else
        {
            printf("floating point value");
        }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc < 7)
    {
        fputs("invalid argument count\n", stderr);
        return 1;
    }

    float k = (float)atof(argv[1]);
    float h = (float)atof(argv[2]);
    float step = (float)atof(argv[3]);

    do
    {
        float var = function_set(k, (float)atof(argv[4]), (float)atof(argv[5]), (float)atof(argv[6]), 0);
        k += step;

        if (var == ERROR)
        {
            printf("undef. ");
            continue;
        }

        printf("%.2f ", var);
    } while (k <= h);

    return 0;
}
