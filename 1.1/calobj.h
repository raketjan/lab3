#ifndef __CALOBJ__
#define __CALOBJ__
#include "date.h"
#include <list>
#include <algorithm>
namespace lab2{
  template <class T>
    class Calobj{
  private:
    std::list<std::string> events;
    T * date;
  public:
    Calobj(T *,std::string);
    ~Calobj();
    Calobj(const Calobj &);
    template<class U>
    Calobj(const Calobj<U> &);
    bool add_event(std::string);
    bool remove_event(std::string);
    bool exist_event(std::string);
    const std::list<std::string> & get_events() const;    
    const T * get_date() const;
    Calobj & operator=(const Calobj<T> &);
  };
  template <typename T> bool operator==(const Calobj<T> &, const Calobj<T> &);
  template <typename T> bool operator==(const Date &, const Calobj<T> &);
  template <typename T> bool operator==(const Calobj<T> &,const Date &);
  template <typename T> bool operator<(const Calobj<T> &, const Calobj<T> &);
  template <typename T> bool operator<(const Calobj<T> &, Date &);
  template <typename T> std::ostream & operator<<(std::ostream &, const Calobj<T> &);
  
}
#include "calobj.cpp"
#endif //__CALOBJ__
