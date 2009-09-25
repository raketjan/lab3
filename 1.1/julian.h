#ifndef __JULIA__
#define __JULIA__
#include "date.h"
namespace lab2{
  class Julian : public Date{
  public:
  Julian();
  Julian(int);
    virtual ~Julian();
    int year() const;
    int month() const;
  };
}
#endif //__JULIA__
