#ifndef __GAME__
#define __GAME__
#include "rum.h"
#include "place_actor.h"
#include "container.h"
#include "trollkarl.h"
#include "monster.h"
#include "location.h"
#include <vector>
#include <time.h>


using namespace std;
namespace advgame{
  class Game{
  private:
    vector<Place *> places;
    vector<Actor *> actors;
    /* or map? */
    string description;
    int clock;
    void getInput();
    void parse();
    void act();
    void init();
  public:
    void loop();
    Game();
    ~Game();
  };
}

#endif
