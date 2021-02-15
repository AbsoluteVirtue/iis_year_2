#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

struct record
{
    void print();

    std::string code;
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

struct Vector
{
    void push_back(record * obj);
    record * begin();
    record * end();

    size_t size{0};
    size_t length{0};
    record* *data{nullptr};
};

bool _compare(record * a, record * b);
void print(record * arr, size_t len) ;

int main(int argc, char const *argv[])
{
    record * data = new record [2];
    data[0]= {"Test 1", "1", 1, 1};
    data[1]= {"Test 2", "2", 2, 2};
    print(data, 2);

    FILE * input = fopen("census.csv", "r");
    if (input == NULL) return -1;

    Vector v;

    char line [100] = {};
    while (fgets(line, 100, input))
    {
        const char * delim = ",\"\n";
        char * token = strtok(line, delim);        
    
        if (!strcmp(token, "Code")) continue;
    
        record * tmp = new record;
        while(token)
        {
            if (tmp->code == "") 
            {
                tmp->code = token;
            }
            else if (tmp->birthplace == "") 
            {
                tmp->birthplace = token;
            }
            else if (tmp->night_pop == 0) 
            {
                tmp->night_pop = (long double)atol(token);
            }
            else if (tmp->resident_pop == 0) 
            {                
                tmp->resident_pop = (long double)atol(token);
            }
            token = strtok(NULL, delim);
        }
        v.push_back(tmp);
    }

    for (auto it : v)
    {
        std::cout << it.code << "\t";
    }

    return 0;
}

record * Vector::begin()
{
    return *data;
}

record * Vector::end()
{
    return *(data) + length;
}

void Vector::push_back(record * obj)
{
    if (length >= size)
    {
        size = (size * 2) + 1;
        record ** tmp = new record * [size];
        if (length > 0)
        {
            std::copy(data, data + length, tmp);
        }
        if (data != nullptr)
        {
            delete [] data;
        }
        data = tmp;
    }
    data[length] = obj;
    length += 1;
}

bool _compare(record * a, record * b)
{
    return (a->night_pop > b->night_pop);
}

void print(record * arr, size_t len) 
{
    for (size_t i = 0; i < len; i++)
    {
        std::cout << arr[i].code << "\n";
    }
    
    delete [] arr;
}
