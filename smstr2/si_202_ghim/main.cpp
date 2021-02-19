
#include "flight_funs.h"

static int count = 10;

int main(int argc, char const *argv[])
{
    Flight_controller fc;

    fc.Create_array(count);

    Flight f = {10, "test", "TEST", {10, 00}, {11, 00}, 100};
    fc.Push_back(f);

    fc.Print();

    fc.Free();

    return 0;
}
