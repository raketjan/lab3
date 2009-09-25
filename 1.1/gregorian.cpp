#include "gregorian.h"
namespace lab2{
  int Gregorian::year() const{
    int number_of_leapyears;
    int the_year=getOffset();
    int leapyear_intervall=1460;
    if(offset<45) {
      return GENESIS;
    }else{
      the_year-=44;
      number_of_leapyears = the_year / leapyear_intervall;
      the_year -= number_of_leapyears;   
      return (offset/365+GENESIS);
    }
  }
}
