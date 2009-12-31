#include "trollkarl.h"

namespace advgame{
  /* 
     Trollkarl måste ha tillgång till 
     Actions och actorsmappen
  */
  Trollkarl::Trollkarl(int h,string namn, Parser * p, map<string, Thing*> * thMap) : Hero(h,namn), parser(p), thingMap(thMap){
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
    parser->parse(this);
    //getGame->parser->parse(this);
  }
  
  void Trollkarl::fight(string motst){

    Actor * motstP;
    Thing * tmp = (*thingMap)[motst];
    motstP = dynamic_cast<Actor *>(tmp);
    // har jag ett vapen ?
    string tjo = "svärd";
    vector<Item *>::iterator it = find(getPossessions().begin(),getPossessions().end(),tjo);
    if (it != getPossessions().end()){
      motstP->setHp(motstP->getHp() - 100);
      if (Worm * ormP = dynamic_cast<Worm *> (motstP)) {
	//cout << "OK " << endl;
	string n1 = motstP->name() + "shuvud";
	string n2 = motstP->name() + "ssvans";
	Worm * w1 = new Worm(100,n1);
	Worm * w2 = new Worm(100,n2);
	w1->setPlace(getPlace());
	w2->setPlace(getPlace());
	(*thingMap)[n1] = w1;
	(*thingMap)[n2] = w2;
	w1->setThingMap(thingMap);
	w2->setThingMap(thingMap);
	getActors().push_back(w1);
	getActors().push_back(w2);
	w1->setActors(&getActors());
	w2->setActors(&getActors());
	w1->setPlayer(getPlayer());
	w2->setPlayer(getPlayer());
      }            
    }else{ 
      motstP->setHp(motstP->getHp() - 50);
    }
    cout << motst << " har nu " << motstP->getHp() << " hitpoints !" << endl;
    
  }
  
  void Trollkarl::go(string d) {
    if (d == "in" && getPlace()->getName() == "böljande fälten") {
      string s("nyckeln");
      if (find(getPossessions().begin(),getPossessions().end(),s) == getPossessions().end()) {
	cout << "Du måste ha en nyckel för att komma in här." << endl;
	return;
      }
    } 
    map<string, Place *>::iterator it = getPlace()->getExits().find(d);
    if(it != getPlace()->getExits().end()){
      
      getPlace()->getGubbar().erase(find(getPlace()->getGubbar().begin(),getPlace()->getGubbar().end(), name()));
      setPlace(it->second);
      getPlace()->addGubbe(this);
      
    }else{
      cout << "Kan inte gå ditåt" << endl;
    }
  }
    
    

  void Trollkarl::talk_to(string pratkvarn){
  }

  void Trollkarl::give(string tillvem){
    //cout << "inne i trollkarl::gebortnåt" << endl;
    if (tillvem == "häxan") {
      // kolla att vi är på samma plats...
      
      if (find(getPlace()->getGubbar().begin(),
	       getPlace()->getGubbar().end(),
	       tillvem) != getPlace()->getGubbar().end() ) {
	string f = "frukostägg";
	if (find(getPossessions().begin(),
		 getPossessions().end(),
		 f) != getPossessions().end()) {
	  cout << "Du ger häxan det goda ägget. Hon blir så lycklig att hon ger dig nyckeln till slottet !" << endl;
	  Item * nyck = new Item("nyckeln", "en nyckel till slottet", 5,10);
	  getThingMap()["nyckeln"] = nyck;
	  getPossessions().push_back(nyck);
	} else {
	  cout << "Du har inget häxan vill ha !" << endl;
	}
      } else {
	cout << "Du ser ingen häxa." << endl;
      }
    }
    else {
      cout << "Finns ingen här som är intresserad av att prata med dig" << endl;
    }
  }

  string Trollkarl::save(){
    return "XXX";
  }
}
