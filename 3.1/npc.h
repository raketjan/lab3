#ifndef __NPC__
#define __NPC__
#include <vector>
#include "place_actor.h"
using namespace std;
namespace advgame{
  class Npc : public Actor{
  public:
    Npc(int,string);
    virtual void action() = 0;
    virtual int fight(Actor *) = 0;
    virtual void talk_to(Actor *) = 0;
  };
}

#endif
