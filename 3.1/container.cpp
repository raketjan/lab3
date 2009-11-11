#include "container.h"
namespace advgame{

Container::Container(std::string namn, std::string beskrivning, int vikt, int pris, int kapacitet) : 
  Item(namn,beskrivning,vikt,pris), capacity(kapacitet), stuff(*(new vector<Item*>()) ) 
{}
  
  Container::~Container() {}   // ta hand om prylarna i när den pajar...

int Container::get_weight_of_contents() const {
  return 1;  // gå igenom innehållet och kolla vikten...
}

int Container::get_capacity() const {
  return capacity;
}

Item & Container::add(Item& i) {
  return i;
}

Item & Container::remove(Item& i) {
  return i;
}

}
