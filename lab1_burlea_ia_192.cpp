#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


#define COUNT 2
 
using namespace std;
 
struct Dogs
{
  char* breed;
  char* name;
  float age;
};

void SetValues(Dogs* Dog, const char* newB, const char* newN, float newAge);

void Print(Dogs* Dog, int count);

void Sort(Dogs* Dog, int count);

void FreeMemory(Dogs* Dog, int count);
 
int main()
{
    setlocale(LC_ALL, "");
  
	struct Dogs* head = 0;
  	
  	head = new Dogs[COUNT];
   
  	SetValues(&head[0], "Malinois", "Mako", 3);
    SetValues(&head[1], "German Shepherd", "Mukhtar", 3);

    Print(head, COUNT);
    
    Sort(head, COUNT);

    Print(head, COUNT);
    
    FreeMemory(head, COUNT);
}
 
void SetValues(Dogs *Dog, const char* newB, const char* newN, float newAge)
{
    Dog->breed = new char[strlen(newB+1)];
    strcpy(Dog->breed, newB);
     
    Dog->name = new char[strlen(newN+1)];
    strcpy(Dog->name, newN);
     
    Dog->age = newAge;
};
 
void Print(Dogs* Dog, int count)
{
    if(Dog!=NULL)
    {
        cout << "a  " << "b\t" << "c\t" << "d\t" << endl;
        cout << "------------------------------------------------" << endl;
        for(int i = 0; i < count; i++)
        {
          cout << i + 1 << "  " << Dog[i].breed<< '\t' << Dog[i].name << '\t' << Dog[i].age << endl;
        }
    }
    else
    {
        cout<<"a b c d";
    }
};

void Sort(Dogs* Dog, int count)
{
    for (int i = count - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (Dog[j].age > Dog[j+1].age)
            {
                Dogs tmp = Dog[j];
                Dog[j] = Dog[j + 1];
                Dog[j + 1] = tmp;
            }
            else if (Dog[j].age == Dog[j+1].age)
            {
                if(strcmp(Dog[j].name, Dog[j+1].name) > 0)
                {
                    Dogs tmp2 = Dog[j];
                    Dog[j] = Dog[j + 1];
                    Dog[j + 1] = tmp2;
                }
            }
        }
    }
};

void FreeMemory(Dogs* Dog, int count)
{
    for(Dogs* p = Dog; p < p + count; p++)
    {
        delete[] p->breed;
        p->breed = NULL;
    
        delete[] p->name;
        p->name = NULL;
    }
    delete[] Dog;
};
