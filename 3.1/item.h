#ifndef __ITEM__
#define __ITEM__
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "thing.h"
using namespace std;
namespace advgame{
  class Item : public Thing{
  private:
    string name; 
    string description;
    int weight;
    int price;
   public:
    Item(string,string,int,int);
    virtual ~Item();
    int getWeight() const;
    int getPrice() const;
    string getDescription() const;
    string getName() const;
    virtual string save();
   };
  bool operator==(const string , const Item *);
  bool operator==(const Item *, const string);
}

#endif

