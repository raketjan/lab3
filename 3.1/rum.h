#ifndef __RUM__
#define __RUM__
#include "indoors.h"

using namespace std;
namespace advgame{
  class Rum : public Indoors{
  public:
    Rum(string,string);
    virtual ~Rum();
    virtual Place & neighbour(string);
    virtual void enter(Actor *);
    virtual void leave(Actor *);
    virtual Item & pick_up(Item *);
    virtual Item & drop(Item *);
    
  };
}

#endif
