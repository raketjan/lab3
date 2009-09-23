#include "date.h"
namespace lab2{
  Date::Date(){

  }
  
  Date::~Date(){

  }
  
  Date::Date(int months, int days_per_year){
    
  }
  
  Date & Date::operator++(){
    
  }
  
  Date & Date::operator--(){
    
  }
  
  Date & Date::operator+=(int days){
    
  }
  
  Date & Date::operator-=(int days){
    
  }
  
  bool Date::operator==(const Date & d1,const Date & d2) const{
  }
  
  bool Date::operator!=(const Date & d1,const Date &d2) const{
  }
  
  bool Date::operator<(const Date & d1,const Date &d2) const{
  }
  
  bool Date::operator<=(const Date & d1,const Date &d2) const{
  }
  
  bool Date::operator>(const Date & d1,const Date &d2) const{
  }
  
  bool Date::operator>=(const Date & d1,const Date &d2) const{
  }
    
  int Date::year() const{
    
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
    
  } 

  /* Not defined in Date */
  int operator-(const Date & d,const Date & d2){
    
  }
  
  std::ostream & operator<<(std::ostream & os,const Date & date){
    
  }
}
