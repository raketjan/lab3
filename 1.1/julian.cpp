#include "julian.h"
namespace lab2{
  const std::string Julian::weekdaynames[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
  const std::string Julian::monthnames[]={"january","february","march","april","may","june","july","august","september","october","november","december"};
  Julian::Julian():Date(){
    //Här får man inte anropa nåt virtuellt
  }

  /* not checked if offset<0 */
  Julian::Julian(int o):Date(o) {
  }

  Julian::Julian(int year, int month, int day)
    :Date(mod_julian_day(year, month, day)) {
  }

  Julian::~Julian(){
  }

  int Julian::year() const{ 
    
    float z, a, alpha, b, c, d, e, year, month, day;
    z = offset+1+2400000;

    a = z;
    b = a + 1524;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor((b - d) / 30.6001);

    month = floor((e < 14) ? (e - 1) : (e - 13));
    year = floor((month > 2) ? (c - 4716) : (c - 4715));
    day = b - d - floor(30.6001 * e);

    /*  If year is less than 1, subtract one to convert from
        a zero based date system to the common era system in
        which the year -1 (1 B.C.E) is followed by year 1 (1 C.E.).  */

    if (year < 1) {
        year--;
    }

    return year;
  }  

  int Julian::month() const{
    
    float z, a, alpha, b, c, d, e, year, month, day;
    z = offset+1+2400000;

    a = z;
    b = a + 1524;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor((b - d) / 30.6001);

    month = floor((e < 14) ? (e - 1) : (e - 13));
    year = floor((month > 2) ? (c - 4716) : (c - 4715));
    day = b - d - floor(30.6001 * e);

    /*  If year is less than 1, subtract one to convert from
        a zero based date system to the common era system in
        which the year -1 (1 B.C.E) is followed by year 1 (1 C.E.).  */

    if (year < 1) {
        year--;
    }

    return month;
  }

  int Julian::day() const {

    float z, a, alpha, b, c, d, e, year, month, day;
    z = offset+1+2400000;

    a = z;
    b = a + 1524;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor((b - d) / 30.6001);

    month = floor((e < 14) ? (e - 1) : (e - 13));
    year = floor((month > 2) ? (c - 4716) : (c - 4715));
    day = b - d - floor(30.6001 * e);

    /*  If year is less than 1, subtract one to convert from
        a zero based date system to the common era system in
        which the year -1 (1 B.C.E) is followed by year 1 (1 C.E.).  */

    if (year < 1) {
        year--;
    }

    return day;
  }

  int Julian::mod_julian_day() const { 
    return offset;
  }
  
  int Julian::mod_julian_day(int year, int month, int day) {
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

        /* Algorithm as given in Meeus, Astronomical Algorithms, Chapter 7, page 61 */

    if (month <= 2) {
        year--;
        month += 12;
    }

    return ((floor((365.25 * (year + 4716))) +
            floor((30.6001 * (month + 1))) +
            day) - 1524.5) - 2400000;
  }
  
  /*Working ?*/
  Date & Julian::add_month(int m){
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
  
  int Julian::days_this_month() const{
    return days_in_month(month());
  }
  
  /* Negativa! */
  Date & Julian::add_year(int y){
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
  
  int Julian::days_in_month(int m) const{
    
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
  
  int Julian::week_day() const{
    return ((offset+2)%days_per_week())+1; //Kostsamt
  }

  /* Hardcaoded - Dangerous! */
  int Julian::days_per_week() const{
    return 7;
  }
  
  std::string Julian::week_day_name() const{
    return weekdaynames[week_day()-1];
  }

  std::string Julian::month_name() const{
    return monthnames[month()-1];
  }
  
  Date & Julian::operator++(){
    ++offset;
    return *this;
  }
  
  Julian Julian::operator++(int){
    Julian tmp(*this);
    ++offset;
    return tmp;
  }
  

  Date & Julian::operator--(){
    --offset;
    return *this;
  }
  
  Julian Julian::operator--(int){
    Julian tmp(*this);
    --offset;
    return tmp;
  }
  
  /* ska kunna ta neg*/
  void Julian::add_one_month(){
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
  
  void Julian::sub_one_month(){
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
  
  bool Julian::is_leap_year() const{
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
