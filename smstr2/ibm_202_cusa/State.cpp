#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include "State.h"

using namespace std; // так делать не надо

bool memoryAllocated = false, dataInput = false; // надо обходиться без глобальных переменных, так как их видно в других файлах

void addWhileNoMemoryOrData(State *&states, int *statesSize);

void memoryAllocation(State *&states, int *statesSize)
{
	if (memoryAllocated) // вместо глобальной переменной лучше проверять первый аргумент на NULL
	{
		cout << "\n������. ������ ��� ��������!";
	}
	else
	{
		cout << "\n������� ���������� �������: ";
		cin >> *statesSize; // если величина передана как аргумент, зачем здесь ввод из терминала?
		states = new State[*statesSize];
		memoryAllocated = true;
		cout << "\n";
	}
}

#pragma region extra

void inputKeyboard(State *&states, int statesSize)
{
	if (dataInput)
	{
		cout << "\n������. ������ ��� �������!\n\n";
	}
	else if (memoryAllocated)
	{
		cout << "\n���� ��������� ������� � ����������\n";
		cout << "��������� ������� ������ ��� ������� ��������:\n\n";
		for (int i = 0; i < statesSize; i++)
		{
			cout << "���� ������ ��� " << i + 1 << " �����������:\n";
			cout << "������� �������� �����������: ";
			cin >> states[i].name;
			cout << "������� ������� �����������: ";
			cin >> states[i].capital;
			do
			{
				cout << "������� ������� ����������� � ��^2 (����� ������): ";
				cin >> states[i].area;
				if (states[i].area < 1)
				{
					cout << "\n������. ��������� ����!\n\n";
				}
			} while (states[i].area < 1);
			do
			{
				cout << "������� ��������� �����������: ";
				cin >> states[i].population;
				if (states[i].population < 1)
				{
					cout << "\n������. ��������� ����!\n\n";
				}
			} while (states[i].population < 1);
			do
			{
				cout << "������� ���������� ������� ������� � ���� $: ";
				cin >> states[i].vvp;
				if (states[i].vvp <= 0)
				{
					cout << "\n������. ��������� ����!\n\n";
				}
			} while (states[i].vvp <= 0);
			cout << "\n";
		}
		dataInput = true;
	}
	else
	{
		cout << "\n������. ������ �� ���� ��������!\n\n";
	}
}

