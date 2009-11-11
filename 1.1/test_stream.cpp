#include "gregorian.h"

using namespace lab2;


int main(){
  Gregorian g(9000);
  ++g;
  int i = 0;
  std::cout << g << " ";
  ++g;
  std::cout << g << std::endl;
  --g;
  std::cout << g << std::endl;
  
  return 0;
}

