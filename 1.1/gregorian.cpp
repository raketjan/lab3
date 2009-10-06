#include "gregorian.h"
namespace lab2{
   Gregorian::Gregorian():Date(){
  }

  Gregorian::Gregorian(int o):Date(o) {
}

  Gregorian::Gregorian(int year, int month, int day)
    :Date(mod_julian_day(year, month, day) + 1) {
  }



  Gregorian::~Gregorian(){
  }

  int Gregorian::year() const{ 

    int j = offset + 2400000 - 1721119;
    int y = (4 * j - 1) / 146097;
    j = 4 * j -1 - 146097 * y;
    int d = j / 4;
    j = (4 * d + 3) / 1461;
    d = 4 * d + 3 - 1461 * j;
    d = (d + 4) / 4;
    int m = (5 * d - 3) / 153;
    d = 5* d - 3 - 153 * m;
    d = (d + 5) / 5;
    y = 100 * y + j;
    if (m < 10) m = m + 3;
    else {
      m = m - 9;
      y = y + 1;
    }
      return y;
  }  

  int Gregorian::month() const{ 
    int j = offset + 2400000 - 1721119;
    int y = (4 * j - 1) / 146097;
    j = 4 * j -1 - 146097 * y;
    int d = j / 4;
    j = (4 * d + 3) / 1461;
    d = 4 * d + 3 - 1461 * j;
    d = (d + 4) / 4;
    int m = (5 * d - 3) / 153;
    d = 5* d - 3 - 153 * m;
    d = (d + 5) / 5;
    y = 100 * y + j;
    if (m < 10) m = m + 3;
    else {
      m = m - 9;
      y = y + 1;
    }
  return m;

}

  int Gregorian::day() const {
    int j = offset + 2400000 - 1721119;
    int y = (4 * j - 1) / 146097;
    j = 4 * j -1 - 146097 * y;
    int d = j / 4;
    j = (4 * d + 3) / 1461;
    d = 4 * d + 3 - 1461 * j;
    d = (d + 4) / 4;
    int m = (5 * d - 3) / 153;
    d = 5* d - 3 - 153 * m;
    d = (d + 5) / 5;
    y = 100 * y + j;
    if (m < 10) m = m + 3;
    else {
      m = m - 9;
      y = y + 1;
    }
    return d;
   
  }

  int Gregorian::mod_julian_day() const { 
    return offset;
  }

  int Gregorian::mod_julian_day(int year, int month, int day) {
    if (month > 2) month -= 3;
    else {
      month += 9;
      year -= 1;
    }
    int c = year / 100;
    int ya = year - 100 * c;
    int j = (146097 * c) / 4 + (1461 * ya) / 4 + (153 * month + 2) / 5 + day + 1721119 - 2400000; 
    return j - 1;
  }


}
