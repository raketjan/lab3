#include "julian.h"
namespace lab2{
  Julian::Julian():Date(){
  }

  Julian::Julian(int o):Date(o) {}
  Julian::~Julian(){
  }
  int Julian::year() const{ 
    int number_of_leapyears;
    int the_year=getOffset();
    int leapyear_intervall=1460;
    if(offset<57) {
      return GENESIS;
    }else{
      the_year-57;
      number_of_leapyears = the_year / leapyear_intervall;
      the_year -= number_of_leapyears;   
      return (offset/365+GENESIS) + 1;
    }
  }  
  int Julian::month() const{ 
    int the_offset = offset;
    
    int leapyear_intervall=1460;
    int number_of_leapyears = offset /leapyear_intervall;

    if (offset<=25)  return 11; // november första året

    if (offset<=56) return 12; //december först året

    the_offset -= 56; // nu modulo 1a jan 1858
    // ta oss till första skottåret


    the_offset -= number_of_leapyears;
    the_offset = the_offset % ;
    if (the_offset <= 31) return 1;
    if (year() % 4 == 0) --the_offset;
    if (the_offset <= 59) return 2;
    if (the_offset <= 90) return 3;
    if (the_offset <= 120) return 4;
    if (the_offset <= 151) return 5;
    if (the_offset <= 181) return 6;
    if (the_offset <= 212) return 7;
    if (the_offset <= 243) return 8;
    if (the_offset <= 273) return 9;
    if (the_offset <= 304) return 10;
    if (the_offset <= 334) return 11;
    if (the_offset <= 365) return 12;
    return -1;
  }  

}

