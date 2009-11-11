#ifndef __TROLLKARL__
#define __TROLLKARL__
#include <vector>
#include "hero.h"
#include "place_actor.h"
#include "item.h"
using namespace std;
namespace advgame{
  class Trollkarl : public Hero{
  public:
    Trollkarl(int,string);
    virtual ~Trollkarl();
    virtual void action();
    virtual int fight(Actor *);
    virtual Item& pick_up(Item *);
    virtual Item& drop(Item *);
    virtual void talk_to(Actor *);
  };
}

#endif
 
