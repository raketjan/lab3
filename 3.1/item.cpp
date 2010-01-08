#include "item.h"

namespace advgame{


  Item::Item(string namn, string beskrivning, int vikt, int pris):
    name(namn), description(beskrivning), weight(vikt), price(pris) {}

  Item::~Item() {
    //cout << "Item destruktor till: " << getName() << endl;
  }

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
  std::string Item::save(){
    return "XXX";
  }
  
  bool operator==(const string s, const Item * i2) {
    return s == i2->getName();
  }
  bool operator==(const Item * i1, const string s) {
  return s == i1->getName();
  }

}
