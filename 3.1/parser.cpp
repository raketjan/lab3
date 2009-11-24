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
    ((*player).*(*actorFuncMap)[token])(token2);
  }
}
