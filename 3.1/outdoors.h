#ifndef __OUTDOORS__
#define __OUTDOORS__

#include <vector>
#include "place_actor.h"

using namespace std;
namespace advgame{
  
  class Outdoors : public Place{
  public:
    Outdoors(string, string);
    virtual ~Outdoors();
    virtual string save() = 0;
    void action(string);
  };
}

#endif
