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
    float A, month, year;
    if (offset == 0) return 1858;  // hjälp
    float julDate = offset + 1.5 + 2400000;
    float z = floor(julDate);
    float f = julDate - z;
    if (z < 2299161) {
      A = z;
    }
    else {
      float omega = floor((z-1867216.25)/36524.25);
      A = z + 1 + omega - floor(omega/4);
    }
    float B = A + 1524;
    float C = floor((B-122.1)/365.25);
    float D = floor(365.25*C);
    float Epsilon = floor((B-D)/30.6001);
    float dayGreg = B - D - floor(30.6001*Epsilon) + f;
    if (Epsilon < 14) {
      month = Epsilon - 1;
    }
    else {
      month = Epsilon - 13;
    }
    if (month > 2) {
      year = C - 4716;
    }
    else {
      year = C - 4715;
    }
    return year;

  }  

  int Gregorian::month() const{
    float A, month, year;
    if (offset == 0) return 11;  // hjälp
    float julDate = offset + 1.5 + 2400000;
    float z = floor(julDate);
    float f = julDate - z;
    if (z < 2299161) {
      A = z;
    }
    else {
      float omega = floor((z-1867216.25)/36524.25);
      A = z + 1 + omega - floor(omega/4);
    }
    float B = A + 1524;
    float C = floor((B-122.1)/365.25);
    float D = floor(365.25*C);
    float Epsilon = floor((B-D)/30.6001);
    float dayGreg = B - D - floor(30.6001*Epsilon) + f;
    if (Epsilon < 14) {
      month = Epsilon - 1;
    }
    else {
      month = Epsilon - 13;
    }
    if (month > 2) {
      year = C - 4716;
    }
    else {
      year = C - 4715;
    }
    return month;
  }

  int Gregorian::day() const {
    float A, month, year;
    if (offset == 0) return 17;  // hjälp
    float julDate = offset + 1.5 + 2400000;
    float z = floor(julDate);
    float f = julDate - z;
    if (z < 2299161) {
      A = z;
    }
    else {
      float omega = floor((z-1867216.25)/36524.25);
      A = z + 1 + omega - floor(omega/4);
    }
    float B = A + 1524;
    float C = floor((B-122.1)/365.25);
    float D = floor(365.25*C);
    float Epsilon = floor((B-D)/30.6001);
    float dayGreg = B - D - floor(30.6001*Epsilon) + f;
    if (Epsilon < 14) {
      month = Epsilon - 1;
    }
    else {
      month = Epsilon - 13;
    }
    if (month > 2) {
      year = C - 4716;
    }
    else {
      year = C - 4715;
    }
    return dayGreg;

   
  }

  int Gregorian::mod_julian_day() const { 
    return offset;
  }

  int Gregorian::mod_julian_day(int year, int month, int day) {
    if (month <= 2) {
      month += 12;
      year -= 1;
    }
    float A = floor(year/100);
    float B = 2 - A + floor(A/4);
    float julDate = floor(365.25*(year+4716)) + floor(30.6001*(month+1)) + day + B - 1524.5;
    return julDate - 2400000;
  }


}
