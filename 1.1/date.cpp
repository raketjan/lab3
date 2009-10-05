#include "date.h"
#include <ctime>
namespace lab2{
  Date::Date(){
    time_t sekunder = time(0);
    set_k_time(sekunder);
    sekunder = k_time(0);
    offset = sekunder/(60*60*24) + 40588; // 1 jan 1970 !
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
    return "";
  }
  
  std::string Date::month_name() const{
    return "";
  }
  
  Date & Date::add_year(int n){
    return *this;
  }
  
  Date & Date::add_month(int n){
    return *this;
  }
  
  int Date::mod_julian_day() const{
    return Date::getOffset();
  } 

  int Date::getOffset() const {
    return offset;
  }
  /* Not defined in Date */
  int operator-(const Date & d,const Date & d2){
    return 0;
  }
  
 std::ostream & operator<<(std::ostream & os,const Date & date) {
   os << date.year() << "-" << date.month() << "-" << date.day();
    return os;
  }
  std::istream & operator>>(std::istream & is, Date & date){
    return is;
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
