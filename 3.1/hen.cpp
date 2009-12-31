#include "hen.h"

namespace advgame{

  Hen::Hen(int h,string namn) : 
    Npc(h,namn),
    eggs(3)
  {}


  Hen::~Hen() {

  }
  
  void Hen::action() {

    if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      map<string, Place *>::const_iterator it = getPlace()->getExits().begin();
      for (int i = 0; i < godirection; ++i) ++it;
      go(it->first);
      
    }
    if (rand() % 3 == 0 ) {
      // gör ett ägg
      if (eggs == 3) {
      Item * egg = new Item("frukostägg","ett smaskigt gott läckert ägg",10,10);
	getPlace()->addStuff(egg);
	getThingMap()["frukostägg"]=egg;

      }
      if (eggs == 2) {
	Item * egg = new Item("silverägg","ett skinande finfint ägg",20,100);
	getPlace()->getStuff().push_back(egg);
	getThingMap()["silverägg"]=egg;
      }
      if (eggs == 1) {
      Item * egg = new Item("guldägg","ett gyllene stiligt ägg",30,1000);
	getPlace()->getStuff().push_back(egg);
	getThingMap()["guldägg"]=egg;
      }
      --eggs;
    }
  }
  
  void Hen::fight(string motst) {
     }
  
  void Hen::talk_to(string pratkvarn) {
    
  }

  void Hen::give(string mottagare) {
    
  }
  
  string Hen::save(){
    return "XXX";
  }
}
