#include "trollkarl.h"

namespace advgame{
  /* 
     Trollkarl måste ha tillgång till 
     Actions och actorsmappen
  */
  Trollkarl::Trollkarl(int h,string namn) : Hero(h,namn){
    parser = new Parser();
    // hur skall dett gå till
    //parser->setActorMap(...);
    //parser->setActionMap(...);
  }
  
  Trollkarl::~Trollkarl() {}
  
  void Trollkarl::action() {
    cout << "Du är i " <<  getPlace()->getName() << endl;
    cout << getPlace()->getDescription() << endl;
    if(getPlace()->getStuff().size() > 0){
      cout << "Du ser följande saker: ";
      for (vector<Item *>::const_iterator it = getPlace()->getStuff().begin();
	   it < getPlace()->getStuff().end();
	   ++it) {
	cout << (*it)->getName();
	if (it < getPlace()->getStuff().end() - 1) cout  << ", ";
      }
      cout << endl;
    }
    // Dont count yourself 
    if(getPlace()->getGubbar().size() > 1){
      cout << "Du ser följande dårar: ";
      for(vector<Actor *>::iterator it = getPlace()->getGubbar().begin();
	  it!=getPlace()->getGubbar().end();
	  ++it){
	if (*it != this) cout << (*it)->name();
	if (*it != this && it < getPlace()->getGubbar().end() -1) cout << ", ";
      }
      cout << endl;
    }
    cout << "Du kan gå åt följande håll: ";
    for(map<string,Place *>::iterator it = getPlace()->getExits().begin();
	it!=getPlace()->getExits().end();
	++it) {
      cout << it->first << ", ";
      //if (it  < getPlace()->getExits().end()) cout << ", ";
    }
    cout << endl;
    cout << "Vad vill du göra ?   ";
    //parser->parse(name());
    parser->parse(this);
  }
  
  int Trollkarl::fight(Actor * motst) {
    
  }
  
  void Trollkarl::talk_to(Actor * pratkvarn) {

    
  }
}
