#include "date.h"
#include <ctime>
namespace lab2{
  /* TODO */
  Date::Date(){
  }
    
  Date::Date(int o):offset(o){
    
    }
  
  Date::~Date(){
    
  }
  
  Date::Date(int months, int days_per_year){
    
  }
  
  /* Needed! */
  Date & Date::operator++(){
    ++offset;
    return *this;
  }
  
  /* Needed! */
  Date & Date::operator--(){
    --offset;
    return *this;
  }
  
  Date & Date::operator+=(int days){
    offset+=days;
    return *this;
  }  

  Date & Date::operator-=(int days){
    offset-=days;
    return *this;
  }
  
  
  double Date::getOffset() const {
    return offset;
  }

  int operator-(const Date & d,const Date & d2){
    return d.offset - d2.offset;
  }
  
 std::ostream & operator<<(std::ostream & os,const Date & date) {
   os << date.year() <<  "-";
   os.width(2);
   os.fill('0');
   os << date.month() << "-";
   os.width(2);
   os.fill('0');
   os << date.day();
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
