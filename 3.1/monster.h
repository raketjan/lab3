#ifndef __MONSTER__
#define __MONSTER__
#include <vector>
#include "npc.h"
#include "place_actor.h"
#include "item.h"
using namespace std;
namespace advgame{
  class Monster : public Npc{
  public:
    Monster(int,string);
    virtual ~Monster();
    virtual void action();
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
  
  };
}

#endif
 
