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
    virtual void fight(string) = 0;
    virtual void talk_to(string) = 0;
    virtual string save() = 0;
    virtual ~Hero();
  };
}

#endif
