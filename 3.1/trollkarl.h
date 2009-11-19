#ifndef __TROLLKARL__
#define __TROLLKARL__
#include <vector>
#include "hero.h"
#include "place_actor.h"
#include "item.h"
#include "parser.h"

using namespace std;
namespace advgame{
  class Trollkarl : public Hero{
  private: Parser * parser;
    
  public:
    Trollkarl(int,string);
    virtual ~Trollkarl();
    virtual void action();
    virtual int fight(Actor *);
    virtual void talk_to(Actor *);
  };
}

#endif
 
