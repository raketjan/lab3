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
  /* ska kunna ta neg*/
  void Gregorian::add_one_month(){
    if(day()==31&&month()==7){
      offset+=days_this_month();
      return;
    }
    if(day()==31){
      offset+=30;
      return;
    }
    if(day()==30&&month()==1){
      offset+=30;
      return;
    }
    if(day()==29&&month()==1){
      if(is_leap_year()){
	offset+=days_this_month();
      }else{
	offset+=30;
      }
      return;
    }
 
    offset+=days_this_month();
    return;
  }
  
  void Gregorian::sub_one_month(){
    if(day()==30&&month()==3){
      offset-=30;
      return;
    }
    if(day()==29&&month()==3){
      if(is_leap_year()){
	offset-=29;	
      }else{
	offset-=30;
      }
      return;
    }
    if(day()==28&&month()==3){
      if(is_leap_year()){
	offset-=29;
      }else{
	offset-=28;
      }
      return;
    }
    int prev_month=(month()!=1)?month()-1:12;
    offset-=days_in_month(prev_month);
    
    return;
  }
  
  /*Working ?*/
  Date & Gregorian::add_month(int m){
    if(m<0){
      for(int i=0;i<-m;++i){
	sub_one_month();	
      }
    }else{    
      for(int i=0;i<m;++i){
	add_one_month();	
      }
    }
    return *this;
  }
  
  int Gregorian::days_this_month() const{
    return days_in_month(month());
  }
  
  int Gregorian::days_in_month(int m) const{
    
    switch (m){
    case 1:
      return 31;
      break;
    case 2:
      if(is_leap_year()){
	return 29;
      }else{
     return 28;
      }
      break;
    case 3:
      return 31;
      break;
    case 4:
	return 30;
	break;
    case 5:
      return 31;
      break;
    case 6:
	return 30;
	break;
    case 7:
      return 31;
      break;
    case 8:
      return 31;
      break;
      case 9:
	return 30;
	break;
    case 10:
      return 31;
      break;
    case 11:
      return 30;
      break;
    case 12:
      return 31;
	break;
	
    }
  }
  
  bool Gregorian::is_leap_year() const{
    if(year()%400==0){
      return true;
    }
    if(year()%100==0){
      return false;
    }
    if(year()%4==0){
      return true;
    }
    return false;
  }
}
