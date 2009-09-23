#ifndef __MIDDLE__
#define __MIDDLE__
include "date.h"

class Middle:public Date{
    Middle();
    ~Middle();
    Date(int months, int days_per_year );
    virtual Middle & operator++();
    virtual Middle &  operator--();
    virtual Middle & operator+=(int days);
    virtual Date & operator-=(int days);
    int year() const;
    int month() const;
    int day() const;
    int week_day() const;
    int days_per_week() const;
    int days_this_month() const;
    int months_per_year() const;
    std::string week_day_name() const;
    std::string month_name() const;
    virtual Middle & add_year(int n = 1);
    virtual Middle & add_month(int n = 1);
    int mod_julian_day() const;
};

#endif //__JULIA__
