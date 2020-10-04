#include <iostream>
#include <cstring>
#include <fstream>
#include <utility>

using namespace std;

struct File {
    
    char* name;
    char* date;
    char* time;
    int size;
};

void setValues(File* pfile, const char* _name, const char* _date, const char* _time, int _size){
    pfile->name = new char[strlen(_name+1)];
    strcpy(pfile->name, _name);
    pfile->date = new char[strlen(_date+1)];
    strcpy(pfile->date, _date);
    pfile->time = new char[strlen(_time+1)];
    strcpy(pfile->time, _time);
    pfile->size = _size;
}

void freeMemory(File* pfile){
    delete[] pfile->name;
    delete[] pfile->date;
    delete[] pfile->time;
}

void changeElements(File* pfile, int n){
    char file[15];
    
    int choice=1;
    cout << "Информацию о каком файле хотите поменять? (введите название)";
    cout << endl;
    cin >> file;
    cout << endl;
    for (int i=0; i<n; i++){
        if(strcmp(pfile[i].name, file)==0){
            while(choice){
                cout << "Что вы хотите поменять?" << endl;
                cout << "1.Название" << endl;
                cout << "2.Дату создания" << endl;
                cout << "3.Время создания" << endl;
                cout << "4.Размер" << endl;
                cout << endl;
                cin >> choice;
                cout << endl;
                switch(choice){
                    case 1: cout << "Введите новое название: ";
                        cin >> pfile[i].name;
                        break;
                    case 2: cout << "Введите новый дату создания: ";
                        cin >> pfile[i].date;
                        break;
                    case 3: cout << "Введите новое время создания: ";
                        cin >> pfile[i].time;
                        break;
                    case 4: cout << "Введите новый размер: ";
                        cin >> pfile[i].size;
                        break;
                        
                    default: cout << "Выберите вариант из предложенных!";
                }
                choice=0;
            }
        }
    }
}

void fromFile(int n, File* pfile){
    
    FILE* fp;
    fp = fopen("/Users/small/Desktop/Новая папка/Лена/программы/21 сентября/21 сентября/файлы.txt", "r");
    ifstream infile("/Users/small/Desktop/Новая папка/Лена/программы/21 сентября/21 сентября/файлы.txt");
    
    if (fp==NULL){
        cout << "Ошибка! Не удалось получить доступ к файлу." << endl;
    }
    char* line;
//    while(getline(infile, line)){
//        istringstream l(line);
//        l >> pfile[0].name
//    }
    size_t len=0;
    while(getline(&line, &len,fp) !=-1){
        cout << line;
        for(int i=0; i<n; ++i){
        pfile[i].name = new char[strlen(line)];
        strcpy(pfile[i].name, line);
            
        pfile[i].date = new char[strlen(line)];
        strcpy(pfile[i].date, line);
            
            pfile[i].time = new char[strlen(line)];
            strcpy(pfile[i].time, line);
            
            pfile[i].size = (int)atoi(line);
        }
    }
    fclose(fp);
}


void print(File item)
{
    printf("\n|");
    printf("\t%-10s",item.name);
    printf("\t|");
    printf("\t%-18s",item.date);
    printf("\t|");
    printf("\t%-18s",item.time);
    printf("\t|");
    printf("\t%-4d",item.size);
    printf("\t|");
    printf("\n_____________________________________________________________________________\n");
    
}

void printFull(File* pfile, int n){
    printf("_____________________________________________________________________________\n");
    printf("|");
    printf("\tНазвание");
    printf("\t|");
    printf("\tДата создания");
    printf("\t\t|");
    printf("\tВремя создания");
    printf("\t\t|");
    printf("\tРазмер");
    printf("\t|");
    printf("\n_____________________________________________________________________________");
    for(int i = 0; i < n; i++)
        print(pfile[i]);
}

void SortBySize(File* pfile, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++){
                    
                    if(pfile[i].size > pfile[j].size)
                        
                    {   File temp = pfile[i];
                        
                        pfile[i] = pfile[j];
                        
                        pfile[j] = temp;
                    }
                }
                
        
            }

        }


        int main () {
            
            int n=0;
            File* pfile = NULL;
            
            cout << "Введите количество элементов: ";
            cin >> n;
            pfile = new File[n];
          
            //fromFile(n, pfile);
            setValues(&pfile[0], "File1", "12.03.2000", "12:10", 28);
            setValues(&pfile[1], "File2", "22.04.1998", "02:30", 12);
            setValues(&pfile[2], "File3", "20.02.2000", "10:29", 15);
            setValues(&pfile[3], "File4", "01.08.1992", "05:40", 29);
            printFull(pfile, n);
            changeElements(pfile, n);
            SortBySize(pfile, n);
            printFull(pfile, n);
            freeMemory(pfile);
            
            return 0;
        }
