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
    try{
      
      T * tmp = new T(y, m, d);
      delete today;
      today = tmp;
      return true;
    }catch(...){
      return false;
    }
  }
  
  template <class T>
  bool Calendar<T>::add_event(std::string e,int d,int m,int y){
    try{
      T * da = new T(y,m,d);
      Calobj<T> co(da,e);
      typename std::set<Calobj<T> >::iterator it;
      it = find(events.begin(),events.end(),co);
      if(it!=events.end()){
	Calobj<T> co2(*it);
	events.erase(*it);
	bool tmp = co2.add_event(e);
	events.insert(co2);
	return tmp;	
      }else{
	events.insert(co);
	//går nog bra
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
    //std::cout << "remove_event: " << y<<"-"<<m<<"-"<<d << std::endl;
    T * da;
    try{
      da = new T(y,m,d);
    }catch(...){
      return false;
    }
    Calobj<T> co(da,e);
    typename std::set<Calobj<T> >::iterator it;
    it = find(events.begin(),events.end(),co);
    if(it!=events.end()){
      // it är const Calobj efetersom det är ett sorterat set
      // kopiera
      // tabort
      // lägg till om inte dess eventllista e tom
      Calobj<T> co2(*it);
      events.erase(*it); 
      if(!co2.remove_event(e)){
	return false; //returnerar bool
      }
      if(co2.get_events().size()!=0){
	events.insert(co2);
	return true;
      }else{
	return true;	
      }
    }else{
      return false;
    }
  
  return false;
}
  template <class T>
  bool Calendar<T>::remove_event(std::string e,int d,int m){
    return remove_event(e,d,m,today->year());
  }
  template <class T>
  bool Calendar<T>::remove_event(std::string e,int d){
    return remove_event(e,d,today->month(),today->year());
  }
  template <class T>
  bool Calendar<T>::remove_event(std::string e){
    return remove_event(e,today->day(),today->month(),today->year());
  }
  
  template <class T>
  const std::set<Calobj<T> > & Calendar<T>::get_events() const{
    return events;
  }
  
  template <class T>
  const T * Calendar<T>::get_today() const{
    return today;
  }
    
  template <class T>
  Calendar<T> & Calendar<T>::operator=(const Calendar<T> & c){
    *today = *(c.get_today());
    events.empty();
    events = c.get_events();
    return *this;
  }
  
  template <class T>
  template <class U>
  Calendar<T> & Calendar<T>::operator=(const Calendar<U> & c){

    *today = *(c.get_today());
    events.empty();
    typename std::set<Calobj<U> >::const_iterator i;
    for(i = c.get_events().begin();
	i != c.get_events().end();
	++i){
      Calobj<T> tmp(*i);
      events.insert(tmp); // denna events har T      
    }

    return *this; // T
  }
  
  template <class T>
  Calendar<T>::Calendar(const Calendar<T> & c):today(new T(*(c.get_today()))),events(c.get_events()){
    
  }
  
  template <class T>
  template <class U>
  Calendar<T>::Calendar(const Calendar<U> & c){
    //std::cout << "*get_today() " << *(c.get_today()) << std::endl;
    //*today är inget datum än så gör en ny
    T  * tmp = new T(*(c.get_today())); 
    today = tmp;
    events.empty();
    typename std::set<Calobj<U> >::const_iterator i;
    for(i = c.get_events().begin();
	i != c.get_events().end();
	++i){
      Calobj<T> tmp(*i);
      events.insert(tmp); // denna events har T      
    }

  }
  
  template <class T>
  std::ostream & operator<<(std::ostream & os, const Calendar<T> & c){
    //bara från dagens
    Calobj<T> tmp(new T(c.get_today()->year(),c.get_today()->month(),c.get_today()->day()) , "xx");
    typename std::set<Calobj<T> >::const_iterator i;
    //i = find(c.get_events().begin(),c.get_events().end(),tmp);   
    for(i = c.get_events().begin();
    	i != c.get_events().end();
	++i){
      if(*i < tmp ){
	
      }else{      
	os << *i;
      }
    }
    return os;
  }

}
