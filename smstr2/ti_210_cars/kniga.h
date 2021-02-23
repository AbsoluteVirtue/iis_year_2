struct kniga
{
    char* avtor{ nullptr };
    char* nazv{ nullptr };
    int god{ 0 };
    char* izdanie{ nullptr };
    int str{ 0 };
    int tir{ 0 };
};

kniga** PushBack(kniga**& library, int & size);

void Output(kniga**& library, int& size);

void SearchBook(kniga**& library, int& size);

void DeleteBook(kniga**& library, int& size);

void SortLibrary(kniga**& library, int& size);

kniga** finput(kniga**& library, int & size);

void EditBook(kniga **& library, int& size);