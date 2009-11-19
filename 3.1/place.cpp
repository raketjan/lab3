#include "place_actor.h"

namespace advgame{
  Place::Place(string n,string d):name(n),m_description(d)
  {
  }
  
  Place::~Place(){
  }
  
  void Place::setName(string n){
    name = name;
  }

  string Place::getName() const{
    return name;
  }
  void Place::setDescription(string d){
    m_description = d;
  }
  
  string Place::getDescription() const{
    return m_description;
  }
  void Place::setExit(string e,Place * p){
    exits[e]=p;
  }
  
  map<string,Place *> & Place::getExits(){
    return exits;
  }
  
  vector<Item *> & Place::getStuff(){
    return stuff;
  }
  
  void Place::addStuff(Item * i){
    stuff.push_back(i);
  }

  void Place::addGubbe(Actor* a) {
    gubbar.push_back(a);
  }

  vector<Actor *> & Place::getGubbar() {
    return gubbar;
  }

}
