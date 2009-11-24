#include "monster.h"

namespace advgame{

  Monster::Monster(int h,string namn) : Npc(h,namn)  {
  }
  
  Monster::~Monster() {
    // ta bort ur listan med folk där han är
    
    cout << "ta bort ur platsen man är på" << endl;
    
    getPlace()->getGubbar().erase(find(getPlace()->getGubbar().begin(),
				       getPlace()->getGubbar().end(),
				       this)
				  );
    cout << "ta bort ur thingMap" << endl;
    getThingMap().erase(name());
    cout << "ta bort ur actors" << endl;
    
    getActors().erase(find(getActors().begin(),
			   getActors().end(),
			   this));
    cout << "tagit bort ur ~Monster, hoppar typ uppåt !" << endl;
    // ta bort ur itemMap
    
  }
  
  void Monster::action() {
    cout << "inne i monster::action" << endl;
    if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      map<string, Place *>::const_iterator it = getPlace()->getExits().begin();
      for (int i = 0; i < godirection; ++i) ++it;
      go(it->first);
    }
  }
  
  void Monster::fight(string motst) {
     cout << "inne i monster.fight() !!!" << endl;
    Actor * motstP; 
      for(vector<Actor *>::iterator it = getPlace()->getGubbar().begin();
	  it!=getPlace()->getGubbar().end();
	  ++it) {
	if (*it == motst) motstP = *it;
      }
 
  }
  
  void Monster::talk_to(string pratkvarn) {
    
  }
  
  string Monster::save(){
    
  }
}
