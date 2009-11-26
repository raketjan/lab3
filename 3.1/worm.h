#ifndef __WORM__
#define __WORM__
#include <vector>
#include "place_actor.h"
#include "monster.h"
using namespace std;
namespace advgame{
  class Worm : public Monster{
  public:
    Worm(int,string);
    virtual void action();
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
    virtual ~Worm();
  };
}

#endif
