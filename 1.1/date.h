#ifndef __LAB2__
#define __LAB2__
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstddef>
namespace lab2{
  class Date{
  private:
  protected:
    static const int GENESIS = 1858;
    int offset;
    int days_per_year;
    //int days_per_month;
    int days_per_week_var;
  public:
    Date();    
    Date(int months, int days_per_year );
    virtual ~Date();
    virtual Date & operator++();
    virtual Date & operator--();
    virtual Date & operator+=(int days);
    virtual Date & operator-=(int days);
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;
    bool operator<(const Date &) const;
    bool operator<=(const Date &) const;
    bool operator>(const Date &) const;
    bool operator>=(const Date &) const;
    virtual int year() const;
    int month() const;
    inline int day() const;
    int week_day() const;
    int days_per_week() const;
    int days_this_month() const;
    int months_per_year() const;
    virtual std::string week_day_name() const;
    virtual std::string month_name() const;
    Date & add_year(int n = 1);
    Date & add_month(int n = 1);
    const int getOffset();
    int mod_julian_day() const;
  };
  
  /* Not in Date */
  int operator-(const Date &,const Date &);
  std::ostream & operator<<(std::ostream &,const Date &);
}

#endif //__LAB2__
