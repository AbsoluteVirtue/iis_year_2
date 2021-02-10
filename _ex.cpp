#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"

struct List
{
    void edit(const char * c, const std::string & n, double np, double rp);
    void push_back(const char * c, const std::string & n, double np, double rp);
    void print();

    record * data{nullptr};
    List * next{nullptr};
};

void split(const std::string & str, const std::string & delim, std::vector<std::string> & parts);

int main(int argc, char const *argv[])
{
    List * head = nullptr;

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
            if (head == nullptr)
            {
                head = new List;
                head->edit(tokens[0].c_str(), tokens[1], (double)std::stof(tokens[2]), (double)std::stof(tokens[3]));
            }
            else
            {
                head->push_back(tokens[0].c_str(), tokens[1], (double)std::stof(tokens[2]), (double)std::stof(tokens[3]));
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    input.close();

    while(head->data != nullptr && head->next != nullptr)
    {
        std::cout   << head->data->birthplace << " "
                    << head->data->code << " "
                    << head->data->night_pop << " "
                    << head->data->resident_pop<< "\n";
        head = head->next;
    }

    return 0;
}

void List::push_back(const char * c, const std::string & n, double np, double rp)
{
    List * cur = this;
    while(cur->next != nullptr) cur = cur->next;

    char * tmp = new char[strlen(c) + 1];
    strcpy(tmp, c);
    List * node = new List;
    node->data = new record({tmp, n, rp, np});
    cur->next = node;
}

void List::edit(const char * c, const std::string & n, double np, double rp)
{
    if (this->data == nullptr)
    {
        char * tmp = new char[strlen(c) + 1];
        strcpy(tmp, c);
        this->data = new record({tmp, n, rp, np});
    }
    else
    {
        this->data->birthplace = n;
        this->data->night_pop = np;
        this->data->resident_pop = rp;
        if (this->data->code != nullptr)
        {
            delete [] this->data->code;
        }
        this->data->code = new char[strlen(c) + 1];
        strcpy(this->data->code, c);
    }
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
