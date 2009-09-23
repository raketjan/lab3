#ifndef __GREG__
#define __GREG__
#include "date.h"

class Gregorian:public lab2::Date{
    Gregorian();
    ~Gregorian();
    virtual int year();
};

#endif //__GREG__
