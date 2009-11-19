#ifndef __ITEM__
#define __ITEM__
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace advgame{
  class Item{
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
   };
  bool operator==(const string , const Item *);
  bool operator==(const Item *, const string);
}

#endif

