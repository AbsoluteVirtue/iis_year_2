//
//  main.cpp
//  OOP
//
//  Created by Nichita Macheev on 9/18/20.
//  Copyright © 2020 Nichita Macheev. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
    struct Houses {
        private:
            char *name {nullptr};
            char *adress {nullptr};
            int numberOfFloors {0};
            int numberOfFlats {0};
        public:
            //setter and getter for name
            void setName(char* _name){
                int len = strlen(_name);
                name = new char[len +1];
                for (int i=0; i<len; i++) {
                    name[i] = _name[i];
                }
                name[len] = '\0';
            }
        char *getName(){return name;}
            //setter and getter for adress
            void setAdress(char *_adress){
                unsigned long len = strlen(_adress);
                    adress = new char[len +1];
                    for (int i=0; i<len; i++) {
                        adress[i] = _adress[i];
                    }
                    adress[len] = '\0';
                }
        char *getAdress(){return adress;}
            //setter and getter  for numberOfFloors
        void setNumberOfFloors(int number){numberOfFloors = number;}
        int getNumberOfFloors(){return numberOfFloors;}
            // seter and getter for numberOfFlats
        void setnumberOfFlats(int number){numberOfFlats = number;}
        int getnumberOfFlats(){return numberOfFlats;}
        void changeValue(char* value, Houses* house, int position, int indicator){
            switch (indicator){
                case 1:
                    deleteName(house, position);
                    setName(value);
                    break;
                case 2:
                    deleteAdress(house, position);
                    setAdress(value);
                    break;
                case 3:
                    setnumberOfFlats(atoi(value));
                    break;
                case 4:
                    setNumberOfFloors(atoi(value));
                    break;
            }
        }
        void deleteMemory(Houses* house, int i){
            deleteName(house, i);
            deleteAdress(house, i);
            
        };
    private:
        void deleteName(Houses* house, int position) { delete[] house[position].name; }
        void deleteAdress(Houses* house, int position) { delete[] house[position].adress; }
    };
        void sortingArray(Houses* house, int n){
            Houses temp;
            int choice{0};
            cout<<"1.Sort Ascending by flats\n2.Sort Descending by alpfabet\n";
            cin>>choice;
                switch (choice){
                    case 1:
                        for (int i = 0; i < n; i++)
                            for (int j = n - 1; j >= i + 1; j--)
                                if (house[j].getnumberOfFlats() < house[j - 1].getnumberOfFlats()){
                                    temp = house[j];
                                    house[j] = house[j - 1];
                                    house[j - 1] = temp;
                                }
                        break;
                    case 2:
                        for (int i = 0; i < n-1; i++)
                            for (int j = i + 1; j < n; j++)
                                if (strcmp(house[i].getName(), house[j].getName())>0){
                                    temp = house[j];
                                    house[j] = house[j - 1];
                                    house[j - 1] = temp;
                                }
                        break;
                    default:
                        printf("Try again.\n");
                        break;
                }
        }
        void fieldsOfStruct(){
            cout << "1. Name" << endl;
            cout << "2. Adress" << endl;
            cout << "3. Number of floors" << endl;
            cout << "4. Number of flats" << endl;
        }
//function to change data
        void printValue(Houses* house, int i){
            cout << "\nHouse #" << i + 1 << endl;
            cout << "\tName: " << house[i].getName() << endl;
            cout << "\tAdress: " << house[i].getAdress() << endl;
            cout << "\tNumber of floors: " << house[i].getNumberOfFloors() << endl;
            cout << "\tNumber of flats: " << house[i].getnumberOfFlats() << endl;
        }
    void print(Houses* house, int n){
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            printValue(house,i);
        }
    }
    void menu(){
        cout << "\nMenu:" << endl;
        cout << "1. Initialization of houses" << endl;
        cout << "2. Sorting Houses" << endl;
        cout << "3. Print elements" << endl;
        cout << "4. Compare elements" << endl;
        cout << "5. Change element" << endl;
        cout << "6. Menu" << endl;
        cout << "7. Exit and delete memory" << endl;
    
    }
// initialization
    void initialization(Houses* house, int n){
    char name[100];
    char adress[100];
    int numberOfFloors{0}, numberOfFlats{0};
        for (int i = 0; i < n; i++){
            cout << "\nHouse #" << i + 1 << endl;
            cout << "\tName: ";
            cin >> name;
                house[i].setName(name);
            cout << "\tAdress: ";
            cin >> adress;
                house[i].setAdress(adress);
            cout << "\tNumber of floors: ";
            cin >> numberOfFloors;
                house[i].setNumberOfFloors(numberOfFloors);
            cout << "\tNumber of flats: ";
            cin >> numberOfFlats;
                house[i].setnumberOfFlats(numberOfFlats);
        }
    }
    void compareFunction(Houses* house, int n){
        int positionFirst{0},
        positionSecond{0},
        tempFirst{0},
        tempSecond{0},
        choice{0};
            printf("1.Compare houses by Flats\n2.Compare houses by Floors\n");
            scanf("%d", &choice);
        switch (choice){
            case 1:
                cout << "\nNumber of first house to compare" << endl;
                cin >> positionFirst;
                cout << "\nNumber of second house to compare" << endl;
                cin >> positionSecond;
                    for (int i = 0; i < n; i++){
                        tempFirst=house[positionFirst].getnumberOfFlats();
                        tempSecond=house[positionSecond].getnumberOfFlats();
                    }
                if(tempFirst > tempSecond)cout<<"The first house has more flats than the second"<<endl;
                else if(tempFirst < tempSecond)cout<<"The first house has fewer flats than the second";
                else if(tempFirst == tempSecond)cout<<"The first house has the same number of  flats as the second";
                break;
            case 2:
                cout << "\nNumber of first house to compare" << endl;
                cin >> positionFirst;
                cout << "\nNumber of second house to compare" << endl;
                cin >> positionSecond;
                    for (int i = 0; i < n; i++){
                        tempFirst=house[positionFirst].getNumberOfFloors();
                        tempSecond=house[positionSecond].getNumberOfFloors();
                    }
                if(tempFirst > tempSecond)cout<<"The first house has more floors than the second";
                else if(tempFirst < tempSecond)cout<<"The first house has fewer floors than the second";
                else if(tempFirst == tempSecond)cout<<"The first house has the same number of  floors as the second";
                break;
            default:
                printf("Try again.\n");
                break;
        }
    }
    void changeInfo(Houses* house, int n){
        char name[100];
        int value;
        int choice;

        cout << "\nWhich element to change? " << " exist [1.." << n << "]" << endl << "Your choice: ";
        cin >> value;
        value--;

        cout << "\nWhich field to change? " << endl;
            fieldsOfStruct();
        cout << "Your choice: ";
            cin >> choice;

        cout << "\nEnter changes: ";
            cin >> name;
            if (value < n && value >=0){
                house[value].changeValue(name, house, value, choice);
                print(house, n);
            }
            else{
                cout << "No such object exists" << endl;
            }
    }
int main(int argc, const char * argv[]) {
     // number of objects
        cout << "Enter number of objects: ";
        int n{0};
        cin >> n;
        // memory allocation
        Houses* house = new Houses[n];
        menu();
        int choice{0};
        while (choice != 7){
            cout << "\nYour choice (menu): ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                initialization(house, n);
                break;
            case 2:
                sortingArray(house, n);
                break;
            case 3:
                print(house, n);
                break;
            case 4:
                compareFunction(house,n);
                break;
            case 5:
                changeInfo(house, n);
                break;
            case 6:
                menu();
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            house->deleteMemory(house, i);
        }
    return 0;
}