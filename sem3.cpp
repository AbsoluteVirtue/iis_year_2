#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// абстрактный базовый класс
class HttpBase {
public:
    // виртуальные методы без реализации
    virtual void get(std::string args) {
        std::cout << " GET not implemented "<< std::endl;
    }
    virtual void post(std::string args) {
        std::cout << " POST not implemented "<< std::endl;
    }
};


class HttpDepr : public HttpBase {
    std::string msg{"successful request"};
    int status_code{200};

    std::string output() {
        return "status: " + std::to_string(status_code) + ", message: " + msg; 
    }

public:
    // переопределение метода базового класса
    void get(std::string args) override {
        if(args == "") {
            status_code = 400;
            msg = "failed request";
        }
        std::cout << args << " GET - " << output() << std::endl;
    }
};


class Http : public HttpBase {
protected:
    std::string msg{"successful request"};
    int status_code{200};
    
    std::string output() {
        return "[" + std::to_string(status_code) + "]: " + msg; 
    }

public:
    // переопределение метода базового класса
    void get(std::string args) override {
        if(args == "") {
            status_code = 400;
            msg = "failed request";
        }
        std::cout << args << " GET - " << output() << std::endl;
    }
    // переопределение метода базового класса
    void post(std::string args) override {
        if(args == "") {
            status_code = 400;
            msg = "failed request";
        } else {
            status_code = 201;
        }
        std::cout << args << " POST - " << output() << std::endl;
    }
};

// множественное наследование
class HttpSpec : public HttpDepr, public Http {
public:
    // расширение функционала базовых классов в дочернем классе
    void patch(std::string args) {
        if(args == "") {
            Http::status_code = 400;
            Http::msg = "failed request";
        } else {
            Http::status_code = 202;
        }
        std::cout << args << " PATCH - " << Http::output() << std::endl;
    }
};

// полиморфный метод для работы с объектами дочерних классов 
// через тип базового класса
void process_connection(HttpBase & connection) {
    connection.get("test get");
    connection.post("test post");
}

// специальный метод для решения проблемы неопределенности 
// пространств имен при ромбовидном наследовании 
void process_connection(HttpSpec & connection) {
    connection.HttpDepr::get("test get");
    connection.Http::post("test post");
    connection.patch("test patch");
}


int main(int argc, char const *argv[])
{
    Http connect;
    process_connection(connect);

    HttpDepr connect_depr;
    process_connection(connect_depr);

    // пример ромбовидного наследования, полиморфная функция не работает
    // необходима перегрузка для специального случая
    HttpSpec connect_spec;
    process_connection(connect_spec);

    std::list<int> v;
    v.push_back(2);
    v.push_back(35);

    for (auto c : v) {
        std::cout << c << std::endl;
    }

    return 0;
}
