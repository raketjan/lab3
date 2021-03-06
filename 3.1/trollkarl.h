#ifndef __TROLLKARL__
#define __TROLLKARL__
#include <vector>
#include "hero.h"
#include "place_actor.h"
#include "item.h"
#include "parser.h"
#include "worm.h"
using namespace std;
namespace advgame{
  class Trollkarl : public Hero{
  private: Parser * parser;
    map<string, Thing*> * thingMap;
  public:
    Trollkarl(int,string,Parser*, map<string, Thing *> *);
    virtual ~Trollkarl();
    virtual void action();
    void go(string);
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
    virtual void give(string);
  };
}

#endif
 
