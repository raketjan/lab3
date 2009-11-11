#include "monster.h"

namespace advgame{

  Monster::Monster(int h,string namn) : Npc(h,namn)  {
  
  }
  
  Monster::~Monster() {}
  
  void Monster::action() {
    /*if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      go(getPlace()->getExits()[godirection]);
      }*/
    //go(west);
      
  }
  
  int Monster::fight(Actor * motst) {
    
  }
  
  Item & Monster::pick_up(Item * pryl) {
    
  }

  Item & Monster::drop(Item * pryl) {
    
  }
  
  void Monster::talk_to(Actor * pratkvarn) {
    
  }
}
