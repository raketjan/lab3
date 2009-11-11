#include "trollkarl.h"

namespace advgame{

  Trollkarl::Trollkarl(int h,string namn) : Hero(h,namn)  {
  
  }
  
  Trollkarl::~Trollkarl() {}
  
  void Trollkarl::action() {
    // kolla vad sjutton man vill göra !
    // cout << "Trollkarl::action " << endl;
    cout << "Du är i " <<  getPlace()->getName() << endl;
    cout << getPlace()->getDescription() << endl;
    cout << "Du ser följande saker: ";
    for (vector<Item *>::const_iterator it = getPlace()->getStuff().begin();
	 it < getPlace()->getStuff().end();
	 ++it) {
      cout << (*it)->getName();
      if (it < getPlace()->getStuff().end() - 1) cout  << ", ";
    }
    cout << endl;
    cout << "Du ser följande dårar: ";
    for(vector<Actor *>::iterator it = getPlace()->getGubbar().begin();
	it!=getPlace()->getGubbar().end();
	++it) {
      if (*it != this) cout << (*it)->name();
      if (*it != this && it < getPlace()->getGubbar().end() -1) cout << ", ";
    }
    cout << endl;
    cout << "Vad vill du göra " << name() << " ? ";
    // Parser.parse(cin.getLine());

  }
  
  int Trollkarl::fight(Actor * motst) {
    
  }
  
  Item & Trollkarl::pick_up(Item * pryl) {
    
  }

  Item & Trollkarl::drop(Item * pryl) {
    
  }
  
  void Trollkarl::talk_to(Actor * pratkvarn) {
    
  }
}
