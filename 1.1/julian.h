#ifndef __JULIA__
#define __JULIA__
#include "date.h"
namespace lab2{
  class Julian : public Date{
  public:
  Julian();
  Julian(int);
  Julian(int, int, int);   // year month day
    virtual ~Julian();
    int year() const;
    int month() const;
    int day() const;
    int weekday() const;
    static int mod_julian_day(int,int,int);   // year month day
    int mod_julian_day() const;
  };
}
#endif //__JULIA__
