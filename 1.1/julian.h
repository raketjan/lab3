#ifndef __JULIA__
#define __JULIA__
#include "gregorian.h"
namespace lab2{
  class Julian:public Gregorian{
  public:
    
    Julian();
    explicit Julian(int);
    Julian(int, int, int);   // year month day
    virtual ~Julian();
    virtual int year() const;
    virtual int month() const;
    virtual int day() const;
    virtual int weekday() const;
    virtual std::string week_day_name() const;
    virtual std::string month_name() const;
    
    static int mod_julian_day(int,int,int);   // year month day
    int mod_julian_day() const;
    virtual Julian & operator++();
    virtual Julian operation(int);
    virtual Julian & operator--();
    virtual Julian operator--(int);
  };
}
#endif //__JULIA__
