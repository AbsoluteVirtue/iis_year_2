#ifndef Delim_
#define Delim_

struct flight
{
    std::string number{};
    std::string destination{};
    std::string departing_time{};
    std::string arriving_time{};
    std::string cost{};
};

void DynamicMemory(flight **&Array, int &a);
void fileread(flight **&Array);
void SearchSchedule(flight **&Array, int a);
void PrintStruct(flight **&Array, int a);
void ScheduleSort(flight **&Array, int a);
void Edit(flight **&Array, int a);
void AddNewString(flight **&Array, int &a);
void Delete(flight **&Array, int &a);
void Insert(flight **&Array, int &a);
void FileWrite(flight **&Array, int a);
void Free(flight **&Array, int a);

#endif