void searchState(State *states, int statesSize)
{
	if (dataInput)
	{
		vector<int> foundPositions; // неэффективное использование ресурсов: для создания динамического массива использовать временный динамический массив
		short searchChoice;
		// ввод надо отделять от поиска
		do
		{
			cout << "\n������� �� ������ ��������� �� ������ ������� �����:\n";
			cout << "1. �� ��������\n";
			cout << "2. �� �������\n";
			cout << "3. �� �������\n";
			cout << "4. �� ���������\n";
			cout << "5. �� ����������� �������� ��������\n\n";
			cout << "������� ����� ������ ������: ";
			cin >> searchChoice;
			if ((searchChoice < 1) || (searchChoice > 5))
			{
				cout << "������. ��������� ����!\n";
			}
		} while ((searchChoice < 1) || (searchChoice > 5));
		switch (searchChoice)
		{
		case 1:
		{
			string searchRequest;
			cout << "\n������� �������� ����������� ��� ������: ";
			cin >> searchRequest;
			for (int i = 0; i < statesSize; i++)
			{
				if (states[i].name == searchRequest)
				{
					foundPositions.push_back(i);
				}
			}
			break;
		}
		case 2:
		{
			string searchRequest;
			cout << "\n������� ������� ����������� ��� ������: ";
			cin >> searchRequest;
			for (int i = 0; i < statesSize; i++)
			{
				if (states[i].capital == searchRequest)
				{
					foundPositions.push_back(i);
				}
			}
			break;
		}
		case 3:
		{
			int searchRequest;
			cout << "\n������� ������� ����������� � ��^2 ��� ������: ";
			cin >> searchRequest;
			for (int i = 0; i < statesSize; i++)
			{
				if (states[i].area == searchRequest)
				{
					foundPositions.push_back(i);
				}
			}
			break;
		}
		case 4:
		{
			int searchRequest;
			cout << "\n������� ��������� ����������� ��� ������: ";
			cin >> searchRequest;
			for (int i = 0; i < statesSize; i++)
			{
				if (states[i].population == searchRequest)
				{
					foundPositions.push_back(i);
				}
			}
			break;
		}
		case 5:
		{
			float searchRequest;
			cout << "\n������� ��� ����������� � ���� $ ��� ������: ";
			cin >> searchRequest;
			for (int i = 0; i < statesSize; i++)
			{
				if (states[i].vvp == searchRequest)
				{
					foundPositions.push_back(i);
				}
			}
			break;
		}
		}
		if (foundPositions.empty())
		{
			cout << "\n����������� � ����� ���������� �� �������!\n\n";
		}
		else
		{
			// кошмар
			for (int i : foundPositions) 
			{
				cout << "\n��������: " << states[i].name << "\n";
				cout << "�������: " << states[i].capital << "\n";
				cout << "�������: " << states[i].area << "\n";
				cout << "���������: " << states[i].population << "\n";
				cout << "���������� ������� �������: " << states[i].vvp << "\n";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "\n������. ��� ������ � ������������!\n\n";
	}
}

void sort(State *&states, int statesSize)
{
	if (dataInput)
	{
		short sortChoice;
		do
		{
			cout << "\n������� �� ������ ��������� �� ������ ������� ����������:\n";
			cout << "1. �� ��������\n";
			cout << "2. �� �������\n";
			cout << "3. �� �������\n";
			cout << "4. �� ���������\n";
			cout << "5. �� ����������� �������� ��������\n\n";
			cout << "������� ����� ������ ������: ";
			cin >> sortChoice;
			if ((sortChoice < 1) || (sortChoice > 5))
			{
				cout << "������. ��������� ����!\n";
			}
		} while ((sortChoice < 1) || (sortChoice > 5));
		short sortType;
		do
		{
			cout << "\n�������� ��� ����������:\n";
			cout << "1. �� �����������\n";
			cout << "2. �� ��������\n\n";
			cout << "������� ����� ������ ������: ";
			cin >> sortType;
			if ((sortType < 1) || (sortType > 2))
			{
				cout << "������. ��������� ����!\n";
			}
		} while ((sortType < 1) || (sortType > 2));

		State tmp;
		switch (sortChoice)
		{
		case 1:
			for (int i = 0; i < statesSize - 1; i++)
			{
				for (int j = 0; j < statesSize - i - 1; j++)
				{
					if (sortType == 1)
					{
						if (states[j].name > states[j + 1].name)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
					else
					{
						if (states[j].name < states[j + 1].name)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
				}
			}
			break;
		case 2:
			for (int i = 0; i < statesSize - 1; i++)
			{
				for (int j = 0; j < statesSize - i - 1; j++)
				{
					if (sortType == 1)
					{
						if (states[j].capital > states[j + 1].capital)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
					else
					{
						if (states[j].capital < states[j + 1].capital)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
				}
			}
			break;
		case 3:
			for (int i = 0; i < statesSize - 1; i++)
			{
				for (int j = 0; j < statesSize - i - 1; j++)
				{
					if (sortType == 1)
					{
						if (states[j].area > states[j + 1].area)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
					else
					{
						if (states[j].area < states[j + 1].area)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
				}
			}
			break;
		case 4:
			for (int i = 0; i < statesSize - 1; i++)
			{
				for (int j = 0; j < statesSize - i - 1; j++)
				{
					if (sortType == 1)
					{
						if (states[j].population > states[j + 1].population)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
					else
					{
						if (states[j].population < states[j + 1].population)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
				}
			}
			break;
		case 5:
			for (int i = 0; i < statesSize - 1; i++)
			{
				for (int j = 0; j < statesSize - i - 1; j++)
				{
					if (sortType == 1)
					{
						if (states[j].vvp > states[j + 1].vvp)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
					else
					{
						if (states[j].vvp < states[j + 1].vvp)
						{
							tmp = states[j];
							states[j] = states[j + 1];
							states[j + 1] = tmp;
						}
					}
				}
			}
			break;
		}
		cout << "\n";
	}
	else
	{
		cout << "\n������. ��� ������ � ������������!\n\n";
	}
}

#pragma endregion

void editState(State *&states, int statesSize)
{
	if (dataInput) // если здесь не выполняется условие, как его выставить вне данной функции?
	{
		string editName;
		short editChoice, stayOnEdit;
		int editPosition = -1;
		do
		{
			do
			{
				cout << "\n������� �������� �����������, ������� ������ ���������������: ";
				cin >> editName;
				editPosition = -1;
				for (int i = 0; i < statesSize; i++)
				{
					if (states[i].name == editName)
					{
						editPosition = i;
					}
				}
				if (editPosition == -1)
				{
					cout << "������. ����������� � ����� ��������� �� ������, ��������� ����\n";
				}
			} while (editPosition == -1); // бесконечный цикл - это перебор
			do
			{
				do
				{
					cout << "\n��������� ��������������:\n";
					cout << "1. ��������\n";
					cout << "2. �������\n";
					cout << "3. �������\n";
					cout << "4. ���������\n";
					cout << "5. ���������� ������� ������� (���)\n\n";
					cout << "������� ����� ���������, ������� ������� ���������������: ";
					cin >> editChoice;
					if ((editChoice < 1) || (editChoice > 5))
					{
						cout << "������. ��������� ����!\n";
					}
				} while ((editChoice < 1) || (editChoice > 5));

				switch (editChoice)
				{
				case 1:
					cout << "\n������� ��������: " << states[editPosition].name << "\n";
					cout << "������� ����� ��������: ";
					cin >> states[editPosition].name; // редактирование и ввод надо разделять
					break;
				case 2:
					cout << "\n������� �������: " << states[editPosition].capital << "\n";
					cout << "������� ����� �������: ";
					cin >> states[editPosition].capital;
					break;
				case 3:
					cout << "\n������� �������� ������� (����� ������): " << states[editPosition].area;
					cout << "\n";
					cout << "������� ����� �������� �������: ";
					cin >> states[editPosition].area;
					break;
				case 4:
					cout << "\n������� �������� ���������: " << states[editPosition].population;
					cout << "\n";
					cout << "������� ����� �������� ���������: ";
					cin >> states[editPosition].population;
					break;
				case 5:
					cout << "\n������� �������� ���: " << states[editPosition].vvp;
					cout << "\n";
					cout << "������� ����� �������� ��� � ���� $ : ";
					cin >> states[editPosition].vvp;
					break;
				}
				do
				{
					cout << "\n���������� ������������� ������ ����� �����������?\n";
					cout << "1. ��\n";
					cout << "2. ���\n";
					cout << "������� ����� ������ ������: ";
					cin >> stayOnEdit;
					if ((stayOnEdit < 1) || (stayOnEdit > 2))
					{
						cout << "������. ��������� ����!\n";
					}
				} while ((stayOnEdit < 1) || (stayOnEdit > 2));
			} while (stayOnEdit == 1);
			do
			{
				cout << "\n������ ��������������� ������ ��� ������� �����������?\n";
				cout << "1. ��\n";
				cout << "2. ���\n";
				cout << "������� ����� ������ ������: ";
				cin >> stayOnEdit;
				if ((stayOnEdit < 1) || (stayOnEdit > 2))
				{
					cout << "������. ��������� ����!\n";
				}
			} while ((stayOnEdit < 1) || (stayOnEdit > 2));
		} while (stayOnEdit == 1);
		cout << "\n";
	}
	else
	{
		cout << "\n������. ��� ������ � ������������!\n\n";
	}
}

void addNewStateInEnd(State *&states, int *statesSize)
{
	State *statesTemp;
	if (dataInput)
	{
		statesTemp = new State[++*statesSize];
		for (int i = 0; i < *statesSize - 1; i++)
		{
			statesTemp[i] = states[i];
		}
		delete[] states;

		// если теперь при вводе что-то случится, будет и потеря данных, и утечка памяти
		cout << "\n���� ������ ��� ������ �����������:\n";
		cout << "������� �������� �����������: ";
		cin >> statesTemp[*statesSize - 1].name;
		cout << "������� ������� �����������: ";
		cin >> statesTemp[*statesSize - 1].capital;
		do
		{
			cout << "������� ������� ����������� � ��^2 (����� ������): ";
			cin >> statesTemp[*statesSize - 1].area;
			if (statesTemp[*statesSize - 1].area < 1)
			{
				cout << "\n������. ��������� ����!\n\n";
			}
		} while (statesTemp[*statesSize - 1].area < 1);
		do
		{
			cout << "������� ��������� �����������: ";
			cin >> statesTemp[*statesSize - 1].population;
			if (statesTemp[*statesSize - 1].population < 1)
			{
				cout << "\n������. ��������� ����!\n\n";
			}
		} while (statesTemp[*statesSize - 1].population < 1);
		do
		{
			cout << "������� ���������� ������� ������� � ���� $: ";
			cin >> statesTemp[*statesSize - 1].vvp;
			if (statesTemp[*statesSize - 1].vvp <= 0)
			{
				cout << "\n������. ��������� ����!\n\n";
			}
		} while (statesTemp[*statesSize - 1].vvp <= 0);
		states = statesTemp;
		cout << "\n";
	}
	else
	{
		addWhileNoMemoryOrData(states, statesSize);
	}
}

void deleteState(State *&states, int *statesSize)
{
	if (dataInput)
	{
		State *statesTemp;
		if (*statesSize - 1 == 0)
		{
			delete[] states;
			statesSize = 0;
			memoryAllocated = false;
			dataInput = false;
		}
		else
		{
			string deleteName;
			int deletePosition = -1;
			do
			{
				cout << "\n������� �������� �����������, ������� ������ �� �������: ";
				cin >> deleteName;
				for (int i = 0; i < *statesSize; i++)
				{
					if (states[i].name == deleteName)
					{
						deletePosition = i;
					}
				}
				if (deletePosition == -1)
				{
					cout << "\n������. ����������� � ����� ��������� �� ���� �������, ��������� ����\n";
				}
			} while (deletePosition == -1);

			statesTemp = new State[--*statesSize];
			int j = 0;
			for (int i = 0; i < *statesSize + 1; i++)
			{
				if (i != deletePosition)
				{
					statesTemp[j++] = states[i];
				}
			}
			delete[] states;
			states = statesTemp;
			cout << "\n����������� " << deleteName << " ���� ������� �������!\n\n";
		}
	}
	else
	{
		cout << "\n������. ��� ������ � ������������!\n\n";
	}
}

void addNewState(State *&states, int *statesSize)
{
	if (dataInput)
	{
		int insertPosition;
		State *statesTemp;
		short choice;
		do
		{
			cout << "\n���������� ������ �����������:\n";
			cout << "1. ����� ����������� ������������\n";
			cout << "2. ����� ������������ �����������\n";
			cout << "3. �� ���������� �������\n";
			cout << "4. � ������\n";
			cout << "5. � �����\n";
			cout << "������� ����� ������ ������: ";
			cin >> choice;
			if ((choice < 1) || (choice > 5))
			{
				cout << "\n������. ��������� ����!\n";
			}
		} while ((choice < 1) || (choice > 5));
		insertPosition = -1;
		switch (choice)
		{
		case 1:
		{
			string searchName;
			do
			{
				cout << "\n������� �������� �����������, ����� ������� ������";
				cout << " �������� ����� �������: ";
				cin >> searchName;
				for (int i = 0; i < *statesSize; i++)
				{
					if (states[i].name == searchName)
					{
						insertPosition = i;
					}
				}
				if (insertPosition == -1)
				{
					cout << "\n������. ����������� � ����� ��������� ";
					cout << "�� �������, ��������� ����\n";
				}
			} while (insertPosition == -1);
			break;
		}
		case 2:
		{
			string searchName;
			do
			{
				cout << "\n������� �������� �����������, ����� �������� ������";
				cout << " �������� ����� �������: ";
				cin >> searchName;
				for (int i = 0; i < *statesSize; i++)
				{
					if (states[i].name == searchName)
					{
						insertPosition = i + 1;
					}
				}
				if (insertPosition == -1)
				{
					cout << "\n������. ����������� � ����� ��������� ";
					cout << "�� �������, ��������� ����\n";
				}
			} while (insertPosition == -1);
			break;
		}
		case 3:
			do
			{
				cout << "\n������� �������, ���� ������ �������� ����� �������";
				cout << " (���������� � 0): ";
				cin >> insertPosition;
				if ((insertPosition < 0) || (insertPosition >= *statesSize))
				{
					cout << "\n������. ����� �� ������� �������, ��������� ����";
				}
			} while ((insertPosition < 0) || (insertPosition >= *statesSize));
			break;
		case 4:
			insertPosition = 0;
			break;
		case 5:
			insertPosition = *statesSize;
			break;
		}
		if (insertPosition == *statesSize)
		{
			addNewStateInEnd(states, statesSize);
		}
		else
		{
			statesTemp = new State[++*statesSize];
			int j = 0;
			for (int i = 0; i < *statesSize - 1; i++)
			{
				if (i == insertPosition)
				{
					cout << "\n���� ������ ��� ������ �����������:\n";
					cout << "������� �������� �����������: ";
					cin >> statesTemp[j].name;
					cout << "������� ������� �����������: ";
					cin >> statesTemp[j].capital;
					do
					{
						cout << "������� ������� ����������� � ��^2 (����� ������): ";
						cin >> statesTemp[j].area;
						if (statesTemp[j].area < 1)
						{
							cout << "\n������. ��������� ����!\n\n";
						}
					} while (statesTemp[j].area < 1);
					do
					{
						cout << "������� ��������� �����������: ";
						cin >> statesTemp[j].population;
						if (statesTemp[j].population < 1)
						{
							cout << "\n������. ��������� ����!\n\n";
						}
					} while (statesTemp[j].population < 1);
					do
					{
						cout << "������� ���������� ������� ������� � ���� $: ";
						cin >> statesTemp[j].vvp;
						if (statesTemp[j].vvp <= 0)
						{
							cout << "\n������. ��������� ����!\n\n";
						}
					} while (statesTemp[j].vvp <= 0);
					j++;
					statesTemp[j++] = states[i];
					cout << "\n";
				}
				else
				{
					statesTemp[j++] = states[i];
				}
			}
			delete[] states;
			states = statesTemp;
			dataInput = true;
		}
	}
	else
	{
		addWhileNoMemoryOrData(states, statesSize);
	}
}

void addWhileNoMemoryOrData(State *&states, int *statesSize)
{
	if (memoryAllocated)
	{
		delete[] states;
	}
	states = new State[1];
	*statesSize = 1;
	memoryAllocated = true;
	cout << "\n\n���� ������ ��� ������ �����������:\n";
	cout << "������� �������� �����������: ";
	cin >> states[0].name;
	cout << "������� ������� �����������: ";
	cin >> states[0].capital;
	do
	{
		cout << "������� ������� ����������� � ��^2 (����� ������): ";
		cin >> states[0].area;
		if (states[0].area < 1)
		{
			cout << "\n������. ��������� ����!\n\n";
		}
	} while (states[0].area < 1);
	do
	{
		cout << "������� ��������� �����������: ";
		cin >> states[0].population;
		if (states[0].population < 1)
		{
			cout << "\n������. ��������� ����!\n\n";
		}
	} while (states[0].population < 1);
	do
	{
		cout << "������� ���������� ������� ������� � ���� $: ";
		cin >> states[0].vvp;
		if (states[0].vvp <= 0)
		{
			cout << "\n������. ��������� ����!\n\n";
		}
	} while (states[0].vvp <= 0);
	dataInput = true;
}

void outputFile(State *states, int statesSize)
{
	if (dataInput)
	{
		string file;
		cout << "\n������� �������� � ���������� ����� ��� ������ (��� ��������): ";
		cin >> file;
		ofstream fout(file);

		fout << "|�����������������������������������������������";
		fout << "���������������������������������������������|\n";
		fout << "|" << setw(60) << right << "����� ���������� ����������: ";
		fout << setw(3) << left << statesSize;
		fout << "                             |\n";
		fout << "|�����������������������������������������������";
		fout << "���������������������������������������������|\n";
		fout << "| ��������                 | �������          |";
		fout << " ������� (��^2)  | ���������  | ��� (���� $)  |\n";
		fout << "|�����������������������������������������������";
		fout << "���������������������������������������������|\n";
		for (int i = 0; i < statesSize; i++)
		{
			fout << "| " << setw(25) << left << states[i].name;
			fout << "| " << setw(17) << left << states[i].capital;
			fout << "| " << setw(16) << left << states[i].area;
			fout << "| " << setw(11) << left << states[i].population;
			fout << "| " << setw(14) << left << states[i].vvp << "|\n";
			fout << "|�����������������������������������������������";
			fout << "���������������������������������������������|\n";
		}
		fout.close();
		cout << "������ ������� �������� � ���� " << file << "\n\n";
	}
	else
	{
		cout << "\n������. ��� ������ � ������������\n\n!";
	}
}

void inputFile(State *&states, int *statesSize)
{
	string file;
	cout << "\n������� �������� � ���������� ����� ��� ������ (��� ��������): ";
	cin >> file;
	ifstream fin(file);
	if (!fin.is_open())
	{
		cout << "\n���� �� ����� ���� ������!\n\n";
	}
	else
	{
		if (memoryAllocated)
		{
			memoryClear(states, statesSize);
		}
		fin >> *statesSize;
		states = new State[*statesSize];
		for (int i = 0; i < *statesSize; i++)
		{
			fin >> states[i].name;
			fin >> states[i].capital;
			fin >> states[i].area;
			fin >> states[i].population;
			fin >> states[i].vvp;
		}
		memoryAllocated = true;
		dataInput = true;
		fin.close();
		cout << "������ ��������� �������!\n";
	}
	cout << "\n";
}

void outputConsole(State *states, int statesSize)
{
	if (dataInput)
	{
		cout << "\n|�����������������������������������������������";
		cout << "���������������������������������������������|\n";
		cout << "|" << setw(60) << right << "����� ���������� ����������: ";
		cout << setw(3) << left << statesSize;
		cout << "                             |\n";
		cout << "|�����������������������������������������������";
		cout << "���������������������������������������������|\n";
		cout << "| ��������                 | �������          |";
		cout << " ������� (��^2)  | ���������  | ��� (���� $)  |\n";
		cout << "|�����������������������������������������������";
		cout << "���������������������������������������������|\n";
		for (int i = 0; i < statesSize; i++)
		{
			cout << "| " << setw(25) << left << states[i].name;
			cout << "| " << setw(17) << left << states[i].capital;
			cout << "| " << setw(16) << left << states[i].area;
			cout << "| " << setw(11) << left << states[i].population;
			cout << "| " << setw(14) << left << states[i].vvp << "|\n";
			cout << "|�����������������������������������������������";
			cout << "���������������������������������������������|\n";
		}
		cout << "\n";
	}
	else
	{
		cout << "\n������. ��� ������ � ������������!\n\n";
	}
}

void memoryClear(State *&states, int *statesSize)
{
	if (memoryAllocated)
	{
		delete[] states;
		*statesSize = 0;
		states = NULL;
		memoryAllocated = false;
		dataInput = false;
	}
	cout << "\n������ ��������!\n\n";
}
