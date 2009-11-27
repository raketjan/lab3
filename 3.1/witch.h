#ifndef __WITCH__
#define __WITCH__
#include <vector>
#include "npc.h"
#include "place_actor.h"
#include "item.h"
using namespace std;
namespace advgame{
  class Witch : public Npc{
  public:
    Witch(int,string);
    virtual ~Witch();
    virtual void action();
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
    virtual void give(string); 

  };
}

#endif
 
