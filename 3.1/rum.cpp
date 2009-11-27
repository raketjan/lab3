#include "rum.h"

namespace advgame{
  Rum::Rum(string n, string d):
    Indoors(n,d)
  {
  }
  
  Rum::~Rum(){}
  
  string Rum::save(){
    return "save rum";
  }  
}
