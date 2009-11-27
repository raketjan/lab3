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
    Place * clearing = new Rum("dystra gläntan","En ödesmättad trolldimma ligger tät över denna plats.");
    (*thingMap)["dystra gläntan"] = clearing;
    Place * woods = new Rum("ödsliga skogen","Här bor ett otal rövare och djur och annat skumt.");
    (*thingMap)["ödsliga skogen"]=woods;
    Place * fields = new Rum("böljande fälten","Här odlas all mat i riket.");
    (*thingMap)["böljande fälten"]=fields;
    Place * beach = new Rum("fjärran stranden","Här blickar du ut över det oändliga söderhavet.");
    (*thingMap)["fjärran stranden"]=beach;
    Place * lobby = new Rum("slotts-lobbyn","I foajén till slottet.");
    (*thingMap)["lobbyn"]=lobby;
    Place * hall = new Rum("stora slottshallen","Här har det fina folket sina fester.");
    (*thingMap)["slottshall"]=hall;
    Place * dungeon = new Rum("fängelsehålan","Här låser kungen in sina värsta fiender.");
    (*thingMap)["fängelsehålan"]=dungeon;
    Place * tower = new Rum("uppe i tornet","Här kan du se ut över hela riket.");
    (*thingMap)["tornet"]=tower;
    clearing->setExit("väst",woods);
    woods->setExit("öst",clearing);
    woods->setExit("söder",beach);
    woods->setExit("väst",fields);
    beach->setExit("norr",woods);
    fields->setExit("in",lobby);
    fields->setExit("öst", woods);
    dungeon->setExit("upp", lobby);
    lobby->setExit("ner", dungeon);
    lobby->setExit("upp", tower);
    lobby->setExit("norr", hall);
    tower->setExit("ner", lobby);
    hall->setExit("south", lobby);
    Item * svard = new Item("svärd","Stick dom med den vassa änden.", 4,3);
    (*thingMap)["svärd"]=svard;
    beach->addStuff(svard);
    Container * pase = new Container("påse", "Den rymmer en massa härliga grejer!", 2, 10, 20);
    (*thingMap)["påse"]=pase;
    clearing->addStuff(pase);
    string namnet, beskrivningen;
    cout << "Vad ska du heta ?" << endl;
    cin >> namnet;
    Trollkarl * player = new Trollkarl(50, namnet, parser, thingMap);
    (*thingMap)[namnet]=player;
    player->setPlace(woods);
    player->setActors(actors);    
    Worm * argOrm = new Worm(50, "Ormbengt");
    (*thingMap)["Ormbengt"]=argOrm;
    argOrm->setThingMap(thingMap);
    argOrm->setActors(actors);
    argOrm->setPlace(woods);
   
    Monster * witch = new Monster(50, "häxan");
    witch->setThingMap(thingMap);
    (*thingMap)["häxan"]=witch;
    witch->setActors(actors);
    witch->setPlace(clearing);
    actors->push_back(player);
    actors->push_back(witch);
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
