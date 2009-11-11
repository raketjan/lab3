#include "place_actor.h"

namespace advgame{
  Actor::Actor(int h,string namn):
    hp(h),m_name(namn){
  }

  string Actor::name() const {
    return m_name;
  }
    
  void Actor::go(Direction d){
    whereAt->getGubbar();
    map<Direction, Place *>::iterator it = whereAt->getExits().find(d);
    whereAt = it->second;
    whereAt->addGubbe(this);
  }
  
  Place * Actor::getPlace() const {
    return whereAt;
  }
  
  void Actor::setPlace(Place * p) {
    p->addGubbe(this);
    whereAt = p;
    return;
  }

  vector<Item *>& Actor::getPossessions(){
    return possessions;
  }
}
