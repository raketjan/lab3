#ifndef __GREG__
#define __GREG__
#include "julian.h"
#include <math.h>
namespace lab2{
  class Gregorian:public Date{
    void add_one_month();
    void sub_one_month();
    bool is_leap_year() const;
    int days_in_month(int) const;
  public:
    Gregorian();
    explicit Gregorian(int);
    Gregorian(int, int, int);
    virtual ~Gregorian();
    virtual int year() const;
    virtual int month() const;
    virtual int day() const;
    virtual Date & add_month(int n = 1);
    virtual int days_this_month() const;
    int weekday() const;
    static int mod_julian_day(int, int, int);
    int mod_julian_day() const;
  };
}
#endif //__GREG__
