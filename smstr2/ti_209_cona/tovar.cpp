#include<bits/stdc++.h>
#include "tovar.h"

using namespace std; // так лучше не делать

void dinamiceskoe_videlenie_pamiati(tovar *&novii_massif,int &a){
    if(!novii_massif){
        // размер массива надо передавать как аргумент
        puts("vvedite razmer massiva"); 
        scanf("%d",&a);
        // желательно еще проверить, если величина числовая
        if(a!=0) 
            novii_massif=new tovar[a];
        else
            novii_massif=NULL;
    }
}

void vivod_massiva_na_ekran(tovar*&novii_massiv,int &a){
    if(!novii_massiv){ // должен быть while, либо выходить из функции при неудачном выделении
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    for (int i = 0; i < a; i++)
    {
        puts(novii_massiv[i].nazvanie.c_str());
        puts(novii_massiv[i].country.c_str());
        puts(novii_massiv[i].proizvoditel.c_str());
        puts(novii_massiv[i].rod_izdelia_tovara.c_str());
        printf("%d\n\n",novii_massiv[i].price);
    }    
}

void vvod_massiva_s_klav_(tovar *&novii_massiv, int &a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    for (int i = 0; i < a; i++)
    {
        cin.ignore();
        puts("vvedite nazvanie tovara");
        getline(cin,novii_massiv[i].nazvanie);
        puts("vvedite stranu proizvoditelea");
        getline(cin,novii_massiv[i].country);
        puts("vvedite");
        getline(cin,novii_massiv[i].proizvoditel);
        puts("vvedite");
        getline(cin,novii_massiv[i].rod_izdelia_tovara);
        puts("vvedite number");
        cin>>novii_massiv[i].price;
    }
}

void scitivanie_elementov_iz_faila(tovar*&novii_massif,const char *name_of_file, int &a){
    if(!novii_massif){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massif,a);
    }
    ifstream file(name_of_file);
    if(file.is_open()){
        cout<<"da"<<endl;
    }
    else{
        cout<<"ne"<<endl;;
        // надо выходить из функции
    }
        tovar *vrem = new tovar;
        for(int i=0;i<a;i++){
            string k;
            file.ignore();
            getline(file,k);
            vrem->nazvanie=k;
            getline(file,k);
            vrem->country=k;
            getline(file,k);
            vrem->proizvoditel=k;
            getline(file,k);
            vrem->rod_izdelia_tovara=k;
            getline(file,k);
            vrem->price=atoi(k.c_str());
            novii_massif[i]=*vrem;
        }
        delete vrem; // ни в коем случае нельзя удалять здесь указатель
        // он нужен для чтения данных из массива в других функциях
        puts("fail scitalsea");
}

bool compare_vozrastanie_nazvanie (tovar a,tovar b){
    return a.nazvanie<b.nazvanie;
}
bool compare_ubivanie_nazvanie(tovar a,tovar b){
    return a.nazvanie>b.nazvanie;
}
bool compare_vozrastanie_country(tovar a,tovar b){
    return a.country<b.country;
}
bool compare_ubivanie_country(tovar a,tovar b){
    return a.country>b.country;
}
bool compare_vozrastanie_proizv (tovar a,tovar b){
    return a.proizvoditel<b.proizvoditel;
}
bool compare_ubivanie_proizv(tovar a,tovar b){
    return a.proizvoditel>b.proizvoditel;
}
bool compare_vozrastanie_rod_tov(tovar a,tovar b){
    return a.rod_izdelia_tovara<b.rod_izdelia_tovara;
}
bool compare_ubivanie_rod_tov(tovar a,tovar b){
    return a.rod_izdelia_tovara>b.rod_izdelia_tovara;
}
bool compare_vozrastanie_tsena (tovar a,tovar b){
    return a.price<b.price;
}
bool compare_ubivanie_tsena(tovar a,tovar b){
    return a.price>b.price;
}

void sortirovka(tovar*&novii_massiv, int &a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    int KK,LL;
    while(1){
        cout<<"po kakomy poliu hotite otsortirovat'"<<endl;
        cout<<"[1] for nazvanie"<<endl;
        cout<<"[2] for strana "<<endl;
        cout<<"[3] for proizvoditel"<<endl;
        cout<<"[4] for rod izdelia tovvara"<<endl;
        cout<<"[5] for tsena"<<endl;
        cin>>KK;
        if((KK<1)||(KK>5)){
            cout<<"vvedite nomer iz reada"<<endl;
        }
        else{
            break;
        }
    }
    while(1){
        cout<<"po kakomy vidu hotite otsortirovat'"<<endl;
        cout<<"[1]vozrastanie"<<endl;
        cout<<"[2]ubivanie"<<endl;
        cin>>LL;
        if((LL>2)||(LL<1)){
            cout<<"viberite nomer iz reada"<<endl;
        }
        else{
            break;
        }
    }
    if(KK==1&&LL==1){
        sort(novii_massiv,novii_massiv+a,compare_vozrastanie_nazvanie);}
    else if(KK==1&&LL==2){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_nazvanie);}
    else if(KK==2&&LL==1){
        sort(novii_massiv,novii_massiv+a,compare_vozrastanie_country);}
    else if(KK==2&&LL==2){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_country);}
    else if(KK==3&&LL==1){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_proizv);}
    else if(KK==3&&LL==2){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_proizv);}
    else if(KK==4&&LL==1){
        sort(novii_massiv,novii_massiv+a,compare_vozrastanie_rod_tov);}
    else if(KK==4&&LL==2){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_rod_tov);}
    else if(KK==5&&LL==1){
        sort(novii_massiv,novii_massiv+a,compare_vozrastanie_tsena);}
    else if(KK==5&&LL==2){
        sort(novii_massiv,novii_massiv+a,compare_ubivanie_tsena);}   
}

