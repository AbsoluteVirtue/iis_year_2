#include <iostream>
#include <vector>
#include <Windows.h>

#include "Vehicles.h"

using namespace std;

int GetInput()
{
    int choice;
    cin >> choice;
    return choice;
}

void DisplayMainMenu()
{
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Vehicles Menu\n";
    cout << "2 - Quit\n";
    cout << "Selection: ";
}

void DisplayOptionsMenu()
{
    cout << "Vehicles Menu\n";
    cout << "Please make your selection\n";
    cout << "1 - Create\n";
    cout << "2 - Print all\n";
    cout << "3 - Search by model\n";
    cout << "4 - Edit by index\n";
    cout << "5 - Delete by index\n";
    cout << "6 - Save data to file\n";
    cout << "7 - Read data from file\n";
    cout << "8 - Back\n";
    cout << "Selection: ";
}

void Options(Vehicles veh)
{
    int choice = 0;
    do
    {
        system("cls");
        DisplayOptionsMenu();
        choice = GetInput();
        switch (choice)
        {
        case 1:
            veh.addVehicle();
            break;
        case 2:
            veh.printVehicles();
            cout << "Print complete clearing terminal in 5 seconds..." << endl;
            Sleep(5000);
            break;
        case 3:
            veh.searchByModel();
            break;
        case 4:
            veh.editByIndex();
            break;
        case 5:
            veh.removeElement();
            break;
        case 6:
            veh.saveDataToFile();
            break;
        case 7:
            veh.readDataFromFile();
            break;
        case 8:
            break;
        default:
            break;
        }
    } while (choice != 8);
}

int main() 
{
    Vehicles vehicles;
    int choice = 0;
    
    do
    {
        system("cls");
        DisplayMainMenu();
        choice = GetInput();
        switch (choice) {
        case 1:
            Options(vehicles);
            break;
        case 2:
            cout << "Goodbye!" << endl;
            break;

        default:
            break;
        }
    } while (choice != 2);
    system("PAUSE");
    return EXIT_SUCCESS;
}