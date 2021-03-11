#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"

struct node
{
    void edit(const char * c, const std::string & n, double np, double rp);
    void push_back(const char * c, const std::string & n, double np, double rp);

    record * data{nullptr};
    node * next{nullptr};
};

void print(node * node);
void split(const std::string & str, const std::string & delim, std::vector<std::string> & parts);

int main(int argc, char const *argv[])
{
    node * head = nullptr;

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
                head = new node;
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

    print(head);

    return 0;
}

void print(node * node)
{
    while(node->data != nullptr && node->next != nullptr)
    {
        std::cout   
            << node->data->birthplace << " "
            << node->data->code << " "
            << node->data->night_pop << " "
            << node->data->resident_pop<< "\n";

        node = node->next;
    }
}

void node::push_back(const char * c, const std::string & n, double np, double rp)
{
    node * cur = this;
    while(cur->next != nullptr) cur = cur->next;

    char * tmp = new char[strlen(c) + 1];
    strcpy(tmp, c);
    node * _node = new node;
    _node->data = new record({tmp, n, rp, np});
    cur->next = _node;
}

void node::edit(const char * c, const std::string & n, double np, double rp)
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

node * merge_sorted(node * left, node * right)
{
    node * placeholder = new node;
    node * last = placeholder;

    while(left && right) 
    {
        if(left->data->birthplace < right->data->birthplace)
        {
            last->next = left;
            last = left;
            left = left->next;
        }
        else 
        {
            last->next = right;
            last = right;
            right = right->next;
        }
    }

    if(left) 
    {
        last->next = left;
    }

    if(right)
    {
        last->next = right;
    }

    return placeholder->next;
}

// http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.31.9981
// Treesort is best, followed by Quicksort and Mergesort. 
// Sediment sort, bubble sort, selection sort perform very badly.

// В зависимости от "железа" иногда быстрее скопировать список в массив и применить быстрый алгоритм сортировки, чем сортировать с помощью медленных алгоритмов.
// https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html

// https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-148-sort-list/

node * merge_sort(node * head)
{
    if (!head || !head->next) return head;
    node* slow = head;
    node* fast = head->next;    
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    node* mid = slow->next;    
    slow->next = nullptr;
    return merge_sorted(merge_sort(head), merge_sort(mid));
}

void sort(node * head)
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        node * current = head;
        while (current)
        {
            node * next = current->next;
            if (next->data->birthplace < current->data->birthplace)
            {
                std::swap(current->data, next->data);
                sorted = false;
            }
            current = current->next;
        }
    }
}
