#ifndef __GREG__
#define __GREG__
#include "date.h"
#include <math.h>
namespace lab2{
  class Gregorian:public Date{
  private:
    void check_range(int,int,int);
    static bool is_leap_year(int);
  protected:
    void add_one_month();
    void sub_one_month();
    bool is_leap_year() const;
    int days_in_month(int) const;
    int days_in_month(int, int) const;
    static const std::string weekdaynames [];
    static const std::string monthnames [];
  public:
    Gregorian();
    explicit Gregorian(double);
    Gregorian(int, int, int);
    virtual ~Gregorian();
    virtual int year() const;
    virtual int month() const;
    virtual int day() const;
    virtual Date & add_month(int n = 1);
    virtual Date & add_year(int n = 1);
    virtual int week_day() const; //maybe not needed
    virtual int days_per_week() const;
    virtual int days_this_month() const;
    virtual std::string week_day_name() const;
    virtual std::string month_name() const;
    virtual int months_per_year() const;
    double double_julian_day(int, int, int);
    int mod_julian_day() const;
    double double_julian_day() const;
    Date & operator++();
    Gregorian operator++(int);
    Date & operator--();
    Gregorian operator--(int);
  };
}
#endif //__GREG__
