#include "List.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <sstream> 
#include <iomanip>
using namespace std;

//Define constructor
Sorted_List::Sorted_List():Connection{} {
    
}

//Define copy constructor
Sorted_List::Sorted_List(Sorted_List const& s):first{copy(s.first)} {

}

//Define move cnstructor
Sorted_List::Sorted_List(Sorted_List && s):first{} {
  swap(first, s.first);
}

//Define destructor
Sorted_List::~Sorted_List() {
    while(!empty()) {
        remove();
    }
}

//Insert & sort value
void Sorted_List::insert(int const new_value) {
    if (first == nullptr) { //If the list is empty
        first = new Node{new_value, nullptr};
    }
    else if(first->value > new_value){ //If the current value is smaller than the first one
        first= new Node{new_value, first};
    }
    else {
        insert_helper(new_value, first); //All other positions
    }
}

Sorted_List::Node* Sorted_List::insert_helper(int const v, Node * n) { 
    if (n->next == nullptr) { //If last item in list
        n->next = new Node{v, nullptr};    
    }
    else if (n->next->value > v || n->next->value == v) { //If in between two values
         n->next = new Node{v, n->next};   
    }
    else { //Else repeat until correct position
        insert_helper(v, n->next); 
    }
    return n;
}

//Print list
string Sorted_List::print() {
    stringstream ss;
    Node* temp{first};
    while (temp != nullptr) { //Repeat until last item in list
        ss << temp->value << " ";
        temp = temp->next;
    }
    return ss.str();
}

//Remove value
void Sorted_List::remove(int const v) {   
    Node* current{first}; //Pointer to keep track of the current value
    Node* previous{first}; //Pointer to keep track of the previous value
    if (first == nullptr) { //If the list is empty
        return;
    }
    else if (current->value == v) { //Removes the first value in the list
        first = first->next;
        current->next = nullptr;
        delete current;
    }
    else { 
        while (current != nullptr && current->value != v) { 
            previous = current;
            current = current->next;
        }
        if (current == nullptr) { //The value is not in the list
            return;
        }
        else {
            previous->next = current->next;
            current->next = nullptr;
            delete current;
        }
    }
}

//Remove all
void Sorted_List::remove() {
    Node* temp{first};
    if (first != nullptr) { //Deletes the top value in the list    
        first = first->next;
        temp->next = nullptr;
        delete temp;
    }
    else { //When/if the list is empty
        return;
    }
}

//Check if list is empty
bool Sorted_List::empty() {
   return first == nullptr;
}

//Count size of list
int Sorted_List::size() {
    Node* temp{first};
    int count{};
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

//Define copy assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List const& s) {
    Sorted_List temp{s}; //Make a temprary copy with copy constructor
    swap(first, temp.first); //Redirects the pointers
    return *this; //Goes to the current object
    //Temp is deleted outside the scope
}

//Define move assignment operator
Sorted_List& Sorted_List::operator=(Sorted_List && s) {
    swap(first, s.first);
    while(!s.empty()) { //Delete after swap
        s.remove();
    }
    return *this; 
} 

//Define copy
Sorted_List::Node * Sorted_List::copy(Sorted_List::Node const * n)const{
    if (n == nullptr) 
        return nullptr;

    return new Node{n->value, copy(n->next)};
}
