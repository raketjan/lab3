namespace lab2{
  template <class T>
  Calendar<T>::Calendar():today(new T),events(){
    // kanske ska vara i initlistan som statisk
  }


  
  template <class T>
  Calendar<T>::~Calendar(){
    delete today; 
   // kanske ska vara i initlistan som statisk  
  }

  template <class T>
  bool Calendar<T>::set_date(int y,int m,int d){
  // check_date(y, m, d);
    if(y<1858 || y>2558 
       || m < 1 || m>12 
       || d<1 || d>31){
      return false;
    } 
   T * tmp = new T(y, m, d);
   delete today;
   today = tmp;
   return true;
  }
  
  template <class T>
  bool Calendar<T>::add_event(std::string e,int d,int m,int y){    
    
    try{
      T * da = new T(y,m,d);
      Calobj<T> co(da,e);
      std::set<Calobj<T> >::iterator it;
      it = find(events.begin(),events.end(),co);      
      if(it!=events.end()){
	Calobj<T> co2(*it);
	events.erase(*it);
	co2.add_event(e);
	events.insert(co2);
	//delete co;
	return true;	
      }else{
	events.insert(co);
	// går nog bra
	return true;
      }      
    }catch(std::out_of_range&){
      return false;   
    } 
  }
  
  template <class T>
  bool Calendar<T>::add_event(std::string e,int d,int m){
    return add_event(e,d,m,today->year());
  }
  template <class T>
  bool Calendar<T>::add_event(std::string e,int d){    
    return add_event(e,d,today->month(),today->year());
  }

  template <class T>
  bool Calendar<T>::add_event(std::string e){ 
    return add_event(e,today->day(),today->month(),today->year());
  }
  
  
  template <class T>
  bool Calendar<T>::remove_event(std::string e,int d,int m,int y){
    return false;
  }
  template <class T>
  bool Calendar<T>::remove_event(std::string e,int d,int m){
    return false;
  }
  template <class T>
  bool Calendar<T>::remove_event(std::string e,int d){
    return false;
  }
  template <class T>
  bool Calendar<T>::remove_event(std::string e){
    return false;
  }
  
  template <class T>
  std::set<Calobj<T> > Calendar<T>::get_events(){
    return events;
  }
  
  template <class T>
  T * Calendar<T>::get_today(){
    return today;
  }
  

  
  template <class T>
  Calendar<T> & Calendar<T>::operator=(const Calendar<T> &){
    return *this;
  }
  
  template <class T>
  template <class S>
  Calendar<T> & Calendar<T>::operator=(const Calendar<S> &){
    return *this;
  }
  
  template <class T>
  Calendar<T>::Calendar(const Calendar<T> & c){
    
  }
  
  template <class T>
  template <class S>
  Calendar<T>::Calendar(const Calendar<S> & c){
    
  }

  template <class T>
  std::ostream & operator<<(std::ostream & os, const Calendar<T> & c){
    
    return os;
  }

}
