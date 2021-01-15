#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

template <typename Data>
class List;

template <typename Data>
std::ostream& operator<<(std::ostream&, List<Data> const&);

template <typename Data>
class List
{

public:
  List();
  ~List() { delete first; }

  void insert(Data const& d);
  
  List(List const&);
  List(List&&);
  List& operator=(List const&);
  List& operator=(List&&);
    
private:

  class Link
  {
  public:
    Link(Data const& d, Link* n)
      : data(d), next(n) {}
    ~Link() { delete next; }
    
    friend class List;
    static Link* clone(Link const*);

  private:
    Data data;
    Link* next;
    friend std::ostream& operator<< <>(std::ostream&, List<Data> const&);  
  };
  
  Link* first;
  friend std::ostream& operator<< <>(std::ostream&, List<Data> const&);
  
public:  
  using value_type = Data;
  
  class Iterator
  {
  public:
    Iterator(Link* p) 
      : p(p) {}
    Iterator& operator++();
    Data& operator*();
    bool operator!=(Iterator const& it);
    bool operator==(Iterator const& it);

  private:
    Link* p; //Position in iterator
  };

Iterator begin();
Iterator end();
};
#include "list.tcc"
#endif
