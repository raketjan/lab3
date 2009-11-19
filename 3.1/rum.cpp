#include "rum.h"

namespace advgame{
  Rum::Rum(string n, string d):
    Indoors(n,d)
  {
  }
  
  Rum::~Rum(){}
  
  Place & Rum::neighbour(string direction) {
  }
  
  void Rum::enter(Actor *) {
  }
  
  void Rum::leave(Actor *) {
  }
  
  Item & Rum::pick_up(Item *) {
  }
  
  Item & Rum::drop(Item *) {
  }
  
}
