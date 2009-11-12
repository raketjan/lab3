#include "parser.h"

namespace advgame{
  void Parser::parse() {
    string *  token = new string[3];

    for (int i = 0; i < 3; i++) {
      cin >> token[i]; 
      cout << token[i];
    }
    // cin >> token[0];
    // cin >> token[1];
    // cin >> token[2];

    if (token[0] == "gå") {
      cout << "du vill gå åt " << token[1] << endl;
    } else if (token[0] == "ta") {
      cout << "du vill ta " << token[1] << endl;
    }  else if (token[0] == "undersök") {
      cout << "du vill undersöka " << token[1] << endl;
    } else if (token[0] == "prata") {
      cout << "du vill prata med " << token[2] << endl;
    } else if (token[0] == "anfall") {
      cout << "du vill anfalla " << token[1] << endl;
    } 

    }


}
