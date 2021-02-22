#ifndef __FUNCTIONS__
#define __FUNCTIONS__

struct FILM
{
    char *nam;
    char *country;
    char *reg;
    char *janr;
    int year;
};

void menu();
void strucalloc(struct FILM **&STRPOINT, const int SIZE_MS);
void strucfree(struct FILM **&STRPOINT, const int SIZE_MS);
void strucinp(struct FILM **&STRPOINT, const int i);
void strucoutp(struct FILM **STRPOINT, const int i);
void search(struct FILM **STRPOINT, const int SIZE_MS);
void strucsort(struct FILM **&STRPOINT, const int SIZE_MS);
void strucread_f(struct FILM **&STRPOINT, const char *file_name, const int SIZE_MS);
void strured(struct FILM **&STRPOINT, const int numred);
void myscan(int *number);
void add_element(struct FILM **&STRPOINT, int *SIZE_MS);
void del_element(struct FILM **&STRPOINT, const int delnum, int *SIZE_MS);
void _del_element(struct FILM **&STRPOINT, const int numofdel, const int firstdel, int *SIZE_MS);
void paste_element(struct FILM **&STRPOINT, const int pastenum, int *SIZE_MS);
void strucfprintf(struct FILM **STRPOINT, const char *file_name, const int SIZE_MS);

#endif
