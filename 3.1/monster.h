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
    virtual int fight(Actor *);
    virtual Item& pick_up(Item *);
    virtual Item& drop(Item *);
    virtual void talk_to(Actor *);
  };
}

#endif
 
