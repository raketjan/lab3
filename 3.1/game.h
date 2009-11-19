#ifndef __GAME__
#define __GAME__
#include "rum.h"
#include "place_actor.h"
#include "container.h"
#include "trollkarl.h"
#include "monster.h"
#include "location.h"
#include "parser.h"
#include <vector>
#include <time.h>

using namespace std;
namespace advgame{
  class Game{
  private:
    vector<Place *> places;
    vector<Actor *> actors;
    /*Borde nog ersätta sctors */
    map<string,Actor *> actorMap;
    map<string, Item *> itemMap;
    typedef void (Actor::*actorFuncP)(string);
    map<string, actorFuncP> actionMap;
    
    /* or map? */
    Parser * parser;
    string description;
    int clock;
    void getInput();
    void parse();
    void act();
    void init();
    void initActions();
  public:
    void loop();
    map<string, Item*> & getItemMap();
    Game();
    ~Game();
  };
}

#endif
