#ifndef __LAB2__
#define __LAB2__
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstddef>
#include "kattistime.h"
#include <math.h>
namespace lab2{
  class Date{
    /* friend? */
    friend  std::ostream & operator<<(std::ostream &, const Date &);
    friend bool operator==(const Date &,const Date &);    
    friend bool operator!=(const Date &,const Date &);
    friend bool operator<(const Date &,const Date &);
    friend bool operator<=(const Date &,const Date &);
    friend bool operator>(const Date &,const Date &);
    friend bool operator>=(const Date &,const Date &);
    friend int operator-(const Date &,const Date &);
    //TODO get_offset
  public:
    //protected:
    //static const int GENESIS = 1858;
    double offset;
    //int days_per_year;
    //int days_per_month;
    //int days_per_week_var;
  public:
    Date();    
    explicit Date(int);
    //Date & Date(const & d);
    Date(int months, int days_per_year );
    Date & operator=(const Date &);
    virtual ~Date();
    Date & operator+=(int);
    Date & operator-=(int);
    virtual int year() const = 0;
    virtual int month() const = 0;
    virtual int day() const = 0;
    virtual int week_day() const = 0;
    virtual int days_per_week() const = 0;
    virtual int days_this_month() const = 0;
    virtual int months_per_year() const = 0;
    virtual std::string week_day_name() const = 0;
    virtual std::string month_name() const = 0;
    Date & operator++();
    Date & operator--();
    virtual Date & add_year(int n = 1) = 0;
    virtual Date & add_month(int n = 1) = 0;
    virtual int mod_julian_day() const = 0;
    virtual double double_julian_day() const = 0;
    double getOffset() const;
  };

  /* Not in Date */
  
  int operator-(const Date &,const Date &);
  std::ostream & operator<<(std::ostream &, const Date &);

  /* TODO Should theese be const? */
  bool operator==(const Date &,const Date &);
  bool operator!=(const Date &,const Date &);
  bool operator<(const Date &,const Date &);
  bool operator<=(const Date &,const Date &);
  bool operator>(const Date &,const Date &);
  bool operator>=(const Date &,const Date &);
  
}

#endif //__LAB2__
