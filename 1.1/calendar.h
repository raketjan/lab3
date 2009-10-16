#ifndef __CAL__
#define __CAL__
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <cstddef>
#include "kattistime.h"
#include "calobj.h"
namespace lab2{
  template <class T>
    class Calendar{
  private:
    // eller public getter
    template <class U> friend std::ostream & operator<<(std::ostream &,const Calendar<U> &);
  private:
    T * today;
    std::set<Calobj<T> > events;
  public:
    bool set_date(int,int,int);
    bool add_event(std::string,int,int,int);
    bool add_event(std::string,int,int);
    bool add_event(std::string,int);
    bool add_event(std::string);
    bool remove_event(std::string,int,int,int);
    bool remove_event(std::string,int,int);
    bool remove_event(std::string,int);
    bool remove_event(std::string);
    const std::set<Calobj<T> > & get_events() const;
    const T * get_today() const;
    Calendar & operator=(const Calendar &);
    template <class S> Calendar<T> & operator=(const Calendar<S> & );
    
    Calendar(const Calendar &);
    template <class S>Calendar(const Calendar<S> & );
    
    Calendar();
    ~Calendar();
  };
}

#include "calendar.cpp"

#endif //__CAL__