void poisk_elementa_massiva(tovar*&novii_massiv,  int &a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    int KK;
    string LL;
    cout<<"vvedite stroky"<<endl;
    cin>>LL;
    for (int i = 0; i <a ; i++){
        if(strcmp(LL.c_str(),novii_massiv[i].nazvanie.c_str())==0){
            cout<<"nashlos' sovpadenie nazvania^:\n"<<novii_massiv[i].nazvanie<<endl;
        }        
        if (strcmp(LL.c_str(),novii_massiv[i].proizvoditel.c_str())==0){
            cout<<"nashlos' sovpadenie proizvoditelia^:\n"<<novii_massiv[i].proizvoditel<<endl;     
        }
        if (strcmp(LL.c_str(),novii_massiv[i].country.c_str())==0){
            cout<<"nashlos' sovpadenie strani^:\n"<<novii_massiv[i].country<<endl;
        }
        if (strcmp(LL.c_str(),novii_massiv[i].rod_izdelia_tovara.c_str())==0){
            cout<<"nashlos' sovpadenie naznacenia tovara^:\n"<<novii_massiv[i].rod_izdelia_tovara<<endl;
        }
        if (atoi(LL.c_str())==novii_massiv[i].price){
            cout<<"nashlos' sovpadenie tseni^:\n"<<novii_massiv[i].price<<endl;
        }
    }
}

void redaktirovanie_elementov(tovar*&novii_massiv, int &a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    int KK;
    string L;
    while (1){
        cout<<"vvedite index massiva dlea izmenenia,counts from 1"<<endl;
        cin>>KK;
        KK--;
        if(KK<0&&KK>a){
            cout<<"nedopustimoe znacenie"<<endl<<"vvedite esche raz"<<endl;
        }
        else{
            break;
        }
    }
    tovar * vrem =new tovar;
    cout<<"vvedite nazvanie"<<endl;
    cin>>L;
    vrem->nazvanie=L;
    cout<<"vvedite stranu"<<endl;
    cin>>L;
    vrem->country=L;
    cout<<"vvedite proizvoditelia"<<endl;
    cin>>L;
    vrem->proizvoditel=L;
    cout<<"vvedite rod izdelia tovara"<<endl;
    cin>>L;
    vrem->rod_izdelia_tovara=L;
    cout<<"vvedite tsenu"<<endl;
    cin>>L;
    vrem->price=atoi(L.c_str());
    novii_massiv[KK]=*vrem;
    delete vrem;
}


void push_back(tovar*&novii_massiv,int &a){
    if(!novii_massiv){
        // здесь это не надо
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    ++a;
    tovar*vrem=new tovar[a];
    for (int i = 0; i < a-1; i++)
    {
        vrem[i]=novii_massiv[i];
    }
    delete[]novii_massiv;
    novii_massiv=vrem;
}

void delete_element(tovar*&novii_massiv,int&a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    a--;
    tovar*vrem=new tovar[a];
    int  b,i=0,j=0;
    while(1){
        cout<<"what element do you want to eraze?>,"<<endl;
        cin>>b;
        b--;
        if(b<0||b>a){
            cout<<"net takovogo"<<endl;
        }
        else{
            break;
        }
    }
    while(i<a){
        if(i!=b){
            vrem[j]=novii_massiv[i];
            i++;
        }
        else{
            i++;
            vrem[j]=novii_massiv[i];
        }
        j++;

    }
    delete[]novii_massiv;
    novii_massiv=vrem;
    if(!a){
        osvobojdenie_pamiati(novii_massiv,a);
    }
}

void vstavka_novogo_elementa(tovar*&novii_massiv,int &a){
    if(!novii_massiv){
        cout<<"vvedite snaciala razmer massifa"<<endl;
        dinamiceskoe_videlenie_pamiati(novii_massiv,a);
    }
    a++;
    int b,i=0,j=0;
    tovar *vrem=new tovar[a];
    while(1){
        cout<<"v kakoe mesto vi hotite vstavit' element?>"<<endl;
        cin>>b;
        b--;
        if(b<0||b>a){
            cout<<"nedopustimoe znacenie "<<endl;
        }
        else
        break;
    } 
    while(i<a){
        if(i!=b){
            vrem[i]=novii_massiv[j];
            j++;
        }
        else{
            ;
        }
        i++;
    }
    delete[]novii_massiv;
    novii_massiv=vrem;
}

void zapiss_elementov_v_fail (tovar*&novii_massiv,int &a,const char* nazvanie_faila){
    FILE*fp;
    fp=fopen(nazvanie_faila,"w");
    if(!fp){
        cout<<"fail ne otkrilsea";
    }
    else{
        cout<<"fail otkrilsea";
    }
    for (int i = 0; i < a; i++)
    {
        fprintf(fp,"%s\n",novii_massiv[i].nazvanie.c_str());
        fprintf(fp,"%s\n",novii_massiv[i].country.c_str());
        fprintf(fp,"%s\n",novii_massiv[i].proizvoditel.c_str());
        fprintf(fp,"%s\n",novii_massiv[i].rod_izdelia_tovara.c_str());
        fprintf(fp,"%d\n",novii_massiv[i].price);
    }
    fclose(fp);
}

void osvobojdenie_pamiati(tovar*&novii_massiv,int &a){
    delete []novii_massiv;
    novii_massiv=NULL;
}
