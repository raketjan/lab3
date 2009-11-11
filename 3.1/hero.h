#ifndef __HERO__
#define __HERO__
#include <vector>
#include "place_actor.h"
using namespace std;
namespace advgame{
  class Hero : public Actor{
    int fp;  // förmågepoäng
  public:
    Hero(int,string);
    virtual void action() = 0;
    virtual int fight(Actor *) = 0;
    virtual Item& pick_up(Item *) = 0;
    virtual Item& drop(Item *) = 0;
    virtual void talk_to(Actor *) = 0;
  };
}

#endif
