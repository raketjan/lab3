#ifndef __GREG__
#define __GREG__
#include "julian.h"
namespace lab2{
  class Gregorian:public Julian{
    Gregorian();
    virtual ~Gregorian();
    virtual int year();
  };
}
#endif //__GREG__
