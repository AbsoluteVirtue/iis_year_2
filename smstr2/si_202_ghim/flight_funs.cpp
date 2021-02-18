#include <iostream>
#include <string>
#include "flight_funs.h"
#include <limits>
#include <fstream>
#include <algorithm>
using namespace std;

// 1
void Flight_controller::Create_array(int n) {
	fl_arr = (Flight*)malloc(n * sizeof(Flight));
	num_of_flights = n;
	created = 1;
}

// 2
void Flight_controller::Kb_arr_enter() {
	if (created == 0) return;
	for (int i = 0; i < num_of_flights; i++) {
		cout << "Enter the infor for Flight " << i + 1 << endl;
		cout << " Number: "; cin >> fl_arr[i].number;
		std::string tmp = "";
		cout << " Depature city: "; cin >> tmp;
		for (int j = 0; j < 15; j++)
			fl_arr[i].dep_city[j] = tmp[j];
		fl_arr[i].dep_city[15] = '\0';
		cout << " Arrival city: "; cin >> tmp;
		for (int j = 0; j < 15; j++)
			fl_arr[i].arv_city[j] = tmp[j];
		fl_arr[i].arv_city[15] = '\0';
		cout << " -- Enter time as <hours> <minutes>. They have to be separated by space.--" << endl;
		cout << " Depature time: "; cin >> &fl_arr[i].dep_time;
		cout << " Arrival time: "; cin >> &fl_arr[i].arv_time;
		cout << " Ticket cost: "; cin >> fl_arr[i].tic_cost;
	}
}

// Return converted number of minutes to f_time type
f_time Flight_controller::itof(int number) {
	f_time tmp;
	tmp.hours = (number / 60) % 24;
	tmp.minutes = number % 60;
	return tmp;
}

// 3
void Flight_controller::Find(int num) {
	if (created == 0) return;
	for (int i = 0; i < num_of_flights; i++)
		if (fl_arr[i].number == num) {
			cout << "Found by number!" << endl;
			cout << fl_arr[i] << endl;
		}
}


void Flight_controller::Find(std::string city) {
	if (created == 0) return;
	for (int i = 0; i < num_of_flights; i++) {
		if (fl_arr[i].dep_city == city) {
			cout << "Found by depature city!" << endl;
			cout << fl_arr[i] << endl;
		}
	}

	for (int i = 0; i < num_of_flights; i++) {
		if (fl_arr[i].arv_city == city) {
			cout << "Found by arrival city!" << endl;
			cout << fl_arr[i] << endl;
		}
	}
}


void Flight_controller::Find(f_time t) {
	if (created == 0) return;
	for (int i = 0; i < num_of_flights; i++)
		if (fl_arr[i].dep_time == t) {
			cout << "Found by depature time!" << endl;
			cout << fl_arr[i] << endl;
		}
	// I did not copy-pasted it from above. Really.
	for (int i = 0; i < num_of_flights; i++)
		if (fl_arr[i].arv_time == t) {
			cout << "Found by depature time!" << endl;
			cout << fl_arr[i] << endl;
		}
}


void Flight_controller::swap(int first, int second) {
	Flight tmp = fl_arr[first];
	fl_arr[first] = fl_arr[second];
	fl_arr[second] = tmp;
}

// 4
void Flight_controller::Sort() {
	if (created == 0) return;
	for (int i = 0; i < num_of_flights; i++) {
		int i_min = i;
		for (int j = i + 1; j < num_of_flights; j++)
			if (fl_arr[i_min].number < fl_arr[j].number)
				i_min = j;
		swap(i, i_min);
	}
}

// Cutting off big numbers of time
void Flight_controller::time_mod(f_time* t) {
	(*t).hours %= 24;
	(*t).minutes %= 60;
}

