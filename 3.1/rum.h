#ifndef __RUM__
#define __RUM__
#include "indoors.h"

using namespace std;
namespace advgame{
  class Rum : public Indoors{
  public:
    Rum(string,string);
    virtual ~Rum();
    virtual string save();
  };
}

#endif
