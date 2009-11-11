#ifndef __INDOORS__
#define __INDOORS__

#include <vector>
#include "place_actor.h"
using namespace std;
namespace advgame{
  
  class Indoors : public Place{
  public:
    Indoors(string, string);
    virtual ~Indoors();
    virtual Place & neighbour(Direction direction) = 0;
    virtual void enter(Actor *) = 0;
    virtual void leave(Actor *) = 0;
    virtual Item & pick_up(Item *) = 0;
    virtual Item & drop(Item *) = 0;
  };
}

#endif