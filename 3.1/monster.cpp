#include "monster.h"

namespace advgame{

  Monster::Monster(int h,string namn) : Npc(h,namn)  {
  }
  
  Monster::~Monster() {}
  
  void Monster::action() {
    if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      map<string, Place *>::const_iterator it = getPlace()->getExits().begin();
      for (int i = 0; i < godirection; ++i) ++it;
      go(it->first);
    }
  }
  
  int Monster::fight(Actor * motst) {
    
  }
  
  void Monster::talk_to(Actor * pratkvarn) {
    
  }
}
