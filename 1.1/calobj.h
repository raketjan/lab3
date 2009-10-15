#ifndef __CALOBJ__
#define __CALOBJ__
#include "date.h"
#include <list>
#include <algorithm>
namespace lab2{
  template <class T>
    class Calobj{
  private:
    //  template <typename T> bool operator==(const T &,const T &);
    //friend bool operator<(const Calobj &,const Calobj &);
    std::list<std::string> events;
    T * date;
  public:
    Calobj(T *,std::string);
    ~Calobj();
    Calobj(const Calobj<T> &);
    bool add_event(std::string);
    bool remove_event(std::string);    
    bool exist_event(std::string);
    std::list<std::string> get_events();
    T * get_date();
    Calobj & operator=(const Calobj<T> &);
  };
  template <typename T> bool operator==(const Calobj<T> &, const Calobj<T> &);
  template <typename T> bool operator<(const Calobj<T> &, const Calobj<T> &);
}
#include "calobj.cpp"
#endif //__CALOBJ__
