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
    (*actorFuncMap)["ge"]=&Actor::give;
    parser->thingMap = thingMap;
    parser->actorFuncMap = actorFuncMap;
    setDescription();
    initActions();
    init();
  }
  
  void Game::initActions(){
  }

  void Game::setDescription(){
    description = 
      "Välkommen till Supergame ! \n"
      "Din käresta har fångats av den lömske kungen och hans ormformade underhuggare.\n"
      "Finn ett sätt att ta dig in i slottet, och undvik de lömska ormarna i möjligaste mån.\n" 
      "Du måste skriva två ord, där det första är något av följande: gå, ta, släng, undersök, anfall, ge, t.ex gå väst, ge häxan.\n";
  }

  
  void Game::init(){
    cout << description << endl;
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
    Place * tower = new Rum("tornet","Här kan du se ut över hela riket.");
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
    player = new Trollkarl(50, namnet, parser, thingMap);
    (*thingMap)[namnet]=player;
    player->setPlace(beach);
    player->setActors(actors);
    player->setThingMap(thingMap);    
    Worm * argOrm = new Worm(50, "Ormbengt");
    (*thingMap)["Ormbengt"]=argOrm;
    argOrm->setThingMap(thingMap);
    argOrm->setActors(actors);
    argOrm->setPlace(woods);
    Hen * hen = new Hen(10,"hönan");
    (*thingMap)["hönan"] = hen;
    hen->setThingMap(thingMap);
    hen->setActors(actors);
    hen->setPlace(woods);
   
    Witch * witch = new Witch(100050, "häxan");
    (*thingMap)["häxan"]=witch;

    witch->setPlace(clearing);
    witch->setActors(actors);
    witch->setThingMap(thingMap);
    // fel på clearing, beach, fields, dungeon!
    // funkar med woods, lobby, 

    actors->push_back(player);
    actors->push_back(witch);
    actors->push_back(argOrm);
    actors->push_back(hen);
    witch->setPlayer(player);
    argOrm->setPlayer(player);
    player->setPlayer(player);  // !!!
    hen->setPlayer(player);

  }
  
  void Game::getInput(){
    
  }
  
  void Game::loop(){
    while(true){

      if (clock == 30) {
	cout << "Du känner att det samlas lite vatten i ditt knä." << endl;
      }
      if (clock == 40) {
	cout << "Det börjar mullra lite i skyn..." << endl;
      }
      if (clock == 50) {
	cout << "Åskan slår ner i huvet på dig. Skynda dig lite mer med att rädda prinsessan nästa gång, sölkorv !" << endl;
	return;
      }
      //cout << player->getPlace()->getName() << endl;
      if (player->getPlace()->getName() == "tornet") {
	cout << "Du har hittat prinsessan ! Hurra, nu ska ni leva lyckliga resten av era liv !!!" << endl;
	return;
      }
      cout << endl;
      cout << "------------------- Omgång " << clock << " ---------------" << endl;
      for(size_t i =0;i<actors->size();++i){
	//cout << "--- Spelare " << (*actors)[i]->name()  << "s tur" << endl;
	if((*actors)[i]->getHp() <=0 ) {
	  // Kanske ska ta bort allt för hand här
	  delete (*actors)[i];
	  --i;
	}else{
	  (*actors)[i]->action();
	}
      }
      ++clock;
    }
  }
  
  Game::~Game(){
    /* Delete all actors first 
       to prevent sigseg*/
    while(!actors->empty()){
      delete (*actors)[0];
    }
    while(!thingMap->empty()){
      map<string,Thing*>::iterator it = thingMap->begin();
      delete it->second;
            if(thingMap->find(it->first)!=thingMap->end()){
	thingMap->erase(thingMap->begin());
      }
    }
    delete thingMap;
    delete actors;    
    delete parser;
    delete actorFuncMap;
  }
}

