#ifndef __INDOORS__
#define __INDOORS__

#include <vector>
#include "place_actor.h"

using namespace std;
namespace advgame{
  
  class Indoors : public Place{
  public:
    Indoors(string, string);
    virtual ~Indoors();
    virtual string save() = 0;
  };
}

#endif
