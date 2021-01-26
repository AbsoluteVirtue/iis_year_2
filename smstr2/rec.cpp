#include <cstdio>
#include "rec.h"

void record::print()
{
    printf("%s %s %.0f %.0f\n", 
                this->code,
                this->birthplace.c_str(),
                this->night_pop,
                this->resident_pop);
}
