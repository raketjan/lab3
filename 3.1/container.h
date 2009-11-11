#ifndef __CONTAINER__
#define __CONTAINER__
#include <vector>
#include "item.h"
using namespace std;
namespace advgame{

  class Container : public Item{
  protected:
    int capacity;
    vector<Item *> stuff;
  public:
    Container(string,string,int,int,int);

    virtual ~Container();
    int get_weight_of_contents() const;
    int get_capacity() const;
    Item & add(Item&);
    Item & remove(Item&);
 
   };
}

#endif

