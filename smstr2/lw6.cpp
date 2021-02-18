#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

struct record
{
    void print();

    std::string code;
    std::string birthplace;
    double night_pop{0};
    double resident_pop{0};
};

static size_t size = 0;
static size_t length = 0;

void split(const std::string & str, const std::string & delim, std::vector<std::string> & parts);
void print(record ** & arr);
void push_back(record ** & arr, const char * c, const std::string & n, double np, double rp);
void pop_back(record ** & arr);
void insert(record ** & arr, const size_t idx, const char * c, const std::string & n, double np, double rp);
void erase(record ** & arr, const size_t idx);
void clear(record ** & arr);

int main(int argc, char const *argv[])
{
    record ** array = nullptr;

    std::ifstream input;
    input.open("census.csv");
    if (!input.is_open()) return 1;

    std::string line;
    while (std::getline(input, line))
    {
        std::vector<std::string> tokens;
        split(line, ",\n\"", tokens);
        if (tokens[0] == "Code") continue;

        try
        {
            push_back(array, tokens[0].c_str(), tokens[1], (double)std::stof(tokens[2]), (double)std::stof(tokens[3]));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    input.close();

    print(array);

    pop_back(array);
    pop_back(array);

    print(array);

    insert(array, 10, "9998", "Test", 1, 1);

    erase(array, 10);

    clear(array);

    return 0;
}

void print(record ** & arr)
{
    for(size_t i = 0; i < length; ++i)
    {
        std::cout   << arr[i]->birthplace << " ("
                    << arr[i]->code << ") "
                    << arr[i]->night_pop << " "
                    << arr[i]->resident_pop<< "\n";
    }
}

void push_back(record ** & arr, const char * c, const std::string & n, double np, double rp)
{
    if (size <= length)
    {
        size = (2 * length) + 1;
        record ** tmp = new record * [size];
        if (length > 0)
            std::copy(arr, arr + length, tmp);

        delete [] arr;
        arr = tmp;
    }

    char * tmp_str = new char[strlen(c) + 1];
    strcpy(tmp_str, c);

    arr[length] = new record({tmp_str, n, rp, np});

    length += 1;
}

void pop_back(record ** & arr) {}
void insert(record ** & arr, const size_t idx, const char * c, const std::string & n, double np, double rp) {}
void erase(record ** & arr, const size_t idx) {}
void clear(record ** & arr)
{
    for (size_t i = 0; i < length; i++)
    {
        delete arr[i];
    }
    delete [] arr;
}

void split(const std::string & str, const std::string & delim, std::vector<std::string> & parts)
{
    size_t start, end = 0;
    while (end < str.size())
    {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != std::string::npos))
        {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == std::string::npos))
        {
            end++;
        }
        if (end - start != 0)
        {
            parts.push_back(std::string(str, start, end - start));
        }
    }
}
