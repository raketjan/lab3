#ifndef __THING__
#define __THING__
#include <iostream>
using namespace std;
namespace advgame{
  class Thing{
  public:
    virtual ~Thing();
    virtual string save() = 0;
    void go(string s);
    void pick_up(string);
    void drop(string);
    void examine(string);
  };
}
#endif
