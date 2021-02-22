#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std; // надо обходиться без этого

class Vehicles
{
	struct Vehicle // лучше ее отдельно держать
	{
		string model;
		string country;
		int hourse_power;
		double price;
		tm created_at;
	};

private:
	vector<Vehicle> vehicles; // должны быть указатели; пропадает смысл вектора, если его включать в другой класс

	// определения желательно компилировать в отдельном файле
	Vehicle prepareVehicleOptions()
	{
		string model;
		string country;
		int hourse_power;
		double price;
		char *time_raw;

		cout << "Enter vehicle model: ";
		getline(cin >> ws, model);
		cout << endl;

		cout << "Enter vehicle country: ";
		getline(cin >> ws, country);
		cout << endl;

		cout << "Enter vehicle hourse power: ";
		cin >> hourse_power;
		cout << endl;

		cout << "Enter vehicle price: ";
		cin >> price;
		cout << endl;

		string input;
		int year, month, day;
		cout << "Enter vehicle created_at (2005:03:09 or 2005/04/02): ";
		cin >> input; // input can be 2005:03:09 or 2005/04/02 or whatever
		stringstream ss(input);
		char ch;
		ss >> year >> ch >> month >> ch >> day;

		tm tm1;

		tm1.tm_year = year;
		tm1.tm_mon = month;
		tm1.tm_mday = day;

		Vehicle veh;
		veh.country = country;
		veh.hourse_power = hourse_power;
		veh.model = model;
		veh.price = price;
		veh.created_at = tm1;

		return veh;
	}

	void printVeh(Vehicle current_veh, int i)
	{
		cout << endl;
		cout << "Vehicle #" << i << " :" << endl;
		cout << "  model: " << current_veh.model << endl;
		cout << "  price: " << current_veh.price << endl;
		cout << "  hourse_power: " << current_veh.hourse_power << endl;
		cout << "  country: " << current_veh.country << endl;
		cout << "  created_at: " << prepareData(current_veh.created_at) << endl;
		cout << endl;
	}

	int getVehicleIndex()
	{
		int index;
		cout << "Enter index of vehicle you want to act: ";
		cin >> index;
		cout << endl;

		if (index > vehicles.size() || index < 0)
		{
			return -1;
		}
		else
		{
			return index;
		}
	}

	string prepareData(tm date)
	{
		return to_string(date.tm_year) + '-' + to_string(date.tm_mon) + '-' + to_string(date.tm_mday);
	}

	vector<string> split(string str, string token)
	{
		vector<string> result;
		while (str.size())
		{
			int index = str.find(token);
			if (index != string::npos)
			{
				result.push_back(str.substr(0, index));
				str = str.substr(index + token.size());
				if (str.size() == 0)
					result.push_back(str);
			}
			else
			{
				result.push_back(str);
				str = "";
			}
		}
		return result;
	}

public:
	void addVehicle()
	{
		Vehicle veh = prepareVehicleOptions();
		vehicles.push_back(veh);
	}

	void printVehicles()
	{
		for (int i = 0; i < vehicles.size(); i++)
		{
			Vehicle current_veh = vehicles.at(i);
			cout << endl;
			cout << "Vehicle #" << i << " :" << endl;
			cout << "  model: " << current_veh.model << endl;
			cout << "  price: " << current_veh.price << endl;
			cout << "  hourse_power: " << current_veh.hourse_power << endl;
			cout << "  country: " << current_veh.country << endl;
			cout << "  created_at: " << prepareData(current_veh.created_at) << endl;
			cout << endl;
		}
	}

	void searchByModel()
	{
		// запрос надо передавать в функцию
		string model_name;
		cout << "Enter vehicle model name: ";
		getline(cin >> ws, model_name);

		Vehicle finded_veh;
		int index = -1;

		for (int i = 0; i < vehicles.size(); i++)
		{
			Vehicle cur_veh = vehicles.at(i);
			if (cur_veh.model == model_name)
			{
				finded_veh = cur_veh;
				index = i;
				break;
			}
		}

		if (index == -1)
		{
			cout << "Vehicle is not found";
			Sleep(5000); // ???
		}
		else
		{
			printVeh(finded_veh, index);
			Sleep(5000);
		}
	}

	void removeElement()
	{
		int index = getVehicleIndex();
		if (index == -1)
		{
			cout << "Invalid index." << endl;
		}
		else
		{
			vehicles.erase(vehicles.begin() + index);

			cout << "Successfully deleted!" << endl;
		}
	}

