#include "date.h"
namespace lab2{
  Date::Date():offset(0){
  }
  
  Date::Date(int o):offset(o){
  }
  
  Date::~Date(){
  }
  
  Date::Date(int months, int days_per_year){
  }
  
  inline Date & Date::operator++(){
    ++offset;
    return *this;
  } 
  inline Date & Date::operator--(){
    --offset;
    return *this;
  }
  inline Date & Date::operator+=(int days){
    offset+=days;
    return *this;
  }  
  inline Date & Date::operator-=(int days){
    offset-=days;
    return *this;
  }

 
  /* TODO */
  inline int Date::day() const{
    return 0;
  }
  /*TODO*/
  int Date::week_day() const{
    return 0;
  }
  /*TODO*/
  int Date::days_per_week() const{
    return 0;
  }
  /*TODO*/
  int Date::days_this_month() const{
    return 0;
  }
  /*TODO*/
  int Date::months_per_year() const{
    return 0;
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
    return Date::getOffset();
  } 

  int Date::getOffset() const {
    return offset;
  }
  /* Not defined in Date */
  int operator-(const Date & d,const Date & d2){
    
  }
  
  std::ostream & operator<<(std::ostream & os,const Date & date){
    
  }
  
  inline bool operator==(const Date & d1,const Date &d2){
    return d1.getOffset()==d2.getOffset();
  }
  inline bool operator!=(const Date & d1,const Date &d2) {return d1.getOffset()!=d2.getOffset();}
  inline bool operator<(const Date & d1,const Date &d2) {return d1.getOffset()<d2.getOffset();}
  inline bool operator<=(const Date & d1,const Date &d2)  {return d1.getOffset()<d2.getOffset();}
  inline bool operator>(const Date & d1,const Date &d2)  {return d1.getOffset()>d2.getOffset();}
  inline bool operator>=(const Date & d1,const Date &d2) {return d1.getOffset()<=d2.getOffset();}
}
