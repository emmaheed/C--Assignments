#include <algorithm>
#include <iostream>

//Insert
template<typename Data>
void List<Data>::insert(Data const& d)
{
  first = new Link(d, first);
}

//Find first place in list
template<typename Data>
typename List<Data>::Iterator List<Data>::begin() 
{
  Iterator it{first};
  return it;
}

//Find last place in list
template<typename Data>
typename List<Data>::Iterator List<Data>::end() 
{
  Iterator it{nullptr};
  return it;
}

//Move one step forward in iterator
template<typename Data>
typename List<Data>::Iterator& List<Data>::Iterator::operator++() 
{
  p = p -> next;
  return *this; 
}

//Get value at iterator position
template<typename Data>
Data& List<Data>::Iterator::operator*() 
{ 
  return p -> data;
}

//Check if two iterator positions are not equal
template<typename Data>
bool List<Data>::Iterator::operator!=(Iterator const& it) 
{
  return p != it.p;   
}

//Check if two iterator positions are equal
template<typename Data>
bool List<Data>::Iterator::operator==(Iterator const& it) 
{
  return p == it.p;  
}

//Print list
template<typename Data>
std::ostream& operator<<(std::ostream & os, List<Data> const& l) 
{
  typename List<Data>::Link* temp{l.first};
  while( temp != nullptr ) 
  {
    os << temp -> data << " ";
    temp = temp -> next; 
  }
  return os;
} 
//-----------------------------------------------------//
// Important copy and assignment stuff

template<typename Data>
typename List<Data>::Link*
List<Data>::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

template<typename Data>
List<Data>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template<typename Data>
List<Data>::List(List const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template<typename Data>
List<Data>::List(List&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template<typename Data>
List<Data>& List<Data>::operator=(List const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template<typename Data>
List<Data>& List<Data>::operator=(List&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}
