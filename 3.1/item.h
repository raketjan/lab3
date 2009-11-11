#ifndef __ITEM__
#define __ITEM__
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace advgame{
  class Item{
  private:
    int weight, price;
    string name;
    string description;
  public:
    
    Item(string,string,int,int);
    virtual ~Item();
    int getWeight() const;
    int getPrice() const;
    string getDescription() const;
    string getName() const;
   };
}

#endif

