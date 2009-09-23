#include "date.h"
namespace lab2{
  Date::Date(){
  }
  
  Date::~Date(){
  }
  
  Date::Date(int months, int days_per_year){
  }
  
  inline Date & Date::operator++(){++offset;} 
  inline Date & Date::operator--(){--offset;}
  inline Date & Date::operator+=(int days){offset+=days;}  
  inline Date & Date::operator-=(int days){offset-=days;}
  inline bool Date::operator==(const Date & d) const {return d.getOffset()==offset;}
  inline bool Date::operator!=(const Date & d) const {return d.getOffset()!=offset;}
  inline bool Date::operator<(const Date & d) const{return d.getOffset()<offset;}
  inline bool Date::operator<=(const Date & d) const {return d.getOffset()<offset;}
  inline bool Date::operator>(const Date & d) const {return d.getOffset()>offset;}
  inline bool Date::operator>=(const Date & d) const {return d.getOffset<=offset;}
    
  int Date::year() const{
    int number_of_leapyears,the_year=offset;
    int leapyear_intervall=1460;
    if(offset<45) {
      return GENESIS;
    }else{
      the_year-=44;
      number_of_leapyears = the_year / leapyear_intervall;
      theyear -= number_of_leapyears;   
      return (offset/365+GENESIS);
    }
  }
  
  int Date::month() const{
  }
  
  inline int Date::day() const{
    
  }
  
  int Date::week_day() const{
    
  }
  
  int Date::days_per_week() const{
    
  }
  
  int Date::days_this_month() const{
    
  }
  
  int Date::months_per_year() const{
    
  }
  
  std::string Date::week_day_name() const{
    
  }
  
  std::string Date::month_name() const{
    
  }
  
  Date & Date::add_year(int n){
    
  }
  
  Date & Date::add_month(int n){
    
  }
  
  int Date::mod_julian_day() const{
    return getOffset();
  } 
  
  const int getOffset(){
    return offset;
  }
  
  /* Not defined in Date */
  int operator-(const Date & d,const Date & d2){
    
  }
  
  std::ostream & operator<<(std::ostream & os,const Date & date){
    
  }
}
