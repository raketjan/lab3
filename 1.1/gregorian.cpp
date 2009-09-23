#include "gregorian.h"


int Gregorian::year(){
  return days_since_1858%days_per_year;
}
