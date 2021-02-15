#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "lab6_prosa_lib.h"

#define symbols_of_file 10000

void movie::print(){
    std::cout<<"Название:"<<this->name<<"\n";
    std::cout<<"Страна:"<<this->country<<"\n";
    std::cout<<"Режиссёр:"<<this->producer<<"\n";
    std::cout<<"Жанр:"<<this->genre<<"\n";
    std::cout<<"Год:"<<this->year<<"\n";
}

movie* memoAlloc(movie* mov,const int amountOfMovies){

    mov=new movie[amountOfMovies];

    return mov;
}

void massSearch(movie* mov,const int amountOfMovies){

    movie* start=mov;

    std::cout<<"Введите название фильма, который хотите найти: ";

    std::string search;

    std::cin>>search;

    std::cout<<"\n";

    for(;(*mov).name!=""&&mov<start+amountOfMovies;mov++){
        if((*mov).name==""){
            std::cout<<"Не найден фильм с таким названием";
            break;
        }

        if((*mov).name==search){
            (*mov).print();
            break;
        }
        mov++;
    }
}

void massSort(movie* mov,const int amountOfMovies){

    movie* start=mov;

    movie intermideateRec;

    while((*(mov+1)).name!=""&&mov+1<=start+amountOfMovies){

        movie i=*mov;
        movie* j=mov;

        while((*(j)).name!=""&&j<=start+amountOfMovies){
            if(i.name>(*j).name){

                intermideateRec=i;
                
                i=*j;

                *j=intermideateRec;

            }
            if(j==start+amountOfMovies)break;
            j++;
        }
        *mov=i;
        
        mov++;
    }

}

void massElEdit(movie* mov,const int amountOfMovies){

    movie* start=mov;

    std::cout<<"Введите название фильма,данные которого хотите изменить: ";

    std::string search;

    std::cin>>search;

    std::cout<<"\n";

    for(;(*mov).name!=""&&mov<start+amountOfMovies;mov++){
        
        if(search==(*mov).name){
            std::cout<<"Название: ";
            std::cin>>(*mov).name;
            std::cout<<"Страна: ";
            std::cin>>(*mov).country;
            std::cout<<"Режиссёр: ";
            std::cin>>(*mov).producer;
            std::cout<<"Жанр: ";
            std::cin>>(*mov).genre;
            std::cout<<"Год: ";
            std::cin>>(*mov).year;
            break;
        }
    }
}

movie* addEl(movie* mov,const int amountOfMovies){
    
    movie* start=mov;
    movie* newMov=nullptr;

    while((*mov).name!=""&&mov<=start+amountOfMovies){

        mov++;

    }
    movie* funMov=mov;

    if(mov>start+amountOfMovies){

        newMov=new movie[amountOfMovies+1];

        movie* indep1=start;
        movie* indep2=newMov;

        mov=indep1;

        while(1){
            *newMov=*mov;

            if(mov>=start+amountOfMovies-1)break;

            newMov++;
            mov++;

        }

        mov=indep1;

        start=indep2;

        delete[] mov;

        funMov=newMov+1;

    }

    std::cout<<"Введите данные нового фильма:\n\n";

    std::cout<<"Название: ";
    std::cin>>(*funMov).name;
    std::cout<<"Страна: ";
    std::cin>>(*funMov).country;
    std::cout<<"Режиссёр: ";
    std::cin>>(*funMov).producer;
    std::cout<<"Жанр: ";
    std::cin>>(*funMov).genre;
    std::cout<<"Год: ";
    std::cin>>(*funMov).year;

    return start;
}

int massElDelete(movie* mov,const int amountOfMovies){
    movie* start=mov;

    std::cout<<"Введите название фильма,данные которого хотите удалить: ";

    std::string search;

    std::cin>>search;

    std::cout<<"\n";

    while((*mov).name!=""){
        
        if(search==(*mov).name){
            break;
        }

        if(mov+1>=start+amountOfMovies){

            std::cout<<"Такого фильма нет.";

            return 1;
        }
        if(mov>=start+amountOfMovies)break;
        mov++;
    }

    while((*mov).name!=""){

        if(mov+1>=start+amountOfMovies)break;

        *mov=*(mov+1);

        mov++;

    }

    (*mov).name="";
    (*mov).country="";
    (*mov).producer="";
    (*mov).genre="";
    (*mov).year=0;

    return 0;
}

