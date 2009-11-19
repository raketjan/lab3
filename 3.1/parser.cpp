#include "parser.h"

namespace advgame{
  /*
    Parsern måste ha tillgång till
    mappar med kommandon och actors
    Kan ta en string istället med mappen
  */
  void Parser::parse(Actor * player) {

    string token;
    cin >> token;   
    if (token == "gå") {
      cin >> token;
      if (token =="åt") cin >> token;
      player->go(token);
      //(actorMap[player]->*actionMap["go"])(token);
    }
    /*
    else if (token == "ta") {
      cin >> token;
     if (token =="upp") cin >> token;
     (player->*mappen["ta"])(token);
     
    }else if (token == "släng") {
      cin >> token;
      if (token == "iväg") cin >> token;
      (player->*mappen["drop"])(token);
    }else if (token == "undersök") {
      cin >> token;
      cout << "du vill undersöka " << token << endl;
      (player->*mappen["undersök"])(token);
    }else if (token == "prata") {
      cin >> token;
      cout << "du vill prata med " << token << endl;
    }else if (token == "anfall") {
      cin >> token;
      cout << "du vill anfalla " << token << endl;
    } 
    */
    
}


}
