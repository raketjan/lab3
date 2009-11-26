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
    map<string, Thing*> * thingMap;
  public:
    Trollkarl(int,string,Parser*, map<string, Thing *> *);
    virtual ~Trollkarl();
    virtual void action();
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
  };
}

#endif
 
