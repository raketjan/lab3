#include "gregorian.h"
namespace lab2{
   Gregorian::Gregorian():Date(){
  }

  Gregorian::Gregorian(int o):Date(o) {
}

  Gregorian::Gregorian(int year, int month, int day)
    :Date(mod_julian_day(year, month, day)) {
   
  }



  Gregorian::~Gregorian(){
  }

  int Gregorian::year() const{ 
    int p = offset + 2400000;
    int s1 = p + 68569;
    int n = 4 * s1 / 146097;
    int s2 = s1 - (146097 * n + 3) / 4;
    int i = 4000*(s2 + 1) / 1461001;
    int s3 = s2 - 1451 * i / 4 + 31;
    int q = 80 * s3 / 2447;
    int e = s3 - 2447 * q/80;
    int s4 = q/11;
    int m = q + 2 - 12 * s4;
    int j = 100* (n -49) + i + s4;
    int d = e;
    return j;
  }  

  int Gregorian::month() const{ 
    int p = offset + 2400000;
    int s1 = p + 68569;
    int n = 4 * s1 / 146097;
    int s2 = s1 - (146097 * n + 3) / 4;
    int i = 4000*(s2 + 1) / 1461001;
    int s3 = s2 - 1451 * i / 4 + 31;
    int q = 80 * s3 / 2447;
    int e = s3 - 2447 * q/80;
    int s4 = q/11;
    int m = q + 2 - 12 * s4;
    int j = 100* (n -49) + i + s4;
    int d = e;
    return m;

}

  int Gregorian::day() const {
    int p = offset + 2400000;
    int s1 = p + 68569;
    int n = 4 * s1 / 146097;
    int s2 = s1 - (146097 * n + 3) / 4;
    int i = 4000*(s2 + 1) / 1461001;
    int s3 = s2 - 1451 * i / 4 + 31;
    int q = 80 * s3 / 2447;
    int e = s3 - 2447 * q/80;
    int s4 = q/11;
    int m = q + 2 - 12 * s4;
    int j = 100* (n -49) + i + s4;
    int d = e;
    return d;
   
  }

  int Gregorian::mod_julian_day() const { 
    return offset;
  }

  int Gregorian::mod_julian_day(int year, int month, int day) {
    int c;
    int J;
    if (month<3){
      month +=12;
      year -= 1;
    }
    c = c - year / 100 + year / 400;
    J= 1461 * (year + 4716) / 4 + 153 * (month + 1) + day + c- 1524.5;  // ger UNmodified julian date
return J- 2400000;
  }


}
