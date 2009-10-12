#include "date.h"
#include <ctime>
namespace lab2{
  /* TODO */
  Date::Date(){
    time_t sekunder = time(0);
    set_k_time(sekunder);
    
    sekunder = k_time(0);
    offset = sekunder/(60*60*24) + 40588 - 1; // 1 jan 1970 !
  }
  
  Date::Date(int o):offset(o){
  }
  
  Date::~Date(){
  }
  
  Date::Date(int months, int days_per_year){
  }
  
  /* Maybe not needed */
  Date & Date::operator++(){
    ++offset;
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

  int Date::mod_julian_day() const{
    return Date::getOffset();
  } 

  int Date::getOffset() const {
    return offset;
  }

  int operator-(const Date & d,const Date & d2){
    return d.offset - d2.offset;
  }
  
 std::ostream & operator<<(std::ostream & os,const Date & date) {
   os << date.year() <<  "-";
   os.width(2);
   os.fill('0');
   os << date.month() << "-" << date.day();
    return os;
  }

  bool operator==(const Date & d1,const Date &d2){
    return d1.getOffset()==d2.getOffset();
  }
  bool operator!=(const Date & d1,const Date &d2){
    return d1.offset!=d2.offset;
  }
  bool operator<(const Date & d1,const Date &d2){
    return d1.getOffset()<d2.getOffset();
  }
  bool operator<=(const Date & d1,const Date &d2){
    return d1.getOffset()<=d2.getOffset();
  }
  bool operator>(const Date & d1,const Date &d2){
    return d1.getOffset()>d2.getOffset();
  }
  bool operator>=(const Date & d1,const Date &d2){
    return d1.getOffset()>=d2.getOffset();
  }
}
