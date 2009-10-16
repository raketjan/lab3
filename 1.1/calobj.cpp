
namespace lab2{
  
  template <class T>
  Calobj<T>::Calobj(T * d,std::string e):date(d){
    add_event(e);
  }
  
  template <class T>
  Calobj<T>::~Calobj(){
    delete date;
  }
  
  template <class T>
  Calobj<T>::Calobj(const Calobj<T> & c):events(c.get_events()),date(new T(*(c.get_date()))){
  }

  template <class T>
  template <class U>
  Calobj<T>::Calobj(const Calobj<U> & c):events(c.get_events()),date(new T(*(c.get_date()))){
  }
  
  
  template <class T>
  Calobj<T> & Calobj<T>::operator=(const Calobj<T> & co){    
    T * tmp =  new T(*(co.date));
    date = tmp;
    events(co.get_events());
    return *this;
  }
  
  
  template <class T>
  bool Calobj<T>::exist_event(std::string e){
    if (find(events.begin(),events.end(),e) == events.end()) { //fanns inte i listan
      return false;
    }else{
      return true;
    }
  }

  template <class T>
  bool Calobj<T>::add_event(std::string e){
    if(exist_event(e)){
      return false;
    }
    // hoppas den funkar
    events.push_back(e);
    return true;   
  }

  template <class T>
  const std::list<std::string> & Calobj<T>::get_events() const{
    return events;
  }

  template <class T>
  const T * Calobj<T>::get_date() const{
    return date;
  }


  template <class T>  
  bool operator==(const Calobj<T> & c1,const Calobj<T> & c2){
    return *(c1.get_date()) == *(c2.get_date());
  }
  
  template <class T>  
  bool operator<(const Calobj<T> & c1,const Calobj<T> & c2){
    return *(c1.get_date()) < *(c2.get_date());
  }
  
  
  template <class T>  
  std::ostream & operator<<(std::ostream & os, const Calobj<T> & co){    
    typename std::list<std::string>::const_iterator i = co.get_events().begin();
    for(; i != co.get_events().end(); ++i){
      os << *(co.get_date()) << " : " << *i;
      // töm buffer?
    }
    return os;
  }
  
  
  template <class T>  
  bool Calobj<T>::remove_event(std::string e){
    if(exist_event(e)){
      events.remove(e);
      // funkar nog
      return true;
    }
    return false;
  }  
  
}
