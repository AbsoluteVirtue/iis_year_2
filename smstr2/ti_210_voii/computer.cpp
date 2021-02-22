#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "computer.h"

void vector::resize(bool extra_mem, int free_slots)
{
    int real_data = this->position - this->first;
    computer *tmp = (computer *)calloc(real_data, sizeof(computer));
    int buf_count = 0;
    for (buf_count = 0; buf_count < real_data; buf_count++)
    {
        tmp[buf_count] = *(this->first++);
    }
    int memory = 0;
    if (extra_mem)
    {
        this->size += free_slots;
        memory = this->size + 1;
    }
    else
    {
        memory = real_data;
    }
    this->first = (computer *)calloc(memory, sizeof(computer));
    this->last = this->first + memory - 1;

    this->size = memory;

    int array_count = 0;
    for (this->position = this->first; this->position < this->first + buf_count; this->position++)
    {
        *this->position = tmp[array_count];
        array_count++;
    }
    this->position = this->first + buf_count;
    free(tmp);
}

// можно было сделать конструктор
void vector::create()
{
    if (this->first == NULL)
    {
        this->first = (computer *)calloc(2, sizeof(computer));
        this->position = this->first;
        this->size++;
        this->last = this->first + this->size;
    }
    else if (this->position == this->last)
    {
        this->resize(1, 5);
    }
}

void vector::open(FILE *input)
{
    char buf[100] = {};
    while (fgets(buf, 100, input))
    {
        const char *delim = " ,\"\n";
        char *token = strtok(buf, delim);
        this->create(); // в момент вызова функции вектор уже должен быть создан
        while (token)
        {
            if (this->position->model == nullptr)
            {
                this->position->model = (char *)malloc(sizeof(token) + 1);
                strcpy(this->position->model, token);
            }
            else if (this->position->processor == nullptr)
            {
                this->position->processor = (char *)malloc(sizeof(token) + 1);
                strcpy(this->position->processor, token);
            }
            else if (this->position->memory == 0)
            {
                this->position->memory = (double)atol(token);
            }
            else if (this->position->speed == 0)
            {
                this->position->speed = (double)atol(token);
            }
            else if (this->position->price == 0)
            {
                this->position->price = (double)atol(token);
            }
            token = strtok(NULL, delim);
        }
        this->position++;
    }
    this->resize(0, 0);
    fclose(input);
}

void vector::find_model(char *str)
{
    for (this->position = this->first; this->position <= this->last; this->position++)
    {
        if (!strcmp(str, this->position->model))
            this->print();
    }
}

void vector::edit(int number, computer element)
{
    this->position = this->first + number;
    if (this->position->model == NULL)
    {
        // strlen лучше
        this->position->model = (char *)malloc(sizeof(element.model) + 1);
        this->position->processor = (char *)malloc(sizeof(element.processor) + 1);
    }
    *(this->position) = element;
}

void vector::push_back(computer element)
{
    this->position = this->first + this->size;
    this->resize(1, 0);
    this->edit(this->size - 1, element);
}

void vector::print()
{
    printf("%s %s %d %d %d\n",
           this->position->model,
           this->position->processor,
           this->position->memory,
           this->position->speed,
           this->position->price);
}

void vector::insert(int number, computer element)
{
    this->position = this->first + this->size;
    this->resize(1, 0);

    for (this->position = this->last; this->position > this->first + number; this->position--)
    {
        *(this->position) = *(this->position - 1);
    }
    this->position = this->first + number;
    edit(number, element);
}

void vector::del(int number)
{
    for (this->position = this->first + number - 1; this->position < this->last; this->position++)
    {
        *(this->position) = *(this->position + 1);
    };
    this->size--;
    resize(0, 0);
}

void vector::sort_price()
{
    int real_data = this->last - this->first;
    computer *arr = (computer *)calloc(real_data, sizeof(computer)); // ???
    int buf_count = 0;
    for (buf_count = 0; buf_count < real_data; buf_count++)
    {
        arr[buf_count] = *(this->first++);
    }
    computer tmp;
    for (int i = real_data - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {

            if (arr[j].price > arr[j + 1].price)
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    resize(1, 0);
    int count = 0;
    for (this->position = this->first; this->position < this->first + buf_count; this->position++)
    {
        *this->position = arr[count++];
    }
    this->position = this->first;
}

void vector::output(FILE *output)
{
    fprintf(output, "%s %s %d %d %d\n",
            this->position->model,
            this->position->processor,
            this->position->memory,
            this->position->speed,
            this->position->price);
    fclose(output);
}

void vector::clean_up()
{
    // где освобождение памяти, связанное со строками?
    free(this->first);
}
