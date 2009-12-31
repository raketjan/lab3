#include "worm.h"

namespace advgame{
  Worm::Worm(int h,string namn) : Monster(h,namn){
    
  }
  
  Worm::~Worm(){
  }

  void Worm::action(){
    //if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      map<string, Place *>::const_iterator it = getPlace()->getExits().begin();
      for (int i = 0; i < godirection; ++i) ++it;
      go(it->first);
      //}

  }
  void Worm::fight(string){
  }
  void Worm::talk_to(string){
  }
  string Worm::save(){
    return "XXX";
  }
}
