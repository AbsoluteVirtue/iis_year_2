#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

struct record
{
    const std::string str();
    void print();

    std::string code;
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

struct Vector
{
    struct iter 
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = record *;
        using pointer = value_type *;
        using reference = value_type &;

        iter(pointer p): _p(p) {}

        reference operator*() const { return *_p; }
        pointer operator->() const { return _p; }
        iter & operator++() 
        { 
            ++_p; 
            return *this;
        }
        iter operator++(int)
        {
            iter tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const iter & lhs, const iter & rhs) { return lhs._p == rhs._p; }
        friend bool operator!=(const iter & lhs, const iter & rhs) { return lhs._p != rhs._p; }

    private:
        pointer _p;
    };

    void push_back(record * obj);
    void insert(record * obj, const size_t idx);
    void pop_back();
    void erase(const size_t idx);
    void clear();
    void print();
    iter begin();
    iter end();

private:
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

    v.insert(new record({"test", "TEST", 0, 0}), 0);

    v.print();

    v.erase(0);

    v.clear();

    return 0;
}

const std::string record::str()
{
    std::ostringstream out;
    out << this->birthplace << " ("
        << this->code << ") "
        << this->night_pop << "/"
        << this->resident_pop;

    return out.str();
}

void record::print()
{
    std::cout << this->str() << "\n";
}

Vector::iter Vector::begin()
{
    return iter(&this->data[0]);
}

Vector::iter Vector::end()
{
    return iter(&this->data[this->length]);
}

void Vector::print()
{
    for (size_t i = 0; i < this->length; i++)
    {
        this->data[i]->print();
    }
}

void Vector::clear()
{
    for (size_t i = 0; i < this->length; ++i)
    {
        delete this->data[i];
    }
    delete [] this->data;
    this->size = 0;
    this->length = 0;
}

void Vector::push_back(record * obj)
{
    if (this->length >= this->size)
    {
        this->size = (this->size * 2) + 1;
        record ** tmp = new record * [this->size];

        if (this->length > 0)
        {
            std::copy(this->data, this->data + this->length, tmp);
        }

        if (this->data != nullptr)
        {
            delete [] this->data;
        }

        this->data = tmp;
    }

    this->data[this->length] = obj;
    this->length += 1;
}

void Vector::pop_back()
{
    this->length -= 1;
    delete this->data[this->length];

    if (this->length <= this->size / 2)
    {
        this->size = this->length;
        record ** tmp = new record * [this->size];

        if (this->length > 0)
        {
            std::copy(this->data, this->data + this->length, tmp);
        }

        if (this->data != nullptr)
        {
            delete [] this->data;
        }

        this->data = tmp;
    }
}

void Vector::insert(record * obj, const size_t idx)
{
    if (idx >= this->length) return;

    this->push_back(obj);
    std::swap(this->data[idx], this->data[this->length - 1]);
}

void Vector::erase(const size_t idx)
{
    if (idx >= this->length) return;

    std::swap(this->data[idx], this->data[this->length - 1]);
    this->pop_back();
}

bool compare_population(record * a, record * b)
{
    return (a->resident_pop > b->resident_pop);
}
