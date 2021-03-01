#pragma once

#include <string>

struct State
{
    std::string name;
    std::string capital;
    int area;
    int population;
    float vvp;
};

// нет массива указателей

void memoryAllocation(State*& states, int* statesSize);
void inputKeyboard(State*& states, int statesSize);
void searchState(State* states, int statesSize);
void sort(State*& states, int statesSize);
void editState(State*& states, int statesSize);
void addNewStateInEnd(State*& states, int* statesSize);
void deleteState(State*& states, int* statesSize);
void addNewState(State*& states, int* statesSize);
void outputFile(State* states, int statesSize);
void inputFile(State*& states, int* statesSize);
void outputConsole(State* states, int statesSize);
void memoryClear(State*& states, int* statesSize);
