#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

/*
    HttpDepr    Http
        \      /
        HttpSpec


        HttpBase
        /      \
    HttpDepr    Http
        \      /
        HttpSpec


    HttpBase    HttpBase
      \          /
    HttpDepr    Http
        \      /
        HttpSpec
*/

class HttpBase
{
public:
    virtual void get(std::string args) = 0;
    virtual void post(std::string args) = 0;
};

class HttpDepr : virtual public HttpBase
{
    std::string msg{"successful request"};
    int status_code{200};

    std::string output()
    {
        return "status: " + std::to_string(status_code) + ", message: " + msg; 
    }
public:
    void get(std::string args) override
    {
        if(args == "") {
            status_code = 400;
            msg = "failed request";
        }
        std::cout << args << ", GET - " << output() << std::endl;
    }

    void post(std::string args) override
    {
        if(args == "") {
            status_code = 400;
            msg = "failed request";
        }
        std::cout << args << ", POST - " << output() << std::endl;
    }
};

class Http : virtual public HttpBase
{
protected:
    std::string msg{"successful request"};
    int status_code{200};
    
    std::string output()
    {
        return "[" + std::to_string(status_code) + "]: " + msg; 
    }
public:
    void get(std::string args) override
    {
        if(args == "")
        {
            status_code = 400;
            msg = "failed request";
        }
        std::cout << args << ", GET > " << output() << std::endl;
    }

    void post(std::string args) override
    {
        if(args == "")
        {
            status_code = 400;
            msg = "failed request";
        }
        else
        {
            status_code = 201;
        }
        std::cout << args << ", POST > " << output() << std::endl;
    }
};


class HttpSpec : public HttpDepr, public Http
{
public:
    void get(std::string args)
    {
        HttpDepr::get(args);
    } 

    void post(std::string args)
    {
        Http::post(args);
    } 

    void patch(std::string args)
    {
        if(args == "")
        {
            Http::status_code = 400;
            Http::msg = "failed request";
        }
        else
        {
            Http::status_code = 202;
        }
        std::cout << args << " PATCH - " << Http::output() << std::endl;
    }
};


void process_connection(HttpBase & connection)
{
    connection.get("test get");
    connection.post("test post");
}


int main(int argc, char const *argv[])
{
    Http connect;
    process_connection(connect);

    HttpDepr connect_depr;
    process_connection(connect_depr);

    HttpSpec connect_spec;
    process_connection(connect_spec);

    return 0;
}
