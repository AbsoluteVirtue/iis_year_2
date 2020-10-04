#include <iostream>
#include <cstring>

using namespace  std;


struct House{
private:
    char *constructorName {nullptr};
    char *address {nullptr};
    int floors {0};
    int apartments {0};

public:
    House() {

    }

    House(const char * constructorName ,const char *address, int floors, int apartments){
        unsigned int len = strlen(constructorName) + 1;

        this->constructorName = new char[len];
        for(int i = 0; i < len - 1; ++i)
            this->constructorName[i] = constructorName[i];

        this->constructorName[len] = '\0';

        len = strlen(address) + 1;

        this->address = new char[len];

        for(int i = 0; i < len - 1; ++i)
            this->address[i] = address[i];
        this->address[len] = '\0';

        this->floors = floors;
        this->apartments = apartments;
    }

    void copyHouse(House &house){

        this->setConstructorName(house.getConstructorName());
        this->setAddress(house.getAddress());
        this->setFloors(house.getFloors());
        this->setAddress(house.getAddress());

    }

    void setConstructorName(const char *constructorName) {
        delete [] this->constructorName;

        unsigned int len = strlen(constructorName) + 1;
        this->constructorName = new char[len];

        for(int i = 0; i < len -1 ;i++)
            this->constructorName[i] = constructorName[i];

        this->constructorName[len] = '\0';


    }

    void setAddress(const char *address) {
        delete [] this->address;

        unsigned int len = strlen(address) + 1;
        this->address= new char[len];

        for(int i = 0; i < len - 1;i++)
            this->address[i] = address[i];

        this->address[len] = '\0';
    }

    bool equals(House &house) const{
        if(strcmp(address,house.address) == 0 && strcmp(constructorName,house.constructorName)  == 0 && floors == house.floors && apartments == house.apartments)
            return true;
        return false;
    }


    void setFloors(int floors) {
        this->floors = floors;
    }

    void setApartments(int apartments) {
        this->apartments = apartments;
    }



    const char* getConstructorName() {
        return this->constructorName;
    }

    const char *getAddress()  {
        return address;
    }

    int getFloors()  {
        return floors;
    }

    int getApartments() {
        return apartments;
    }

    ~House() {
        delete [] address;
        delete [] constructorName;
    }
};


void print(House* houses, int size){
    for(int i = 0; i < size;i++){
        cout<<houses[i].getConstructorName()<<" "<<houses[i].getAddress() <<" "<<"floors "<< houses[i].getFloors()<<endl;
    }
}

void sortByFloors(House* houses,int size){
    House tmp =* new House();

    for(int i = 1; i < size; ++i)
    {
        for(int j = 0; size < size-i; size++)
        {
            if(houses[j].getFloors() <= houses[j+1].getFloors())
            {
                tmp.copyHouse(houses[j]);
                houses[j].copyHouse(houses[j+1]);
                houses[j+1].copyHouse(tmp);
            }
        }
    }
    print(houses,size);
}

void sortByAlph(House* &houses,int size){
    House tmp;

    for(int i = 1; i < size; ++i)
    {
        for(int j = 0; j < size-i; j++)
        {
            if(strcmp(houses[j].getConstructorName(),houses[j+1].getConstructorName()) > 0)
            {
                tmp.copyHouse(houses[j]);
                houses[j].copyHouse(houses[j+1]);
                houses[j+1].copyHouse(tmp);
            }
        }
    }
    print(houses,size);
}


int main() {
    const int size = 5;

    House * houses = new House[size];
    houses[0] = * new House("ProEmobil","Studenchiskaia 1",9, 100);
    houses[1] = * new House("AgroTera","Studenchiskaia 2",8, 90);
    houses[2] = * new House("ProHouse","Testeametianu 1",10, 220);
    houses[3] = * new House("ProStill","Testeametianu 20",12, 230);
    houses[4] = * new House("ProStill","Testeametianu 20",12, 230);

    cout<<endl<<"Arr"<<endl;
    print(houses,size);

    cout<<endl<<"SortArrByAlph"<<endl;
    sortByAlph(houses,size);

    cout<<endl<<"SortArrByFloors"<<endl;
    sortByFloors(houses,size);

    houses[0].setConstructorName("NewMobile");

    cout<<houses->getConstructorName()<<endl;

    cout<<houses[3].equals(houses[2]);


    delete [] houses;

    return 0;
}
