#ifndef __JULIA__
#define __JULIA__
#include "date.h"
namespace lab2{
  class Julian:public Date{
    Julian();
    virtual ~Julian();
    virtual int year();
  };
}
#endif //__JULIA__
