#include "witch.h"

namespace advgame{

  Witch::Witch(int h,string namn) : Npc(h,namn)  {
  }

  Witch::~Witch() {

  }
  
  void Witch::action() {
    cout << "inne i witch::action" << endl;
    if(find(getPlace()->getGubbar().begin(),
	    getPlace()->getGubbar().end(),
	    getPlayer()) != getPlace()->getGubbar().end());
    int r =rand()%5;
    if (r == 0) {
      cout << "Häxan står och kokar giftte." << endl;
    }
    if (r == 1) {
      cout << "Häxan äter några barn." << endl;
    }
    if (r == 2) {
      cout << "Häxan säger: Om jag bara kunde göra en fladdermusomelett !" << endl;
    }
    if (r == 3) {
      cout << "Häxan sjunger en läskig sång om ormar." << endl;
    }
    
  }
    
  void Witch::fight(string motst) {
      
  }
  
  void Witch::talk_to(string pratkvarn) {
  }

  string Witch::save(){
    return "XXX";
  }
  void Witch::give(string s) {
  }
}