// 5
void Flight_controller::Edit(int index) {
	if (created == 0) return;
	if (index < 0 || index > num_of_flights)
		return;
	cout << "What do you want to edit?\n";
	cout << "  1. Number\n  2. Depature city\n  3. Arrival city\n";
	cout << "  4. Depature time\n  5. Arrival time\n  6. Ticket cost\n";
	int input = 0;
	while (input < 1 || input > 6) {
		cin >> input;
		// Validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered wrong type. Enter the number again:\n";
			cin >> input;
		}
		else if (input < 1 or input > 6)
			cout << "You need to enter in range from 1 to 6:\n";
	}
	switch (input) {
	// Change Number
	case 1: {
		int num = 0;
		bool is_unique;
		do {
			is_unique = true;
			// Validation for number
			while (num <= 0) {
				cin >> num;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong type. Enter the number again:\n";
					cin >> num;
				}
				else if (num < 0)
					cout << "You need to enter possitive number!\n";
			}
			for (int i = 0; i < num_of_flights; i++)
				if (fl_arr[i].number == num) {
					cout << "You need to enter unique number for flight!\n";
					is_unique = false;
				}
		} while (!is_unique);
		fl_arr[index].number = num;
	}
	// Change Depature city
	case 2: {
		string city;
		do {
			cin >> city;
			if (fl_arr[index].dep_city == city)
				cout << "You won't change anything! Please enter the different depature city!\n";
		} while (fl_arr[index].dep_city == city);
	}
	// Change Arrival city
	case 3: {
		string city;
		do {
			cin >> city;
			if (fl_arr[index].arv_city == city)
				cout << "You won't change anything! Please enter the different arrival city!\n";
		} while (fl_arr[index].arv_city == city);
	}
	// Change Depature time
	case 4: {
		f_time t;
		do {
			cout << "Enter hours and minutes, separated with space:\n";
			cin >> &t;
			time_mod(&t);
			if (fl_arr[index].dep_time == t)
				cout << "Enter different depature time:\n";
		} while (fl_arr[index].dep_time == t);
	}
	// Change Arrival time
	case 5: {
		f_time t;
		do {
			cout << "Enter hours and minutes, separated with space:\n";
			cin >> &t;
			time_mod(&t);
			if (fl_arr[index].arv_time == t)
				cout << "Enter different depature time:\n";
		} while (fl_arr[index].arv_time == t);
	}
	// Change Ticket cost
	case 6: {
		int cost = 0;
		do {
			while (cost <= 0) {
				cin >> cost;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have entered wrong type. Enter the cost again:\n";
					cin >> cost;
				}
				else if (cost < 0)
					cout << "You need to enter possitive number!\n";
			}
			if (fl_arr[index].tic_cost == cost)
				cout << "You need to enter different ticket cost";
		} while (fl_arr[index].tic_cost == cost);
		fl_arr[index].tic_cost = cost;
	}
	}
}

// 6
void Flight_controller::Push_back(Flight fl) {
	num_of_flights++;
	fl_arr = (Flight*)realloc(fl_arr, num_of_flights *sizeof(Flight));
	fl_arr[num_of_flights - 1] = fl;
	if (num_of_flights == 1) created = 1;
}

// 7
void Flight_controller::Delete(int ind) {
	if (created == 0) return;
	num_of_flights--;
	for (int i = ind; i < num_of_flights; i++)
		fl_arr[i] = fl_arr[i + 1];
	fl_arr = (Flight*)realloc(fl_arr, num_of_flights * sizeof(Flight));
}

// 8
void Flight_controller::Insert(int ind, Flight fl) {
	num_of_flights++;
	fl_arr = (Flight*)realloc(fl_arr, num_of_flights * sizeof(Flight));
	for (int i = ind + 1; i < num_of_flights; i++)
		fl_arr[i] = fl_arr[i - 1];
	fl_arr[ind] = fl;
	if (num_of_flights == 1) created = 1;
}

// 9
void Flight_controller::File_create() {
	ofstream OutputFile("flights.txt");
	for (int i = 0; i < num_of_flights; i++)
		OutputFile << fl_arr[i].number << " " << fl_arr[i].dep_city << " " << fl_arr[i].dep_time << " " <<
		fl_arr[i].arv_city << " " << fl_arr[i].arv_time << " " << fl_arr[i].tic_cost << " ;" << endl;
}

// 10
void Flight_controller::File_dump() {
	ifstream InputFile;
	InputFile.open("flights.txt");
	if (InputFile.fail()) return;
	int lines = count(istreambuf_iterator<char>(InputFile),
		istreambuf_iterator<char>(), '\n');
	Flight_controller::Create_array(lines);
	InputFile.close();
	string line;
	int i = 0;
	int ind = 0;
	InputFile.open("flights.txt");
	while (getline(InputFile, line)) {
		string delimiter = " ";
		int len = line.length();
		while (line.find(" ") < len) {
			string token = line.substr(0, line.find(delimiter));
			line = line.substr(line.find(delimiter) + 1, len);
			len = line.length();
			switch (ind) {
			case 0: {
				fl_arr[i].number = stoi(token);
				break;
			}
			case 1: {
				for (int j = 0; j < token.length(); j++)
					fl_arr[i].dep_city[j] = token[j];
				fl_arr[i].dep_city[token.length()] = '\0';
				break;
			}
			case 2: {
				fl_arr[i].dep_time.hours = stoi(token);
				break;
			}
			case 3: {
				fl_arr[i].dep_time.minutes = stoi(token);
				break;
			}
			case 4: {
				for (int j = 0; j < token.length(); j++)
					fl_arr[i].arv_city[j] = token[j];
				fl_arr[i].arv_city[token.length()] = '\0';
				break;
			}
			case 5: {
				fl_arr[i].arv_time.hours = stoi(token);
				break;
			}
			case 6: {
				fl_arr[i].arv_time.minutes = stoi(token);
				break;
			}
			case 7: {
				fl_arr[i].tic_cost = stoi(token);
				break;
			}
			}
			ind++;
		}
		i++;
		ind = 0;
	}
	InputFile.close();
}


// 11
void Flight_controller::Print() {
	if (created == 0) {
		cout << "Array is empty!" << endl;
		return;
	}
	for (int i = 0; i < num_of_flights; i++)
		cout << "[" << i << "] " << fl_arr[i] << endl;
}
