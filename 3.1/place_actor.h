#ifndef __PLACE_ACTOR__
#define __PLACE_ACTOR__
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "item.h"

using namespace std;
namespace advgame{
  enum Direction{north,
		 east,
		 south,
		 west,
		 northeast,
		 southeast,
		 northwest,
		 southwest,
		 up,
		 down,
		 in,
		 out
  };
  class Actor;
  class Place{
    map<Direction,Place *> exits;
    string name;
    string m_description;
    vector<Item *> stuff;
    vector<Actor *> gubbar;
  public:
    Place(string, string);
    virtual ~Place();
    virtual Place & neighbour(Direction) = 0;
    virtual void enter(Actor *) = 0;
    virtual void leave(Actor *) = 0;
    virtual Item & pick_up(Item *)= 0;
    virtual Item & drop(Item *) = 0;
    void setName(string);
    string getName() const;
    void setExit(Direction e,Place * p);
    map<Direction,Place *> & getExits();
    void addGubbe(Actor*);
    vector<Actor *> & getGubbar();
    void setDescription(string);
    string getDescription() const;
    vector<Item *> & getStuff();
    void addStuff(Item *);
  };
  
  class Actor{
  private:
    string m_name;
    int hp;
    string m_type;
    vector<Item *> possessions;
    Place * whereAt;
   public:   
    Actor(int,string);
    string type();
    string name() const;
    Place * getPlace() const;
    void setPlace(Place *);
    void go(Direction);
    virtual void action()= 0;
    virtual int fight(Actor *) = 0;
    virtual Item& pick_up(Item *) = 0;
    virtual Item& drop(Item *) = 0;
    virtual void talk_to(Actor *) = 0;
    vector<Item *>& getPossessions();
    
  };
}

#endif

