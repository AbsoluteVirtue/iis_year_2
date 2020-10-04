#include <iostream>
#include <cstring>

using namespace std;

class Doucument{
private:
    char* name{nullptr};
    char* theme{nullptr};
    char* author{nullptr};
    int numberOfPage{0};
    int day{0};
    int month{0};
    int year{0};
    int hours{0};
    int minutes{0};
public:
    Doucument(){
        cout << "Конструктор по умолчанию -------- " << this << endl;
    }
    Doucument(char* name, char* theme, char* author){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->theme = new char[strlen(theme)+1];
        strcpy(this->theme, theme);
        this->author = new char[strlen(author)+1];
        strcpy(this->author, author);
        numberOfPage = 0;
        day = 0;
        month = 0;
        year = 0;
        hours = 0;
        minutes = 0;
        cout << "Конструктор с параметром -------- " << this << endl;
    }
    Doucument(const Doucument &doc){
        this->name = (doc.name == nullptr) ? nullptr : new char[strlen(doc.name) + 1];
        strcpy(this->name, doc.name);
//            if (doc.theme == nullptr) this->theme = nullptr;
//            else {
//            this->theme = new char[strlen(doc.theme) + 1];
//            strcpy(this->theme, doc.theme);
//            }
        this->theme = (doc.theme == nullptr) ? nullptr : new char[strlen(doc.theme) + 1];
        strcpy(this->theme, doc.theme);
        this->author = (doc.author == nullptr) ? nullptr : new char[strlen(doc.author) + 1];
        strcpy(this->author, doc.author);
        this->numberOfPage = doc.numberOfPage;
        this->day = doc.day;
        this->year = doc.year;
        this->month = doc.month;
        this->hours = doc.hours;
        this->minutes = doc.minutes;
        cout << "Конструктор копирования -------- " << this << endl;
    }
    ~Doucument(){
        delete [] name;
        delete [] theme;
        delete [] author;
        cout << "Диструктор" << this << endl;
    }
    void setName(char* newName){
    if (name != nullptr) { delete[] name; }
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
    void setTheme(char* newTheme){
        if (theme != nullptr) { delete[] theme; }
        theme = new char[strlen(newTheme) + 1];
        strcpy(theme, newTheme);
    }
    void setAuthor(char* newAuthor){
    if (author != nullptr) { delete[] author; }
        author = new char[strlen(newAuthor) + 1];
        strcpy(author, newAuthor);
    }
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }
    void setHours(int hours) { this->hours = hours; }
    void setMinutes(int minutes) { this->minutes = minutes; }
    void printDocument(){
        if (name != nullptr)
        cout << "\tName of Document: " << name << endl;
        if (theme != nullptr)
        cout << "\tTopic of Document: " << theme << endl;
        if (author != nullptr)
        cout << "\tAuthor of Document: " << author << endl;
        if ((day != 0)&&(month != 0) && (year!= 0))
            cout << "\tTime of the last Save: " <<day<<"-"<<month<<"-"<<year<<" "<<hours<<":"<<minutes << "\n" << endl;
        }
};

int main(int argc, char const *argv[])
{
    Doucument doc;

    doc.setName("Name");

    doc.printDocument();
    return 0;
}
