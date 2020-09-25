#include <iostream>
#include <string.h>

using namespace std;

class Soft
{
private:

	char* full_name;
	char* file_extension;
	char* associative_application;
	char* date_and_time;
	int size;
	
public:
	
	//конструктор по умолчанию
	Soft()
	{
		full_name = nullptr;
		file_extension = nullptr;
		associative_application = nullptr;
		date_and_time = nullptr;
		size = 0;

		cout << "конструктор по умолчанию -------- " << this << endl;
	}

	//конструктор с параметром
	Soft(char* full_name, char* file_extension)
	{
		this->full_name = new char[strlen(full_name) + 1];
		copy_by_character(this->full_name, full_name);

		this->file_extension = new char[strlen(file_extension) + 1];
		copy_by_character(this->file_extension, file_extension);

		associative_application = nullptr;
		date_and_time = nullptr;
		size = 0;

		cout << "конструктор с параметром -------- " << this <<  endl;
	}

	//конструктор копирования
	Soft(const Soft &other)
	{
		//копривоние поля name посимвольно
		if (other.full_name == nullptr) this->full_name = nullptr;
		else {
			this->full_name = new char[strlen(other.full_name) + 1];
			copy_by_character(this->full_name, other.full_name);
		}

		//копирование поля file_extension посимвольно
		if (other.file_extension == nullptr) this->file_extension = nullptr;
		else {
			this->file_extension = new char[strlen(other.file_extension) + 1];
			copy_by_character(this->file_extension, other.file_extension);
		}

		//копирование поля associative_application посимвольно
		if (other.associative_application == nullptr) this->associative_application = nullptr;
		else {
			this->associative_application = new char[strlen(other.associative_application) + 1];
			copy_by_character(this->associative_application, other.associative_application);
		}

		//копирование поля associative_application посимвольно
		if (other.date_and_time == nullptr) this->date_and_time = nullptr;
		else {
			this->date_and_time = new char[strlen(other.date_and_time) + 1];
			copy_by_character(this->date_and_time, other.date_and_time);
		}

		//копирование не динамической переменной
		this->size = other.size;

		cout << "конструктор копирования -------- " << this << endl;
	}

	~Soft()
	{
		delete[] full_name;
		delete[] file_extension;
		delete[] associative_application;
		delete[] date_and_time;

		cout << "диструктор\t" << this << endl;
	}

	//setters
	void set_name(char* new_name)
	{
		if (full_name != nullptr) { delete[] full_name; }

		full_name = new char[strlen(new_name) + 1];
		copy_by_character(full_name, new_name);
	}

	void set_extension(char* new_extension)
	{
		if (file_extension != nullptr) { delete[] file_extension; }

		file_extension = new char[strlen(new_extension) + 1];
		copy_by_character(file_extension, new_extension);
	}

	void set_associative_application(char* new_as_app) 
	{
		if (associative_application != nullptr) { delete[] associative_application; }

		associative_application = new char[strlen(new_as_app) + 1];
		copy_by_character(associative_application, new_as_app);
	}

	void set_date_and_time(char* new_date_and_time)
	{
		if (date_and_time != nullptr) { delete[] date_and_time; }

		date_and_time = new char[strlen(new_date_and_time) + 1];
		copy_by_character(date_and_time, new_date_and_time);
	}

	void set_size(int size) { this->size = size; }


	void print_soft()
	{
		cout << "Адресс объекта: " << this << endl;

		if (full_name != nullptr)
		cout << "\tName: " << full_name << endl;

		if (file_extension != nullptr)
		cout << "\tFile extension: " << file_extension << endl;

		if (associative_application != nullptr)
		cout << "\tAssociative application: " << associative_application << endl;

		if (date_and_time != nullptr)
		cout << "\tDate and time: " << date_and_time << endl;

		if (size != 0)
		cout << "\tSize: " << size << "\n" << endl;
	}

private:
	void copy_by_character(char* where_copy, char* from_where_copy)
	{
		int len = strlen(from_where_copy);
		for (int i = 0; i < len; i++)
		{
			where_copy[i] = from_where_copy[i];
		}
		where_copy[len] = '\0';
	};
};

int main()
{
	setlocale(LC_ALL,"ru");

	//создание объекта с помощью конструктора который устанавливает всем полям нулевые значения
	cout << "Способ создания файла: " << endl;
	cout << "\n1. По умолчанию (создается пустой фаил)" << endl;
	Soft soft_1;
	//вывод на экра не нулевых значений
	soft_1.print_soft();

	//создание объекта с помощью конструктора который устанавливат только название и расширение файла
	cout << "\n2. С установкой имени и расширения файла" << endl;
	char input_name[100];
	char input_extension[100];
	cout << "\nВведите название файла: ";
	cin >> input_name;

	cout << "Введите расширение файла: ";
	cin >> input_extension;
	Soft soft_2(input_name, input_extension);

	//вывод на экра не нулевых значений
	soft_2.print_soft();

	//применение конструктора копирования 
	cout << "\n3. Копирование одного файла в другой" << endl;
	Soft soft_3(soft_2);
	
	soft_3.print_soft();
	
	int choice = 0;
	while (choice != 4)
	{
		cout << "\nВы можете установить все данный файла лично. " << endl;
		cout << "1. Ввести новые данные " << endl;
		cout << "2. Изменить одно поле " << endl;
		cout << "3. Вывод на экран" << endl;
		cout << "4. Ничего не изменять" << endl;
		cin >> choice;

		char input[100];
		int chois_in_switch = 0;
		switch (choice)
		{
		case 1:
			cout << " Name: ";
			cin >> input;
			soft_3.set_name(input);

			cout << " File extension: ";
			cin >> input;
			soft_3.set_extension(input);

			cout << " Associative application: ";
			cin >> input;
			soft_3.set_associative_application(input);

			cout << " Date and time: ";
			cin >> input;
			soft_3.set_date_and_time(input);

			int input_size;
			cout << " Size: ";
			cin >> input_size;
			soft_3.set_size(input_size);

			break;
		case 2:
			cout << "Какое поле изменить: " << endl;
			cout << "1. Name" << endl;
			cout << "2. File extension " << endl;
			cout << "3. Associative application " << endl;
			cout << "4. Date and time" << endl;
			cout << "5. Size" << endl;
			cout << "6. Никакое" << endl;
			cin >> chois_in_switch;

			switch (chois_in_switch)
			{
			case 1:
				cout << " Name: ";
				cin >> input;
				soft_3.set_name(input);
				break;
			case 2:
				cout << " File extension: ";
				cin >> input;
				soft_3.set_extension(input);
				break;
			case 3:
				cout << " Associative application: ";
				cin >> input;
				soft_3.set_associative_application(input);
				break;
			case 4:
				cout << " Date and time: ";
				cin >> input;
				soft_3.set_date_and_time(input);
				break;
			case 5:
				int input_size;
				cout << " Size: ";
				cin >> input_size;
				soft_3.set_size(input_size);
				break;
			default:
				break;
			}

			break;
		case 3:
			soft_3.print_soft();
			break;
		default:
			break;
		}
	}
	
}