movie* insertEl(movie* mov,const int amountOfMovies){

    movie* start=mov;
    movie* newMov=nullptr;
    int count=0;

    std::cout<<"Введите название фильма,после которого хотите вставить новый фильм: ";

    std::string search;

    std::cin>>search;

    std::cout<<"\n";

    mov=start;

    for(;(*mov).name!="";mov++){
        
        if(search==(*mov).name){
            count=mov-start;
            break;
        }

        if(mov+1>=start+amountOfMovies){

            std::cout<<"Такого фильма нет.\n";

            return start;
        }
    }

    while((*mov).name!=""&&mov<=start+amountOfMovies){

        mov++;

    }

    movie* reverse=mov;

    if(mov>start+amountOfMovies){

        newMov=new movie[amountOfMovies+1];

        movie* indep1=start;
        movie* indep2=newMov;

        mov=indep1;

        while(mov<start+amountOfMovies){
            *newMov=*mov;

            if(mov==start+amountOfMovies-1)break;

            newMov++;
            mov++;

        }

        mov=indep1;

        start=indep2;

        delete[] mov;

        reverse=newMov+1;

    }

    for(reverse;reverse>start+count+1;--reverse){

        *reverse=*(reverse-1);
    }

    std::cout<<"Введите данные нового фильма:\n\n";

    std::cout<<"Название: ";
    std::cin>>(*reverse).name;
    std::cout<<"Страна: ";
    std::cin>>(*reverse).country;
    std::cout<<"Режиссёр: ";
    std::cin>>(*reverse).producer;
    std::cout<<"Жанр: ";
    std::cin>>(*reverse).genre;
    std::cout<<"Год: ";
    std::cin>>(*reverse).year;

    return start;
}

int recMassInFile(movie* mov,const int amountOfMovies,std::string* filePath){

    movie* start=mov;

    if((*mov).name==""){
        std::cout<<"В библиотеке нет ни одного фильма\n";
        return 1;
    }

    std::ofstream rez;
    rez.open(*filePath);

    while((*mov).name!=""&&mov<start+amountOfMovies&&rez.is_open()){

        rez<<(*mov).name<<"\t";
        rez<<(*mov).country<<"\t";
        rez<<(*mov).producer<<"\t";
        rez<<(*mov).genre<<"\t";
        rez<<(*mov).year<<"\n";

        mov++;
    }
    return 0;
}

int readMassEl(movie* mov,const int amountOfSymbols, FILE** in){

    if(*in==NULL){
        std::cout<<"Файл пустой\n";
        return 1;
    }

    char buf[symbols_of_file]={};

    const char *delim=",\"; \'";

    int i=0;

    while(fgets(buf,amountOfSymbols,*in)){

            char* token = strtok(buf,delim);
            int fullCount=0;   
            while(fullCount<5){
                
                int full=1;
                
                while(full){
                    token=strtok(token,delim);
                    if((*mov).name==""){

                        (*mov).name=token;

                        int count=strlen(token);

                        for(int z=0;z<=count;++z){

                            if((*mov).name[z]==*token){
                                *token='\0';
                                ++token;
                            }

                        }

                        ++token;

                        full=0;

                        fullCount++;      

                    }else if((*mov).country==""){

                        (*mov).country=token;

                        int count=strlen(token);

                        for(int z=0;z<=count;++z){

                            if((*mov).country[z]==*token){
                                *token='\0';
                                ++token;
                            }

                        }
                        ++token;

                        full=0;  

                        fullCount++;

                    }else if((*mov).producer==""){

                        (*mov).producer=token;

                        int count=strlen(token);
                        
                        for(int z=0;z<=count;++z){

                            if((*mov).producer[z]==*token){
                                *token='\0';
                                ++token;
                            }

                        }
                        ++token;

                        full=0;   

                        fullCount++;

                    }else if((*mov).genre==""){

                        (*mov).genre=token;

                        int count=strlen(token);
                        
                        for(int z=0;z<=count;++z){

                            if((*mov).genre[z]==*token){
                                *token='\0';
                                ++token;
                            }

                        }
                        ++token;

                        full=0;  

                        fullCount++; 

                    }else if((*mov).year==0){

                        (*mov).year=(int)atol(token);

                        full=0;   

                        fullCount++;

                    }

                }

            }

        mov++;
    }
    return 0;
}

void freeMemo(movie* mov){
    
    delete[] mov;

}