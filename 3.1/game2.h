#ifndef __GAME2__
#define __GAME2__
#include "rum.h"
#include "place_actor.h"
#include "container.h"
#include "trollkarl.h"
#include "monster.h"
#include "location.h"
#include "parser.h"
#include "thing.h"
#include "worm.h"
#include <vector>
#include <time.h>


using namespace std;
namespace advgame{

  class Game{
  private:
    vector<Place *> places;
    vector<Actor *> * actors;
    /*Borde nog ersätta sctors */

    map<string, Thing *> * thingMap;
    typedef void (Actor::*actorFuncP)(string);
    map<string, actorFuncP> * actorFuncMap;
    
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
    Game();
    ~Game();
  };
}

#endif
