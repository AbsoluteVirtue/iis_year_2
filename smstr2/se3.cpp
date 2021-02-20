#include <iostream>

// https://cs50.harvard.edu/college/2019/fall/notes/5/#linked-lists

struct node
{
    int number{0};
    node *next{nullptr};
};

int main(void)
{
    // заголовок списка
    node *list = nullptr;

    // первый узел списка, сохраняется в заголовке
    node *n = new node;
    n->number = 1;
    list = n;

    // добавление второго узла в список через поле next в заголовке
    n = new node;
    n->number = 2;
    list->next = n;

    // добавление третьего узла в список через поле next в предыдущем узле
    // который доступен через заголовок
    n = new node;
    n->number = 3;
    list->next->next = n;

    // Как правило, это делается в цикле
    // Пример вывода данных в списке из цикла
    for (node *tmp = list; tmp != nullptr; tmp = tmp->next)
    {
        std::cout << tmp->number << "\n";
    }

    // Пример цикла while, очищение памяти, занятой узлами списка:
    while (list != nullptr)
    {
        node *tmp = list->next;
        delete list;
        list = tmp;
    }
}
