#ifndef __GREG__
#define __GREG__
#include "julian.h"
namespace lab2{
  class Gregorian:public Date{
  public:
    Gregorian();
    explicit Gregorian(int);
    Gregorian(int, int, int);
    virtual ~Gregorian();
    virtual int year() const;
    virtual int month() const;
    virtual int day() const;
    int weekday() const;
    static int mod_julian_day(int, int, int);
    int mod_julian_day() const;
  };
}
#endif //__GREG__
