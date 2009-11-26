#include "game.h"

namespace advgame{
  Game::Game():clock(1){
    //srand( time(NULL));   // for debugging    
    actors = new vector<Actor *>;
    parser = new Parser();
    thingMap = new map<string, Thing *>();
    actorFuncMap = new map<string, actorFuncP>();
    (*actorFuncMap)["gå"]=&Actor::go;
    (*actorFuncMap)["ta"]=&Actor::pick_up;
    (*actorFuncMap)["släng"]=&Actor::drop;
    (*actorFuncMap)["undersök"]=&Actor::examine;
    (*actorFuncMap)["anfall"]=&Actor::fight;
    parser->thingMap = thingMap;
    parser->actorFuncMap = actorFuncMap;
    initActions();
    init();
  }
  
  void Game::initActions(){
  }
  
  void Game::init(){
    Place * vardagsrum = new Rum("vardagsrummet","Här chillar du och pillar naveln.");
    (*thingMap)["vardagsrummet"] = vardagsrum;
    Place * sovrum = new Rum("sovrummet","Här ligger du ofta och snarkar.");
    (*thingMap)["sovrummet"]=sovrum;
    Place * garderob = new Rum("garderoben","Här har du dina loppätna kläder.");
    (*thingMap)["garderoben"]=garderob;
    Place * balkong = new Rum("balkongen","Här tjuvröker du.");
    (*thingMap)["balkongen"]=balkong;
    vardagsrum->setExit("öst",sovrum);
    vardagsrum->setExit("in",garderob);
    garderob->setExit("ut",vardagsrum);
    sovrum->setExit("ut",balkong);
    sovrum->setExit("väst",vardagsrum);
    balkong->setExit("in",sovrum);
    Item * svard = new Item("svärd","Stick dom med den vassa änden.", 4,3);
    (*thingMap)["svärd"]=svard;
    sovrum->addStuff(svard);
    Container * pase = new Container("påse", "Den rymmer en massa härliga grejer!", 2, 10, 20);
    (*thingMap)["påse"]=pase;
    vardagsrum->addStuff(pase);
    string namnet, beskrivningen;
    cout << "Vad ska du heta ?" << endl;
    cin >> namnet;
    Trollkarl * player = new Trollkarl(50, namnet, parser, thingMap);
    (*thingMap)[namnet]=player;
    player->setPlace(sovrum);
    player->setActors(actors);    
    Worm * argOrm = new Worm(50, "Ormbengt");
    (*thingMap)["Ormbengt"]=argOrm;
    argOrm->setThingMap(thingMap);
    argOrm->setActors(actors);
    argOrm->setPlace(sovrum);
    argOrm->pick_up("svärd");    
    Monster * vildaPonnyn = new Monster(50, "Vildaponnyn");
    vildaPonnyn->setThingMap(thingMap);
    (*thingMap)["Vildaponnyn"]=vildaPonnyn;
    vildaPonnyn->setActors(actors);
    vildaPonnyn->setPlace(vardagsrum);
    actors->push_back(player);
    actors->push_back(vildaPonnyn);
    actors->push_back(argOrm);
  }
  
  void Game::getInput(){
    
  }
  
  void Game::loop(){
    while(true){
      cout << endl;
      cout << "------------------- Omgång " << clock << " ---------------" << endl;
      for(size_t i =0;i<actors->size();++i){
	cout << "spelare " << i <<  "s tur" << endl;
	if((*actors)[i]->getHp() <=0 ) {
	  cout << "delete " << (*actors)[i]->name()<< endl;
	  delete (*actors)[i];
	}else{
	  (*actors)[i]->action();
	}
      }
      ++clock;
    }
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

