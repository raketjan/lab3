#include "gregorian.h"
namespace lab2{
  const std::string Gregorian::weekdaynames[]={
    "monday",
    "tuesday",
    "wednesday",
    "thursday",
    "friday",
    "saturday",
    "sunday"};

  const std::string Gregorian::monthnames[]={
    "january",
    "february",
    "march",
    "april",
    "may",
    "june",
    "july",
    "august",
    "september",
    "october",
    "november",
    "december"};
  
  Gregorian::Gregorian():Date(){
    time_t mytime;
    k_time(&mytime);
    
    struct tm *t = gmtime(&mytime);
    int year = t->tm_year + 1900;
    int month = t->tm_mon +1;
    int day = t->tm_mday;
    offset = double_julian_day(year,month,day) ;    
	std::cout << "setting offset 1 " << offset << std::endl;
  }

  /* not checked if offset<0 */
  /* konstig */
  Gregorian::Gregorian(double o):Date(o) {
    std::cout << "setting offset 3 " << offset << std::endl;
  }
  
  /* ok */
  Gregorian::Gregorian(int y, int m, int d):Date(){
    check_range(y,m,d);
    //?
    //Date(double_julian_day(y, m, d));
    Date::offset = double_julian_day(y, m, d);
    std::cout << "setting offset 2 " << offset << std::endl;
  }

  Gregorian::~Gregorian(){
  }
  
  int Gregorian::months_per_year() const{
    return 12;
  }
  
  int Gregorian::year() const{
    std::cout << "year(): offset: " << offset << std::endl; 
    int p = floor(offset + 0.5);
    int s = p + 68569;
    int n = floor(4*s / 146097);
    s = s - floor((146097*n+3) / 4);
    int i = floor(4000 * (s+1) / 1461001);
    s = s - floor(1461*i/4) + 31;
    int q = floor(80*s/2447);
    s = floor(q / 11);
    return 100*(n - 49) + i + s;
  }  

  int Gregorian::month() const{
    int p = floor(offset + 0.5);
    int s = p + 68569;
    int n = floor(4*s / 146097);
    s = s - floor((146097*n+3) / 4);
    int i = floor(4000 * (s+1) / 1461001);
    s = s - floor(1461*i/4) + 31;
    int q = floor(80*s/2447);
    s = floor(q / 11);
    return q + 2 - 12*s;
    
  }

  int Gregorian::day() const {
    int p = floor(offset+ 0.5);
    int s = p + 68569;
    int n = floor(4*s / 146097);
    s = s - floor((146097*n+3) / 4);
    int i = floor(4000 * (s+1) / 1461001);
    s = s - floor(1461*i/4) + 31;
    int q = floor(80*s/2447);
    int e = s - floor(2447*q/80);
    s = floor(q / 11);
    return e + offset  - p + 0.5;
  }
  
  int Gregorian::mod_julian_day() const {     
    return floor(offset-2400000.5);
  }
  
  double Gregorian::double_julian_day() const { 
    return offset;
  }
  
  /* borde heta julianday(...) */
  double Gregorian::double_julian_day(int year, int month, int day) {
    //check_range(year,month,day);
     
        double ret = (1461 * (year + 4800 + (month - 14)/12))/4 +
               (367 * (month - 2 - 12 * ((month - 14)/12)))/12 -
               (3 * ((year + 4900 + (month - 14)/12)/100))/4 +
               day - 32075;

	std::cout << "ret: " << ret << std::endl;
	return ret;

  }
  
  void Gregorian::check_range(int year, int month, int day) {
    std::cout << "check range year " << year << std::endl;
    if(year<1858||year>2558) {
      throw std::out_of_range("year_out_of_range");
    }
    std::cout << "check range month " << month << std::endl;
    
    if(month<1||month>12){
      throw std::out_of_range("month_out_of_range");
    }
    /* Maybe needed 30/2 for example */
    std::cout << "check range day " << day << std::endl;
    std::cout << "days in month: " << days_in_month(month) << std::endl;    
    if(day<1||day>days_in_month(year,month)){
	std::cout << days_in_month(month) << std::endl;
	std::cout << "im gonna throw up" << std::endl;
      throw std::out_of_range("day_out_of_range");
    }
    std::cout << "leaving check_range" << std::endl;
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
	offset = double_julian_day(year()+y,2,29);
	return *this;
      }
      else if((year()+y)%100==0){ // ändå inte skottår
	offset = double_julian_day(year()+y,2,28);
	return *this;
      }else if((year()+y)%4==0){ // landar på vanligt skottår
      	offset = double_julian_day(year()+y,month(),29);
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
 
  int Gregorian::days_in_month(int m) const {
    return days_in_month(year(), m);
  }
 
  int Gregorian::days_in_month(int y, int m) const{
    if(m<1 || m>12){
      throw std::out_of_range("month_out_of_range");
    }
    switch (m){
    case 1:
      return 31;      
    case 2:
      if(is_leap_year(y)){
	return 29;
      }else{
	return 28;
      }      
    case 3:
      return 31;      
    case 4:
	return 30;	
    case 5:
      return 31;      
    case 6:
	return 30;	
    case 7:
      return 31;      
    case 8:
      return 31;      
    case 9:
      return 30;
    case 10:
      return 31;      
    case 11:
      return 30;
    case 12:
      return 31;
    }
    // wroong
    return -1;
  }
  
  int Gregorian::week_day() const{
    return (static_cast<int>(floor(offset+0.5))%days_per_week())+1; //Kostsamt
  }

  /* Hardcaoded - Dangerous! */
  int Gregorian::days_per_week() const{
    return 7;
  }
  
  std::string Gregorian::week_day_name() const{
    if(week_day()<1 || week_day()>7){
      throw std::out_of_range("week_out_of_range");
    }

    return weekdaynames[week_day()-1];
  }

  std::string Gregorian::month_name() const{
    if(month()<1 || month()>12){
      throw std::out_of_range("month_out_of_range");
    }
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

  bool Gregorian::is_leap_year(int y) {
	std::cout << "year " << y << std::endl; 
        if(y % 4 == 0) {
            if(y % 100 == 0) {
                if(y % 400 == 0) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
  } 
 
  bool Gregorian::is_leap_year() const{    
	is_leap_year(year());
  
  }

}
