#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

struct record 
{
    void print();
    void edit(const std::string & n, const std::string & c, double np, double rp);

    std::string name{""};
    std::string code{""};
    double npop{0};
    double rpop{0};
};

size_t find_name(const std::vector<record *> & array, const std::string & n);
bool compare(record * lhs, record * rhs);
void clear(std::vector<record *> & array);

int main(int argc, char const *argv[])
{
    FILE * input = fopen("census.csv", "r");
    if (input == NULL) return -1;

    std::vector<record *> v;

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
            else if (tmp->name == "") 
            {
                tmp->name = token;
            }
            else if (tmp->npop == 0) 
            {
                tmp->npop = (long double)atol(token);
            }
            else if (tmp->rpop == 0) 
            {                
                tmp->rpop = (long double)atol(token);
            }
            token = strtok(NULL, delim);
        }
        v.push_back(tmp);
    }

    v.pop_back();
    v.pop_back();

    std::sort(v.begin(), v.end(), compare);

    v.insert(v.begin(), new record({"9998", "Test", 100, 100}));

    v.erase(v.begin());

    size_t idx = find_name(v, "Moldova");
    v[idx]->print();
    v[idx]->edit("Test", "9998", 0, 0);

    for (auto it : v)
    {
        it->print();
    }

    clear(v);

    fclose(input);

    return 0;
}

void clear(std::vector<record *> & array)
{
    for (auto it : array)
    {
        delete it;
    }
}

bool compare(record * lhs, record * rhs)
{
    return lhs->name < rhs->name;
}

size_t find_name(const std::vector<record *> & array, const std::string & n) 
{
    size_t i = 0;
    for (; i < array.size(); i++)
    {
        if (array[i]->name == n) break;
    }
    
    return i;
}

void record::edit(const std::string & n, const std::string & c, double np, double rp) 
{
    name = n;
    code = c;
    npop = np;
    rpop = rp;
}

void record::print() 
{
    std::cout << name << " " << code << " " << npop << " " << rpop << "\n";
}
