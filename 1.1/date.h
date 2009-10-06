#ifndef __LAB2__
#define __LAB2__
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstddef>
#include "kattistime.h"
namespace lab2{
  class Date{
    friend  std::ostream & operator<<(std::ostream &, const Date &);
    
  private:
  public:
    static const int GENESIS = 1858;
    int offset;
    int days_per_year;
    //int days_per_month;
    int days_per_week_var;
  public:
    Date();    
    explicit Date(int);
    Date(int months, int days_per_year );
    virtual ~Date();
    Date & operator++();
    Date & operator++(int);
    //    Date & operator++(int = 0);
    Date & operator--();
    Date & operator--(int);
    Date & operator+=(int days);
    Date & operator-=(int days);
    virtual int year() const = 0;
    virtual int month() const = 0;
    virtual int day() const = 0;
    int week_day() const;
    int days_per_week() const;
    virtual int days_this_month() const = 0;
    int months_per_year() const;
    virtual std::string week_day_name() const;
    virtual std::string month_name() const;
    
    Date & add_year(int n = 1);
    virtual Date & add_month(int n = 1) = 0;
    int getOffset() const;
    int mod_julian_day() const;
  };

  /* Not in Date */
  int operator-(const Date &,const Date &);
 std::ostream & operator<<(std::ostream &, const Date &);
  bool operator==(const Date &,const Date &); //const
  bool operator!=(const Date &,const Date &);
  bool operator<(const Date &,const Date &);
  bool operator<=(const Date &,const Date &);
  bool operator>(const Date &,const Date &);
  bool operator>=(const Date &,const Date &);
  
}

#endif //__LAB2__
