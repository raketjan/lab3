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
      typename std::set<Calobj<T> >::iterator it;
      it = find(events.begin(),events.end(),co);
      if(it!=events.end()){
	Calobj<T> co2(*it);
	events.erase(*it);
	co2.add_event(e);
	events.insert(co2);
	return true;	
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
    std::cout << "remove_event: " << y<<"-"<<m<<"-"<<d << std::endl;
    T * da = new T(y,m,d);
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
    //T * tmp_today = new T(c.get_today().year(),c.get_today().month(),c.get_today().day());
    //today(tmp_today);
    //*today(*(c.get_today()));
    //events(c.get_events());
    
    return *this;
  }
  
  template <class T>
  template <class U>
  Calendar<T> & Calendar<T>::operator=(const Calendar<U> & c){
    //events = c.get_events2();
    
    //today = new U(*(c.today));
    //rerurnerar T
    return *this;
  }
  
  template <class T>
  Calendar<T>::Calendar(const Calendar<T> & c):today(new T(*(c.get_today()))),events(c.get_events()){
    
  }
  
  template <class T>
  template <class U>
  Calendar<T>::Calendar(const Calendar<U> & c){
    *today=*(c.get_today()); //*this = T 
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
    for(typename std::set<Calobj<T> >::const_iterator i = c.get_events().begin();//c.get_events().find(*(c.get_today()))
	i != c.get_events().end(); 
	++i){
      os << *i << std::endl;
    }
    return os;
  }

}
