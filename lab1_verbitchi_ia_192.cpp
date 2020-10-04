#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Country
{
    
private:
    
    char *name = nullptr;
    char *materic = nullptr;
    int population = 0;
    
public:
    void setName(const char *name){
        size_t len = strlen(name)+1;
        this->name = new char[len];
        for(size_t i = 0; i< len; ++i){
            this->name[i] = name[i];
        }
        this->name[len] = '\0';
    }
    
    void setPopulation(int population){
        this->population = population;
    }
    
    void setMateric(const char *materic){
        size_t len = strlen(materic)+1;
        this->materic = new char[len];
        for(size_t i = 0; i< len; ++i){
            this->materic[i] = materic[i];
        }
        this->materic[len] = '\0';
    }
    
    const char *getName(){
        return this->name;
    }
    
    const char *getMateric(){
        return this->materic;
    }
    
    int getPopulation(){
        return this->population;
    }
    
    Country(const char *name, const char *materic, int population)
    {
        size_t len = strlen(name)+1;
        this->name = new char[len];
        for(size_t i = 0; i< len; ++i){
            this->name[i] = name[i];
        }
        this->name[len] = '\0';

        // this->name = new char[strlen(name) + 1];
        // strcpy(this->name, name);
        
        len = strlen(materic)+1;
        this->materic = new char[len];
        for(size_t i = 0; i< len; ++i){
            this->materic[i] = materic[i];
        }
        this->materic[len] = '\0';
        
        this->population = population;
    }
    
    ~Country()
    {
        delete[] name;
        delete[] materic;
    }
};

void printCountry(Country &country){
    cout<<country.getName()<<" "<<country.getMateric()<<" "<<country.getPopulation()<<endl;
}

void search(const char *name, Country *countries, int n){
    for (int i = 0; i<n; i++) {
        if(strcmp(countries[i].getName(), name) == 0){
            cout << "Exist country:" <<countries[i].getName()<<" in "<<countries[i].getMateric()<< " with population: "<< (countries[i].getPopulation()) << "."<< endl;
            return;
        }
    }
    cout << "Doesn't exist country for your paremetrs." <<endl;
}

void isPopulated(Country &country1, Country &country2){
    if(country1.getPopulation() > country2.getPopulation())
        cout << country1.getName() << " is more populated." <<endl;
    else if(country1.getPopulation() < country2.getPopulation())
        cout << country2.getName() << " is more populated." <<endl;
    else
        cout << country1.getName() << " and " << country2.getName() << " are the same." << endl;
}

int main(int argc, const char * argv[]) {
    
    const int n = 4;
    
    Country contries[n] = {
        
        Country("Russia", "Europe", 140000000),
        Country("Brazil", "South America", 80000000),
        Country("France", "Europe", 60000000),
        Country("Egypt", "Africa", 100000000),
        
    };
    
    
    // for (int i = 0; i<n; i++) {
    //     printCountry(contries[i]);
    // }
    
    // search("China", contries, n);
    // isPopulated(contries[0], contries[3]);
    
    return 0;
}
