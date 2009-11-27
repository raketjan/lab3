#ifndef __HEN__
#define __HEN__
#include <vector>
#include "npc.h"
#include "place_actor.h"
#include "item.h"
using namespace std;
namespace advgame{
  class Hen : public Npc{
  private:
    int eggs;
    string egg [3];
    string eggdescription [3];

  public:
    Hen(int,string);
    virtual ~Hen();
    virtual void action();
    virtual void fight(string);
    virtual void talk_to(string);
    virtual string save();
    virtual void give(string);   
  };
}

#endif
 
