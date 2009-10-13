#include "julian.h"
namespace lab2{
  const std::string Julian::weekdaynames[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
  const std::string Julian::monthnames[]={"january","february","march","april","may","june","july","august","september","october","november","december"};
  Julian::Julian():Date(){
    time_t mytime;
    k_time(&mytime);
    /*funkar i gregorian;*/
    struct tm *t = gmtime(&mytime);
    int year = t->tm_year + 1900;
    int month = t->tm_mon +1;
    int day = t->tm_mday;
    offset = greg_julian_day(year,month,day);
    //Här får man inte anropa nåt virtuellt
  }
  
  Julian::Julian(const Date & d){
    offset=d.offset;
  }  
  /* not checked if offset<0 */
  
  Julian::Julian(int o):Date(o) {
  }
  
  Julian::Julian(int year, int month, int day)
    :Date(double_julian_day(year, month, day)+1) {
  }

  Julian::~Julian(){
  }
  
  double Julian::greg_julian_day(int year,int month, int day){
    check_range(year,month,day);
    if (month <= 2) {
      month += 12;
      year -= 1;
    }

    return (1461 * (year + 4800 + (month - 14)/12))/4 +
      (367 * (month - 2 - 12 * ((month - 14)/12)))/12 -
      (3 * ((year + 4900 + (month - 14)/12)/100))/4 +
      day - 32075;
  }
  
  int Julian::months_per_year() const{
    return 12;
  }

  int Julian::year() const{ 
    double z = floor(offset + 0.5);
    double a = z;
    double b = a + 1524;
    double c = floor((b - 122.1) / 365.25);
    double d = floor(365.25 * c);
    double e = floor((b - d) / 30.6001);
    double month = e > 13? e - 13 : e - 1;
    double year = month < 3? c - 4715 : c - 4716;
    return static_cast<int>(year);
  }  

  int Julian::month() const{  
    double z = floor(offset + 0.5);
    double a = z;
    double b = a + 1524;
    double c = floor((b - 122.1) / 365.25);
    double d = floor(365.25 * c);
    double e = floor((b - d) / 30.6001);
    double month = e > 13? e - 13 : e - 1;
    return static_cast<int>(month);
  }
  
  int Julian::day() const {
   double z = floor(offset + 0.5);
   double f = z - floor(z);
   double a = z;
   double b = a + 1524;
   double c = floor((b - 122.1) / 365.25);
   double d = floor(365.25 * c);
   double e = floor((b - d) / 30.6001);
   double day = b - d - floor(30.6001 * e) + f;
   return static_cast<int>(day);
  }
  
  int Julian::mod_julian_day() const { 
    return floor(offset-2400000.5);
  }
  
  double Julian::double_julian_day() const { 
    return offset;
  }
  /* OK  */
  double Julian::double_julian_day(int year, int month, int day) {
    /* Algorithm as given in Meeus, Astronomical Algorithms, Chapter 7, page 61 */
    check_range(year,month,day);
    if (month <= 2) {
      --year;
      month += 12;
    }
    return floor(365.25 * (year + 4716)) +
      floor(30.6001 * (month + 1)) +
      day - 1524.5;
  }

  void Julian::check_range(int year, int month, int day) {
    if(year<1858||year>2558) {
      throw std::out_of_range("year_out_of_range");
    }
    if(month<1||month>12){
      throw std::out_of_range("month_out_of_range");
    }
    /* Maybe needed 30/2 for example */
    if(day<1||day>days_in_month(month)){
      throw std::out_of_range("day_out_of_range");
    }
  }
  
  /* Working */
     
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
      if((year()+y)%4==0){ // landar på en skottdag == 29
	offset = double_julian_day(year()+y,2,29);
	return *this;      
      }else{	
	offset = double_julian_day(year()+y,month(),28); // landar på ej skottår
	return *this;
      }
    }else{ // inte börjat på skottdag
      offset = double_julian_day(year()+y,month(),day());
      return *this;
    }
  }
  
  int Julian::days_in_month(int m) const{
    if(m<0 || m>12){
      throw std::out_of_range("month_out_of_range");
    }
    
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
    return -1;
  }
  
  int Julian::week_day() const{
    return (static_cast<int>(floor(offset+0.5))%days_per_week())+1; //Kostsamt
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
  
  void Julian::add_one_month(){
    if(day()==31&&month()==7){
      offset+=31;
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
	offset+=31;
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
     if(year()%4==0){
      return true;
    }
    return false;
  }
}
