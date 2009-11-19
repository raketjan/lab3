#include "game.h"

namespace advgame{
  Game::Game():clock(1){
    //srand( time(NULL));   // for debugging    
    initActions();
    init();
  }
  
  void Game::initActions(){
    //void (Actor::*goPtr)( string ) = &Actor::go;
    actionMap["go"]=&Actor::go;
    actionMap["ta"]=&Actor::pick_up;
    actionMap["drop"]=&Actor::drop;
    actionMap["undersök"]=&Actor::examine;
  }
  
  void Game::init(){
    Place * vardagsrum = new Rum("vardagsrummet","Här chillar du och pillar naveln.");
    Place * sovrum = new Rum("sovrummet","Här ligger du ofta och snarkar.");
    Place * garderob = new Rum("garderoben","Här har du dina loppätna kläder.");
    Place * balkong = new Rum("balkongen","Här tjuvröker du.");
    vardagsrum->setExit("öst",sovrum);
    vardagsrum->setExit("in",garderob);
    garderob->setExit("ut",vardagsrum);
    sovrum->setExit("ut",balkong);
    sovrum->setExit("väst",vardagsrum);
    balkong->setExit("in",sovrum);
    Item * svard = new Item("svärd","Stick dom med den vassa änden.", 4,3);
    // itemMap.insert(svard->getName(), svard);
    sovrum->addStuff(svard);
    Container * pase = new Container("påse", "Den rymmer en massa härliga grejer!", 2, 10, 20);
    vardagsrum->addStuff(pase);
    // itemMap.insert(pase->getName(), pase);
  
    string namnet, beskrivningen;
    cout << "Vad ska du heta ?" << endl;
    cin >> namnet;
    Trollkarl * player = new Trollkarl(1000, namnet);
    player->setPlace(sovrum);
    actorMap[namnet] = player;
    //Skicka med actorMap här?
    //player->setActorMap(&actorMap)
    //Skicka med actionMap här?
    //player->setActionMap(&actionMap)
    
    Monster * argOrm = new Monster(1000, "Ormbengt");
    actorMap["Ormbengt"] = argOrm;
    argOrm->setPlace(sovrum);
    argOrm->pick_up("svärd");
    Monster * vildaPonnyn = new Monster(100, "Vildaponnyn");
    actorMap["Vildaponnyn"] = vildaPonnyn;
    vildaPonnyn->setPlace(vardagsrum);    
    actors.push_back(player);
    actors.push_back(argOrm);
    actors.push_back(vildaPonnyn);
  }
  
  void Game::getInput(){
    
  }
  
  void Game::loop(){
    while(true){
      cout << endl;
      cout << "------------------- Omgång " << clock << " ---------------" << endl;
      for(vector<Actor *>::iterator it = actors.begin();
	  it!=actors.end();
	  ++it) 
	{
	  cout << "----- " << (*it)->name() << "s tur -----" << endl;
	  (*it)->action();
	}
      ++clock;
    }
  }

  map<string, Item*> & Game::getItemMap() {
    return itemMap;
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
  

}

