#include "gregorian.h"
namespace lab2{
  int Gregorian::year(){
    return offset%days_per_year;
  }
}
