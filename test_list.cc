// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "List.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <sstream> 
#include <iomanip>
#include <random>
using namespace std;


//=======================================================================
// Test cases
//=======================================================================
TEST_CASE ("Create an empty list") {
    Sorted_List l{};
    CHECK(l.empty());
    CHECK(l.size() == 0);
    CHECK(l.print() == "");
}

TEST_CASE ("Create, sort and print list"){
    Sorted_List l{};
    l.insert(6);
    l.insert(5);
    l.insert(9);
    l.insert(7);
    l.insert(7);
    CHECK(l.print() == "5 6 7 7 9 ");  
    CHECK(!l.empty());
    CHECK(l.size() == 5);
}

TEST_CASE ("Remove"){
    Sorted_List l{};
    l.insert(9);
    l.insert(2);
    l.insert(8);
    l.insert(7);
    CHECK(l.print() == "2 7 8 9 ");

    //Remove first value
    l.remove(2);
    CHECK(l.print() == "7 8 9 ");

    //Value is not in the list
    l.remove(5);
    CHECK(l.print() == "7 8 9 ");

    //Remove any value
    l.remove(8);
    CHECK(l.print() == "7 9 ");

    //Remove last value
    l.remove(9);
    CHECK(l.print() == "7 ");

    //Remove from a list with one value
    l.remove(7);
    CHECK(l.print() == "");

    //List is empty
    l.remove(7);
    CHECK(l.print() == "");
    CHECK(l.empty());
}

TEST_CASE ("Copy") {
    //Copy to an empty list with constructor
    Sorted_List L1{};
    L1.insert(9);
    L1.insert(8);
    L1.insert(7);
    Sorted_List L2{L1};
    CHECK(L1.print() == L2.print());
    
    //Copy to an empty list with operator
    Sorted_List L3{};
    L3.insert(9);
    L3.insert(8);
    L3.insert(7);
    Sorted_List L4{};
    L4 = L3;
    CHECK(L3.print() == L4.print());

    //Copy to a list with values, with operator
    Sorted_List L5{};
    L5.insert(7);
    L5.insert(9);
    L5.insert(9);
    L2 = L5;
    CHECK(L5.print() == L2.print());

    //Copy an empty list
    Sorted_List L6{};
    Sorted_List L7{L6};
    CHECK(L6.empty());
    CHECK(L7.empty());
    
    //Copy an empty list to a list with values
    L2 = L6;
    CHECK(L6.empty());
    CHECK(L2.empty());
}


TEST_CASE ("Move") {
    //Move to an empty list with constructor
    Sorted_List L1{}; 
    L1.insert(9);
    L1.insert(5);
    Sorted_List L2{move(L1)};
    CHECK(L2.print() == "5 9 ");
    CHECK(L1.empty());
    
    //Move to an empty list with operator
    Sorted_List L3{};
    L3.insert(7);
    L3.insert(8);
    Sorted_List L4{};
    L4 = move(L3);
    CHECK(L4.print() == "7 8 ");
    CHECK(L3.empty());

    //Move to a list with values, with operator
    Sorted_List L5{};
    L5.insert(6);
    L5.insert(2);
    L2 = move(L5);
    CHECK(L2.print() == "2 6 ");
    CHECK(L5.empty());

    //Move an empty list
    Sorted_List L6{};
    Sorted_List L7{move(L6)};
    CHECK(L6.empty());
    CHECK(L7.empty());

    //Move an empty list to a list with values
    L2 = move(L6);
    CHECK(L6.empty());
    CHECK(L2.empty());
}
