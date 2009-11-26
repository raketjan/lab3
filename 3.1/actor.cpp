#include "place_actor.h"

namespace advgame{
  Actor::Actor(int h,string namn):
    Thing(),hp(h),m_name(namn){
    
  }
  /* Remove from all containers */
  Actor::~Actor(){
    for(vector<Item *>::iterator it = possessions.begin();
	it!=possessions.end();
	++it){
      getPlace()->getStuff().push_back(*it);
    }

    cout << name() << " s destruktor" << endl;
    getPlace()->getGubbar().erase(find(getPlace()->getGubbar().begin(),
				       getPlace()->getGubbar().end(),
				       this)
				  );
    getThingMap().erase(name());
    getActors().erase(find(getActors().begin(),
			   getActors().end(),
			   this));
    cout << " kom igenom hela ~actor" << endl;
  }
  void Actor::setThingMap( map<string, Thing *>* tm){
    thingMap=tm;
  }
  map<string, Thing *> & Actor::getThingMap(){
    return *thingMap;
  }
  void Actor::setActors(vector<Actor *>*a){
    actors = a;
  }
  vector<Actor*> & Actor::getActors(){
    return *actors;
  }
    
  string Actor::name() const {
    return m_name;
  }
  
  void Actor::go(string d){
    int minpos;
    for(int i= 0; i<whereAt->getGubbar().size();++i){
      if(name()==whereAt->getGubbar()[i]->name()){
	minpos=i;
      }
    }
    
    map<string, Place *>::iterator it = whereAt->getExits().find(d);
    if(it != whereAt->getExits().end()){
   
      whereAt->getGubbar().erase(whereAt->getGubbar().begin()+minpos);
      whereAt = it->second;
      whereAt->addGubbe(this);
      
    }else{
      cout << "Kan inte gå ditåt" << endl;
    }
   
  }
  
  Place * Actor::getPlace() const {
    return whereAt;
  }
  
  void Actor::setPlace(Place * p) {
    p->addGubbe(this);
    whereAt = p;
  }

  vector<Item *>& Actor::getPossessions(){
    return possessions;
  }

  void Actor::setHp(int s){
    hp = s;
  }

  int Actor::getHp() const{
    return hp;
  }

  void Actor::pick_up(string s) {
    cout << name() << " försöker ta upp " << s << endl;

    vector<Item *>::iterator it = find(whereAt->getStuff().begin(),whereAt->getStuff().end(),s);

    if(it != whereAt->getStuff().end()) {
      cout << name() << " tar upp " << s << endl;
      possessions.push_back(*it);
      whereAt->getStuff().erase(it);
    
    }else{
      cout << "Du ser inte nån " << s << endl;      
    }
  }

  void Actor::drop(string s){
    cout << name() << " försöker slänga iväg " << s << endl;
    vector<Item *>::iterator it = find(getPossessions().begin(),getPossessions().end(),s);
    if(it != getPossessions().end()) {
      cout << name() << " släng iväg (dock i samma rum) " << s << endl; 
      whereAt->getStuff().push_back(*it);     
      possessions.erase(it);
    }else{
      cout << "Du har ju ingen " << s << " för fan. Idiot!" << endl;      
    }
    
  }

  void Actor::examine(string s) {
    cout << name() << " försöker undersöka " << s << endl;
    // Bär jag den själv ?
    vector<Item *>::iterator it1 = find(getPossessions().begin(),getPossessions().end(),s);
    vector<Item *>::iterator it2 = find(whereAt->getStuff().begin(),whereAt->getStuff().end(),s);
    if(it1 != getPossessions().end()) {
      cout << name() << " Jag hade den ! " << s << endl; 
      cout << (*it1)->getDescription() << endl;
    } else if (it2 != whereAt->getStuff().end()) {
      cout << name() << " Den fanns här på denna plats" << s << endl;
      cout << (*it2)->getDescription() << endl;
   
    
    } else cout << "Du ser inte nån " << s << " här !!!" << endl;
  }     

  bool operator==(const string s, const Actor * a2) {
    return s == a2->name();
  }

  bool operator==(const Actor * a1, const string s) {
    return s == a1->name();
  }

}
