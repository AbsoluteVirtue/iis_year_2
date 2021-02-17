#include "lab6_cars_lib.h"

int main()
{
    kniga** library = nullptr;

    library = finput(library);

    //SortLibrary(library);

    Output(library);

    int size = StructSize(library);

    PushBack(library);

    //DeleteBook(library);


    //SortLibrary(library);

    //Output(library);

   //DeleteBook(library);

    EditBook(library);

    size = StructSize(library);

    Output(library);

    DeleteBook(library);

    size = StructSize(library);

    Output(library);

    SearchBook(library);

    library = PushBack(library);

    SearchBook(library);

    Output(library);

    //library = DeleteBook(library);

    size = StructSize(library);
    for (int i = 0; i < size; i++)
    {
        delete [] library[i]->avtor;
        delete [] library[i]->nazv;
        delete [] library[i]->izdanie;
        delete[] library[i];
    }
    
    return 0;
}