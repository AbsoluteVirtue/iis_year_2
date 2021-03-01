#include <iostream>         // ���������� �����/������
#include <Windows.h>        // ���������� ������� Windows
#include "State.h"

using namespace std;

int main()
{
    State* states = NULL;   // ��������� �� ���������� ������ ��������
    int statesSize = 0;     // ����������� �������
    SetConsoleCP(1251); SetConsoleOutputCP(1251);   // ��� ������ ������� �������� � �������
    short choice;           // ��� ������ ������������
    do
    {
        do
        {
            cout << "����:\n";  // ���� ������
            cout << "1.  ������������ ��������� ������ ��� ������� ��������.\n";
            cout << "2.  ���� ��������� ������� � ����������.\n";
            cout << "3.  ����� �������� �������.\n";
            cout << "4.  ���������� �������.\n";
            cout << "5.  �������������� �������� �������.\n";
            cout << "6.  ���������� ������ �������� � �����.\n";
            cout << "7.  �������� ���������� �������� �� �������.\n";
            cout << "8.  ������� ������ ��������.\n";
            cout << "9.  ������ ��������� ������� � ����.\n";
            cout << "10. ���������� ��������� ������� �� �����.\n";
            cout << "11. ����� ��������� ������� �� �����.\n";
            cout << "12. ������������ ������, ���������� ��� �������.\n";
            cout << "13. ��������� ������ ���������.\n\n";
            cout << "������� ����� ������ ������: ";
            cin >> choice;

            if ((choice < 1) || (choice > 13))
            {
                cout << "\n������. ��������� ���� ����!\n\n";
            }   // ���� �� ������ ���������� ������
        } while ((choice < 1) || (choice > 13));

        switch (choice)     // � ����������� �� ������ ������������
        {
        case 1:
            // ��������� ������
            //states = memoryAllocation(states, &statesSize);
            memoryAllocation(states, &statesSize);
            break;
        case 2:
            // ���� ������� ��������
            inputKeyboard(states, statesSize);
            break;
        case 3:
            // ����� ��������� � �������
            searchState(states, statesSize);
            break;
        case 4:
            // ���������� ������� ��������
            sort(states, statesSize);
            break;
        case 5:
            // �������������� ��������� �� �������
            editState(states, statesSize);
            break;
        case 6:
            // ���������� ����� ��������� � ����� �������
            addNewStateInEnd(states, &statesSize);
            break;
        case 7:
            // �������� ��������� �� �������
            deleteState(states, &statesSize);
            break;
        case 8:
            // ���������� ����� ���������
            addNewState(states, &statesSize);
            break;
        case 9:
            // ����� ������� �������� � ����
            outputFile(states, statesSize);
            break;
        case 10:
            // ���� ������� �������� ����� ����
            inputFile(states, &statesSize);
            break;
        case 11:
            // ����� ������� �������� � �������
            outputConsole(states, statesSize);
            break;
        case 12:
            // ������������ ������
            memoryClear(states, &statesSize);
            break;
        case 13:
            // �������� ������ ����� ����������� ���������
            memoryClear(states, &statesSize);
            cout << "\n�";
            Sleep(250);
            cout << "�";
            Sleep(250);
            cout << "�";
            Sleep(250);
            cout << "�";
            Sleep(250);
            cout << "!\n\n";
            Sleep(250);
            break;
        }
    } while (choice != 13); // ���� ������������ �� ������� ����� �� ���������

    system("pause");    // �� ��������� ���������� ����
    return 0;           // ��� 0 - �������� ���������� ���������
}
