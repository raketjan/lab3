#ifndef __GAME__
#define __GAME__
#include "rum.h"
#include "place_actor.h"
#include "container.h"
#include "trollkarl.h"
#include "witch.h"
#include "monster.h"
#include "parser.h"
#include "thing.h"
#include "worm.h"
#include "hen.h"
#include <vector>
#include <time.h>


using namespace std;
namespace advgame{

  class Game{
  private:
    vector<Place *> places;
    vector<Actor *> * actors;
    /*Borde nog ersätta actors */

    map<string, Thing *> * thingMap;
    typedef void (Actor::*actorFuncP)(string);
    map<string, actorFuncP> * actorFuncMap;
    
    Trollkarl * player;
    Parser * parser;
    string description;
    int clock;
    void getInput();
    void parse();
    void act();
    void init();
    void initActions();
    void setDescription();
  public:
    void loop();
    Game();
    ~Game();
  };
}

#endif
