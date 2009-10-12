#include "gregorian.h"
namespace lab2{
  const std::string Gregorian::weekdaynames[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
  const std::string Gregorian::monthnames[]={"january","february","march","april","may","june","july","august","september","october","november","december"};
  Gregorian::Gregorian():Date(){
  }

  /* not checked if offset<0 */
  Gregorian::Gregorian(int o):Date(o) {
  }

  Gregorian::Gregorian(int year, int month, int day)
    :Date(mod_julian_day(year, month, day)) {
  }



  Gregorian::~Gregorian(){
  }

  int Gregorian::year() const{ 
    float A, month, year;
    if (offset == 0) return 1858;
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
    if(year<1858||year>2558) {
      throw std::out_of_range("year_out_of_range");
    }
    if(month<1||month>12){
      throw std::out_of_range("month_out_of_range");
    }
    /*Maybe needed 30/2 for example*/
    if(day<1||day>31){
      throw std::out_of_range("day_out_of_range");
    }

    if (month <= 2) {
      month += 12;
      year -= 1;
    }
    float A = floor(year/100);
    float B = 2 - A + floor(A/4);
    float julDate = floor(365.25*(year+4716)) + floor(30.6001*(month+1)) + day + B - 1524.5;
    return julDate - 2400000;
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
  
  /* Negativa! */
  Date & Gregorian::add_year(int y){
    if(day()==29&&month()==2){ //börjar på skottdag == 29
      if((year()+y)%400==0){ // landar på en skottdag == 29
	offset = mod_julian_day(year()+y,2,29);
	return *this;
      }
      else if((year()+y)%100==0){ // ändå inte skottår
	offset = mod_julian_day(year()+y,2,28);
	return *this;
      }else if((year()+y)%4==0){ // landar på vanligt skottår
      	offset = mod_julian_day(year()+y,month(),29);
	return *this;
      }else{	
	offset = mod_julian_day(year()+y,month(),28); // landar på ej skottår
	return *this;
      }
    }else{ // inte börjat på skottdag
      offset = mod_julian_day(year()+y,month(),day());
      return *this;
    }
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
  
  int Gregorian::week_day() const{
    return ((offset+2)%days_per_week())+1; //Kostsamt
  }

  /* Hardcaoded - Dangerous! */
  int Gregorian::days_per_week() const{
    return 7;
  }
  
  std::string Gregorian::week_day_name() const{
    return weekdaynames[week_day()-1];
  }

  std::string Gregorian::month_name() const{
    return monthnames[month()-1];
  }
  
  Date & Gregorian::operator++(){
    ++offset;
    return *this;
  }
  
  Gregorian Gregorian::operator++(int){
    Gregorian tmp(*this);
    ++offset;
    return tmp;
  }
  

  Date & Gregorian::operator--(){
    --offset;
    return *this;
  }
  
  Gregorian Gregorian::operator--(int){
    Gregorian tmp(*this);
    --offset;
    return tmp;
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
