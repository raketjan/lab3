#include "julian.h"
namespace lab2{
int Julian::year(){
  return offset%days_per_year;
}
}
