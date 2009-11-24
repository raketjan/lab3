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
    virtual void fight(string) = 0;
    virtual void talk_to(string) = 0;
    virtual string save() = 0;
    virtual ~Npc();
  };
}

#endif
