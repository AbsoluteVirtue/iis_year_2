#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <string>


void memory(int *** a, int n, int m) {
    *a = (int **)calloc(n, sizeof(int *));
    for (size_t i = 0; i < n; i++)
    {
        (*a)[i] = (int *)calloc(m, sizeof(int));
    }
}


void print(int ** a, int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}


struct M {
    int n;
    char * s;
    std::string S;
};


void struct_examples() {
    M mys = {0, {}, ""};

    char buf[80];

    std::cin >> mys.n >> buf >> mys.S;

    size_t buflen = strlen(buf);

    mys.s = (char *)malloc(buflen + 1);
    strcpy(mys.s, buf);

    std::cout << mys.n << "\t" << mys.s << "\t" << mys.S;
}


int main(int argc, char const *argv[])
{
    int ** A = NULL;
    int N = 4, M = 4;

    int option = -1;

    while(option)
    {
        printf("press 1-7 for options:\n");
        scanf("%i", &option);
        if (!option) {
            return 0;
        } else if (!A && option == 1) {
            memory(&A, N, M);
        } else if (A && option == 2) {
            print(A, N, M);
        } else {
            printf("no such option exists\n");
        }
    }
}
