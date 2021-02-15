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
    void pop_back();
    record * begin();
    record * end();

    size_t size{0};
    size_t length{0};
    record ** data{nullptr};
};

bool compare_name(record * a, record * b);

int main(int argc, char const *argv[])
{
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

    v.pop_back();
    v.pop_back();

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

void Vector::pop_back()
{
    length -= 1;
    delete data[length];
    if (length <= size / 2)
    {
        size = length;
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
}

bool compare_population(record * a, record * b)
{
    return (a->night_pop > b->night_pop);
}
