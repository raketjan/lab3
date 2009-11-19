#ifndef __PLACE_ACTOR__
#define __PLACE_ACTOR__
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "item.h"
#include <algorithm>
using namespace std;
namespace advgame{

  class Actor;
  class Place{
    map<string,Place *> exits;
    string name;    
    string m_description;
    
    vector<Item *> stuff;
    vector<Actor *> gubbar;
  public:
    Place(string, string);
    virtual ~Place();
    virtual Place & neighbour(string) = 0;
    virtual void enter(Actor *) = 0;
    virtual void leave(Actor *) = 0;
    void pick_up(Item *);
    void drop(Item *);
    void setName(string);
    string getName() const;
    void setExit(string e,Place * p);
    map<string,Place *> & getExits();
    void addGubbe(Actor*);
    vector<Actor *> & getGubbar();
    void setDescription(string);
    string getDescription() const;
    vector<Item *> & getStuff();
    void addStuff(Item *);
    
  };
  
  class Actor{
  private:
    int strength;
    int hp;    
    string m_name;
    string m_type;
    vector<Item *> possessions;
    Place * whereAt;
  public:   
    Actor(int,string);
    string type();
    string name() const;
    Place * getPlace() const;
    void setPlace(Place *);
    int getStrength()const;
    void setStrength(int);
    void go(string);
    virtual void action()= 0;
    virtual int fight(Actor *) = 0;
    void pick_up(string);
    void drop(string);
    void examine(string);
    virtual void talk_to(Actor *) = 0;
    vector<Item *>& getPossessions();
    
  };
}

#endif

