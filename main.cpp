#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <new>
#include <exception>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>

struct T
{
    std::string a;
    std::string b;
    std::string c;
    std::string d;
    std::string e;
};

struct node
{
    T data;
    node *next{nullptr};
};

struct node_p
{
    T * data{nullptr};
    node *next{nullptr};

    ~node_p() {delete data;}
};

void print(node *head)
{
    for (node *tmp = head; tmp; tmp = tmp->next)
    {
        std::cout << tmp->data.a << " "
                  << tmp->data.b << " "
                  << tmp->data.c << " "
                  << tmp->data.d << " "
                  << tmp->data.e << "\n";
    }
}

node *find(node *head, const std::string search)
{
    for (node *tmp = head; tmp; tmp = tmp->next)
    {
        if (search == tmp->data.a)
            return tmp;
    }
    return nullptr;
}

void edit(node *head,
          const std::string search,
          std::string a = "",
          std::string b = "",
          std::string c = "",
          std::string d = "",
          std::string e = "")
{
    for (node *tmp = head; tmp; tmp = tmp->next)
    {
        if (search == tmp->data.a)
        {
            if (a != "")
                tmp->data.a = a;
            if (b != "")
                tmp->data.b = b;
            if (c != "")
                tmp->data.c = c;
            if (d != "")
                tmp->data.d = d;
            if (e != "")
                tmp->data.e = e;
            break;
        }
    }
}

void clear(node *head)
{
    while (head)
    {
        node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void push_back(node *head, const T payload)
{
    node *tmp = head;
    for (; tmp->next; tmp = tmp->next)
        ;

    node *_new = new node;
    _new->data = payload;

    tmp->next = _new;
}

int get_random_range(int lower, int upper)
{
    return lower + (rand() % (upper - lower));
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    const char * list [9] = {
        "Schitco, I.",
        "Bodnari, D.",
        "Miron, T.-N.",
        "Malis, V.",
        "Ignatiev, S.",
        "Artiomenco, A.",
        "Rizov, E.",
        "Buliga, M.",
        "Savostin, X.",
    };

    std::vector<const char *> algs = {
        "Алгоритм Фода-Фалкерсона",
        "Алгоритм максимального паросочетания",
        "Алгоритм Дейкстры",
        "Алгоритм Флойда-Уоршалла",
        "Алгоритм Беллмана-Форда",
        "Алгоритм топологической сортировки",
        "Поиск в глубину и классификация ребер",
        "Поиск в ширину и классификация ребер",
        "Пирамидальная сортировка на основе очереди с приоритетами",
        "Алгоритм Прима и остовное дерево",
        "Алгоритм Краскала и остовное дерево",
        "Поиск подстроки в строке с использованием конечного автомата",
    };

    const int N = 20;
    char padding[N + 1] = {0};

    memset(padding, '.', N);

    for (size_t i = 0; i < 9; i++)
    {
        int idx = get_random_range(0, (int)algs.size() - 1);
        const char * title = algs[idx];
        printf("%s %.*s %s\n", list[i], N - (int)strlen(list[i]), padding , title);
        algs.erase(algs.begin() + idx);
    }

    return 0;
}