	void editByIndex()
	{
		int index = getVehicleIndex();
		if (index == -1)
		{
			cout << "Invalid index." << endl;
		}
		else
		{
			Vehicle veh_to_edit = vehicles.at(index);

			string model;
			string country;
			int hourse_power;
			double price;
			char *time_raw;

			cout << "Enter vehicle model (" << veh_to_edit.model << " ?) :";
			getline(cin >> ws, model);
			cout << endl;

			cout << "Enter vehicle country (" << veh_to_edit.country << " ?) :";
			getline(cin >> ws, country);
			cout << endl;

			cout << "Enter vehicle hourse power (" << veh_to_edit.hourse_power << " ?) :";
			cin >> hourse_power;
			cout << endl;

			cout << "Enter vehicle price (" << veh_to_edit.price << " ?) :";
			cin >> price;
			cout << endl;

			cout << "Enter vehicle created_at (" << prepareData(veh_to_edit.created_at) << " ?) :";
			string input;
			int year, month, day;
			cin >> input; // а откуда пользователь об этом знает?: input can be 2005:03:09 or 2005/04/02 or whatever
			stringstream ss(input);
			char ch;
			ss >> year >> ch >> month >> ch >> day;

			if (model != "")
			{
				veh_to_edit.model = model;
			}

			if (country != "")
			{
				veh_to_edit.country = country;
			}

			if (hourse_power != 0)
			{
				veh_to_edit.hourse_power = hourse_power;
			}

			if (price != 0)
			{
				veh_to_edit.price = price;
			}

			if (input != "")
			{
				tm tm1;

				tm1.tm_year = year;
				tm1.tm_mon = month;
				tm1.tm_mday = day;
				veh_to_edit.created_at = tm1;
			}

			vehicles.at(index) = veh_to_edit;

			cout << "Vehicle edited: " << endl;

			printVeh(vehicles.at(index), index);
		}
	}

	void saveDataToFile()
	{
		string filename;
		cout << "File name (without ext): ";
		cin >> filename;

		ofstream output(filename + ".csv");
		output << "model,country,hourse_power,price,created_at\n";
		for (int i = 0; i < vehicles.size(); i++)
		{
			Vehicle current = vehicles.at(i);
			output << current.model + "," + current.country + "," + to_string(current.hourse_power) + "," + to_string(current.price) + "," + prepareData(current.created_at) + '\n';
		}
	}

	void readDataFromFile()
	{
		vector<pair<string, vector<string>>> result;
		string filename;
		cout << "File name (with .csv): ";
		cin >> filename;

		ifstream input(filename);
		// Make sure the file is open
		if (!input.is_open())
			throw std::runtime_error("Could not open file");
		// Helper vars
		std::string line, colname;
		if (input.good())
		{
			// Extract the first line in the file
			std::getline(input, line);

			// Create a stringstream from line
			std::stringstream ss(line);

			// Extract each column name
			while (std::getline(ss, colname, ','))
			{

				// Initialize and add <colname, int vector> pairs to result
				result.push_back({colname, std::vector<string>{}});
			}
		}
		// Read data, line by line
		while (std::getline(input, line))
		{
			// Create a stringstream of the current line
			vector<string> row = split(line, ",");

			// Keep track of the current column index
			int colIdx = 0;

			// Extract each row
			for (int i = 0; i < row.size(); i++)
			{
				string val = row.at(i);
				result.at(colIdx).second.push_back(val);
				colIdx++;
			}
		}

		// Close file
		input.close();

		for (int i = 0; i < result.at(0).second.size(); ++i)
		{
			Vehicle veh;
			for (int j = 0; j < result.size(); ++j)
			{
				string val = result.at(j).second.at(i);
				if (result.at(j).first == "model")
				{
					veh.model = val;
				}
				else if (result.at(j).first == "country")
				{
					veh.country = val;
				}
				else if (result.at(j).first == "hourse_power")
				{
					veh.hourse_power = stoi(val);
				}
				else if (result.at(j).first == "price")
				{
					veh.price = stod(val);
				}
				else if (result.at(j).first == "created_at")
				{

					int year, month, day;
					stringstream ss(val);
					char ch;
					ss >> year >> ch >> month >> ch >> day;

					tm tm1;

					tm1.tm_year = year;
					tm1.tm_mon = month;
					tm1.tm_mday = day;
					veh.created_at = tm1;
				}
				else
				{
					cout << "No match!" << endl;
				}
			}
			vehicles.push_back(veh);
		}
	}
};
