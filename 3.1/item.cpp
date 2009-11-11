#include "item.h"

namespace advgame{


Item::Item(string namn, string beskrivning, int vikt, int pris) : 
  name(namn), description(beskrivning), weight(vikt), price(pris) {}

  Item::~Item() {}

int Item::getWeight() const {
  return weight;
}

int Item::getPrice() const {
  return price;
}

std::string Item::getDescription() const {
  return description;
}

std::string Item::getName() const {
  return name;
}
}
