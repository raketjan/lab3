
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
  Calobj<T>::Calobj(const Calobj<T> & c){
    //*this=c;    
  }
  
  template <class T>
  Calobj<T> & Calobj<T>::operator=(const Calobj<T> & co){    
    *date=*(co.date);  
    events.clear();
    events=co.events;
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
  std::list<std::string> Calobj<T>::get_events(){
    return events;
  }

  template <class T>
  T * Calobj<T>::get_date(){
    return date;
  }

  template <class T>  
  bool operator==(const Calobj<T> & c1,const Calobj<T> & c2){
    return c1.get_date() == c2.get_date();
  }
  
  template <class T>  
  bool operator<(const Calobj<T> & c1,const Calobj<T> & c2){
    return c1.get_date() < c2.get_date();
  }
  
  template <class T>  
  bool Calobj<T>::remove_event(std::string e){
    if(exist_event(e)){
      events.remove(e);
      // funksr no
      return true;
    }
    return false;
  }  
  
}
