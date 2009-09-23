#ifndef __JULIA__
#define __JULIA__
#include "date.h"

class Julian:public lab2::Date{
    Julian();
    ~Julian();
    virtual int year();
};

#endif //__JULIA__
