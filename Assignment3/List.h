#ifndef LIST_H
#define LIST_H
#include <string>

class Sorted_List {
    public:
    Sorted_List(); //Constructor
    Sorted_List(Sorted_List const& s);//copy constructor
    Sorted_List(Sorted_List && s);//move constructor
    ~Sorted_List(); //Destructor
    void insert(int const new_value); //Insert & sort 
    std::string print(); //Print the list
    void remove(int const v); //Remove a value
    void remove(); //Remove all 
    bool empty(); //Check if list is empty
    int size(); //Check size
    Sorted_List& operator=(Sorted_List const& s); //Copy operator
    Sorted_List& operator=(Sorted_List && s); //Move operator
    private:
    struct Node {
        int value;
        Node* next;
    };
    Node* first;
    Node* copy(Node const * n) const;
    Node* insert_helper(int const v, Node * n);
};

#endif
