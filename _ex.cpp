#include <cstdio>
#include <cstdlib>
#include <cstring>


#define NO_OF_ENTRIES 6


struct Item
{
    long int night_population{0};
    long int usual_population{0};
    char * birthplace{nullptr};
    char * code{nullptr};
};


int main(int argc, char const *argv[])
{
    FILE *input = fopen("census.csv", "r");

    if (input == NULL)
    {
        printf("error: read file");
        return 1;
    }

    Item * list[NO_OF_ENTRIES] = {nullptr};
    const char *delimiters = ",.!?@#$%^&*();:\"\n\t";
    char line[160] = {};
    while (fgets(line, 160, input)) 
    {
        char * token = strtok(line, delimiters);
        if (!strcmp(token, "Code")) continue;

        Item * tmp = (Item *)malloc(sizeof(Item));
        size_t i = 0;
        while (token)
        {
            if (i == 0)
            {
                tmp->code = (char *)malloc(strlen(token) + 1);
                strcpy(tmp->code, token);
            }
            else if (i == 1)
            {
                tmp->birthplace = (char *)malloc(strlen(token) + 1);
                strcpy(tmp->birthplace, token);
            }
            else if (i == 2)
            {
                tmp->night_population = (long int)atol(token);
            }
            else if (i == 3)
            {
                tmp->usual_population = (long int)atol(token);
            }

            token = strtok(NULL, delimiters);
            ++i;
        }
        free(tmp);    
    }

    fclose(input);
    
    return 0;
}
