#include <iostream>
#include <cstring>
#include <string>


class Coordinates {
    int x {0};
    int y {0};
    char * p {nullptr};
public:
    Coordinates() {}

    Coordinates(int _x, int _y, const char * _p) : x(_x), y(_y)
    {
        p = new char [strlen(_p) + 1];

        for (int i=0; i < strlen(_p); i += 1) {
            p[i] = _p[i];
        }

        p[strlen(_p)] = '\0';
    }

    Coordinates(const Coordinates & data) 
    {
        * this = data;
    }

    Coordinates(Coordinates && data) noexcept
    {
        * this = std::move(data);
    }

    ~Coordinates()
    {
        delete [] p;
    }

    Coordinates & operator=(const Coordinates & data) 
    {
        x = data.x;
        y = data.y;

        if (p == nullptr) {
            p = new char [strlen(data.p)  + 1];

            for (int i=0; i < strlen(data.p); i += 1) {
                p[i] = data.p[i];
            }
            p[strlen(data.p)] = '\0';
        }

        return * this;
    }

    Coordinates & operator=(Coordinates && data) noexcept
    {
        if (this != &data) {
            x = data.x;
            data.x = 0;
            y = data.y;
            data.y = 0;

            delete [] p;

            p = data.p;
            data.p = nullptr;
        }

        return * this;
    }

    friend std::ostream & operator<<(std::ostream & outs, const Coordinates & data) 
    {
        outs << data.p;
        return outs;
    }

    const char * get_p() const
    {
        return p;
    }

    const int get_x() const
    {
        return x;
    }

    const int get_y() const
    {
        return y;
    }

    void print()
    {
        std::cout << "x: " << x << "; y: " << y << std::endl;
        if (p != nullptr) {
            std::cout << p << std::endl;
        }
    }
};


int main(int argc, char const *argv[]) 
{
    Coordinates c;

    Coordinates coord(1, 2, "hello");

    Coordinates coord_copy(coord);

    Coordinates coord_eq = coord_copy;

    Coordinates coord_move = std::move(coord_eq);

    std::cout << coord_move << std::endl;

    return 0;
}
