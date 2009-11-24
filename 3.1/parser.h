#ifndef __PARSER__
#define __PARSER__
#include "place_actor.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "item.h"
#include "thing.h"


using namespace std;
namespace advgame{
  class Parser {
  public:  
    map<string,Thing *> * thingMap;
    typedef void (Actor::*actorFuncP)(string);
    map<string, actorFuncP> * actorFuncMap;
    void parse(Actor *);
  };
}
#endif
