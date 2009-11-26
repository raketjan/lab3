#include "parser.h"

namespace advgame{
  /*
    Parsern måste ha tillgång till
    mappar med kommandon och actors
    Kan ta en string istället med mappen
  */
  void Parser::parse(Actor * player) {    
    string token, token2;
    cin >> token;
    cin >> token2;
    if(actorFuncMap->find(token) != actorFuncMap->end() &&
       thingMap->find(token2) != thingMap->end()){
      ((*player).*(*actorFuncMap)[token])(token2);
    }else{
      cout << "Lär dig stava idiotjävel!" << endl;
    }
  }
}
