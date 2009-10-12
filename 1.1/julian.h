#ifndef __JULIA__
#define __JULIA__
#include "date.h"
#include <math.h>
namespace lab2{
  class Julian:public Date{
  protected:
    void add_one_month();
    void sub_one_month();
    bool is_leap_year() const;
    int days_in_month(int) const;
    static const std::string weekdaynames [];
    static const std::string monthnames [];
  public:
    Julian();
    explicit Julian(int);
    Julian(int, int, int);
    virtual ~Julian();
    virtual int year() const;
    virtual int month() const;
    virtual int day() const;
    virtual Date & add_month(int n = 1);
    virtual Date & add_year(int n = 1);
    virtual int week_day() const; //maybe not needed
    //int weekday() const;
    virtual int days_per_week() const;
    virtual int days_this_month() const;
    virtual std::string week_day_name() const;
    virtual std::string month_name() const;
    
    static int mod_julian_day(int, int, int);
    
int mod_julian_day() const;
//Måste ha med båda?
 Date & operator++();
 Julian operator++(int);

 Date & operator--();
 Julian operator--(int);
  };
}
#endif //__JULIA__
