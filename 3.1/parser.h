#ifndef __PARSER__
#define __PARSER__
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "item.h"
#include "place_actor.h"

using namespace std;
namespace advgame{
  class Parser {
    map<string,Actor *>  actorMap;
    typedef void (Actor::*actorFuncP)(string);
    map<string, actorFuncP>  actionMap;
  public:
    void parse(Actor *);
  };
}
#endif
