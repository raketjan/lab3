#include "game.h"

namespace advgame{
  Game::Game(){
    // srand( time(NULL));   // for debugging    
    init();
   
  }

  Game::~Game(){
    /*
    for(vector<Place *>::iterator it = places.begin();
	it!=places.end();
	++it){
      // fel att delete  *it?
      for(vector<Item *>::iterator it2 = (*it)->getStuff().begin();
	  it2!=((*it)->getStuff()).end();
	  ++it2){
	delete *it2;
      }
      delete *it;
    }
    
    for(vector<Actor *>::iterator it = actors.begin();
	it!=actors.end();
	++it){
      // fel att delete  *it?
      for(vector<Item *>::iterator it2 = (*it)->getPossessions().begin();
	  it2!=((*it)->getPossessions()).end();
	  ++it2){
	delete *it2;
      }
      delete *it;
    }
    */
  }
  
  void Game::init(){
    Place * livingroom = new Rum("vardagsrummet","Här chillar du och pillar naveln.");
    Place * bedroom = new Rum("sovrummet","Här ligger du ofta och snarkar.");
    livingroom->setExit(east,bedroom);
    bedroom->setExit(west,livingroom);
    Item * sword = new Item("ett svärd","Stick dom med den vassa änden.", 4,3);
    bedroom->addStuff(sword);
    Container * bag = new Container("en påse", "Den rymmer en massa härliga grejer!", 2, 10, 20);
    livingroom->addStuff(bag);
  
 
    string namnet, beskrivningen;
    cout << "Vad ska du heta ?" << endl;
    cin >> namnet;
    Trollkarl * player = new Trollkarl(1000, namnet);
    player->setPlace(bedroom);
    
    
    Monster * argOrm = new Monster(1000, "Bengt, den arga ormen");
    argOrm->setPlace(bedroom);
    argOrm->pick_up(sword);
    Monster * vildaPonnyn = new Monster(100, "Siv, den vilda ponnyn");
    vildaPonnyn->setPlace(livingroom);
    
    actors.push_back(player);
    actors.push_back(argOrm);
    actors.push_back(vildaPonnyn);
    
  }
  
  void Game::getInput(){
    
  }
  
  void Game::loop(){
    for(vector<Actor *>::iterator it = actors.begin();
	it!=actors.end();
	++it) {
      // cout << (*it)->name() << endl;
      (*it)->action();
    }
  }
   
}

