#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>

struct f_time {
	int minutes = 0;
	int hours = 0;

	friend inline bool operator==(const f_time first, const f_time second) {
		return (first.hours == second.hours) and (first.minutes == second.minutes);
	}

	friend std::ostream& operator <<(std::ostream& out, const f_time time) {
		out << time.hours << " " << time.minutes;
		return out;
	}
	
	friend std::istream& operator >>(std::istream& in, f_time* time) {
		in >> (*time).hours >> (*time).minutes;
		return in;
	}
};

struct Flight {
	int number;
	char dep_city[15] = "";
	char arv_city[15] = "";
	f_time dep_time;
	f_time arv_time;
	int tic_cost;

	friend std::ostream& operator <<(std::ostream& out, const Flight tmp) {
		out << "Flight " << tmp.number << " from " << tmp.dep_city << " in " <<
			tmp.dep_time.hours << ":" << tmp.dep_time.minutes << " to " <<
			tmp.arv_city << " in " << tmp.arv_time.hours << ":" << tmp.arv_time.minutes <<
			". Ticket cost equal " << tmp.tic_cost;
		return out;
	}
};

class Flight_controller {
public:
	// 1
	void Create_array(int n);
	// 2
	void Kb_arr_enter();
	// 3
	void Find(int num);
	void Find(std::string city);
	void Find(f_time t);
	f_time itof(int number);
	// 4
	void Sort();
	// 5
	void Edit(int index);
	// 6
	void Push_back(Flight fl);
	// 7
	void Delete(int ind);
	// 8
	void Insert(int ind, Flight fl);
	// 9
	void File_create();
	// 10
	void File_dump();
	// 11
	void Print();
private:
	int num_of_flights = 0;
	int created = 0;
	Flight* fl_arr = nullptr;
	// 4
	void swap(int first, int second);
	// 5
	void time_mod(f_time* t);
};

#endif // !FUNCTIONS 
