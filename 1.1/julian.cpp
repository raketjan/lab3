#include "julian.h"

int Julian::year(){
  return days_since_1858%days_per_year;
}
