#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

// #include "flight.cpp"
#include "flight.h"

using namespace std;

int main(int argc, char const *argv[])
{
    flight **mySchedule = NULL;
    int size=0;
    DynamicMemory(mySchedule, size);
    fileread(mySchedule);
    cout << "Nasha ishodnaya structura" << endl;
    PrintStruct(mySchedule, size);
    cout << "Poisk strocki" << endl;
    SearchSchedule(mySchedule, size);
    cout << "Sortirovka strukturi" << endl;
    ScheduleSort(mySchedule, size);
    cout << "Otsortirovanaya struktura" << endl;
    PrintStruct(mySchedule, size);
    cout << "Izmenenie Strukturi" << endl;
    Edit(mySchedule, size);
    cout << "Struktura s izmeneniem" << endl;
    PrintStruct(mySchedule, size);
    cout << "Dobavlenie strochki v konte structuri" << endl;
    AddNewString(mySchedule, size);
    cout << "Struktura s novoi strochkoi" << endl;
    PrintStruct(mySchedule, size);
    cout << "Udalenie strochki iz strukturi" << endl;
    Delete(mySchedule, size);
    cout << "Struktura s udalennoy strochkoi" << endl;
    PrintStruct(mySchedule, size);
    cout << "Vstavka strochki v structuru" << endl;
    Insert(mySchedule, size);
    cout << "Struktura so vstavlenoi strokoi" << endl;
    PrintStruct(mySchedule, size);
    cout << "Zapisi v file" << endl;
    FileWrite(mySchedule, size);
    Free(mySchedule, size);
    return 0;
}
