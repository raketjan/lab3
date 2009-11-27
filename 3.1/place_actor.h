#ifndef __PLACE_ACTOR__
#define __PLACE_ACTOR__
#include <typeinfo>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>
#include "item.h"
#include "thing.h"
#include <algorithm>
using namespace std;
namespace advgame{
  class Actor;
  class Place : public Thing{
  
    map<string,Place *> exits;
    string name;
    string m_description;   
    vector<Item *> stuff;
    vector<Actor *> gubbar;
  public:
    Place(string, string);
    virtual ~Place();
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
    virtual string save() = 0;
  };
  
  class Actor : public Thing{
  private:
    Actor * player;
    int hp;    
    string m_name;
    string m_type;
    vector<Item *> possessions;
    Place * whereAt;
    map<string, Thing *> * thingMap;
    vector<Actor*> *actors;
  public:
    Actor(int,string);
    void setThingMap( map<string, Thing *>*);
    map<string, Thing *> & getThingMap();
    void setActors( vector<Actor *>*);
    vector<Actor*> & getActors();
    virtual ~Actor();
    string type();
    string name() const;
    Place * getPlace() const;
    void setPlace(Place *);
    int getHp()const;
    void setHp(int);
    void go(string);
    virtual void action()= 0;
    virtual void fight(string) = 0;
    void pick_up(string);
    void drop(string);
    void examine(string);
    virtual void give(string) = 0;
    virtual void talk_to(string) = 0;
    vector<Item *>& getPossessions();
    Actor* getPlayer();
    void setPlayer(Actor *);     

  public:
    virtual string save() = 0;
  };

  bool operator==(const string , const Actor *);
  bool operator==(const Actor *, const string);

}
#endif
