#include "worm.h"

namespace advgame{
  Worm::Worm(int h,string namn) : Monster(h,namn){
    
  }
  Worm::~Worm(){
    cout << "destr" << endl;
    string n1 = name() + "shuvud";
    string n2 = name() + "ssvans";
    cout << "Skapar: " << n1 << " & " << n2 << endl;
    Worm * w1 = new Worm(100,n1);
    Worm * w2 = new Worm(100,n2);
    w1->setPlace(getPlace());
    w2->setPlace(getPlace());
    getThingMap()[n1] = w1;
    getThingMap()[n2] = w2;
    w1->setThingMap(&getThingMap());
    w2->setThingMap(&getThingMap());
    getActors().push_back(w1);
    getActors().push_back(w2);
    
  }

  void Worm::action(){
    cout << "Inne i worm::action !!!" << endl;
    //if (rand() % 2 == 0) {
      int godirection = rand() % getPlace()->getExits().size();
      map<string, Place *>::const_iterator it = getPlace()->getExits().begin();
      for (int i = 0; i < godirection; ++i) ++it;
      go(it->first);
      //}
    cout << "Klar med worm::action !!!" << endl;
  }
  void Worm::fight(string){
  }
  void Worm::talk_to(string){
  }
  string Worm::save(){

  }
}
