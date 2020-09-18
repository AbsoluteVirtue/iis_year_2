#include <iostream>
#include <cstring>
using namespace  std;

struct House{
    char *constructorName;
    char *address;
    int floors;
    House() {
        this->constructorName = nullptr;
        this->address = nullptr;
        this->floors = 0;
    }
    House(const char *constructorName, const char *address, int floors){
        int len = strlen(constructorName);
        this->constructorName = new char[len + 1];
        for (int i=0; i < len; i += 1) {
            this->constructorName[i] = constructorName[i];
        }
        this->constructorName[len] = '\0';
        // this->constructorName = constructorName;
        len = strlen(address);
        this->address = new char[len + 1];
        for (int i=0; i < len; i += 1) {
            this->address[i] = address[i];
        }
        this->address[len] = '\0';
        // this->address = address;
        this->floors = floors;
    }
    bool equals(House house){
        if(address == house.address && constructorName == house.constructorName && floors == house.floors)
            return true;
        return false;
    }
    char *getConstructorName() const {
        return constructorName;
    }
    void setConstructorName(const char *constructorName) {
        // this->constructorName = constructorName;
    }
    char *getAddress() const {
        return address;
    }
    void setAddress(char *address) {
        this->address = address;
    }
    int getFloors() const {
        return floors;
    }
    void setFloors(int floors) {
        this->floors = floors;
    }
};
void sortByFloors(House *houses,int size){
    for (int i = 0;i < size - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < size; j++)
            if (houses[j].getFloors() <= houses[k].getFloors())
                k = j;
        swap(houses[i],houses[k]);
    }
}
void sortByAlph(House *houses,int size){
    for (int i = 0; i < size - 1; ++i){
        int k = i;
        for (int j = i + 1; j < size; j++)
            if (strcmp(houses[j].getConstructorName(),houses[k].getConstructorName())>0 )
                k = j;
        swap(houses[i],houses[k]);
    }
}
void print(House *houses, int size){
    for(int i = 0; i < size;i++){
        cout<<houses[i].getConstructorName()<<" "<<houses[i].address <<" "<<"floors "<< houses[i].floors<<endl;
    }
}
int main() {
    int size = 4;
    House *houses = new House[size];
    houses[0] = House("ProEmobil","Testemiteanu 11",10);
    houses[1] = House("Glorinal","Testemiteanu 32",19);
    houses[2] = House("Proemobil","Testemiteanu 11",10);
    houses[3] = House("Glorinal","Testemiteanu 13",5);

    houses[0].equals(houses[1]);

    cout<<"Floors sort"<<endl;
    sortByFloors(houses,size);
    print(houses,size);
    cout<<"Alph sort"<<endl;
    sortByAlph(houses,size);
    print(houses,size);
    
    delete [] houses;
    return 0;
}