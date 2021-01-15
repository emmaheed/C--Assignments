#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <sstream> 
#include <iomanip>
using namespace std;

TEST_CASE("Time valid") 
{
    Time t1{23, 59, 59};
    Time t2{25, 67, 01};   
    CHECK(is_valid(t1));
    CHECK(!is_valid(t2));
}

TEST_CASE("Time string") 
{
    Time t1{23, 59, 59};
    Time t2{12, 59 ,59};
    Time t3{00, 59, 59};
    Time t4{02, 02 ,59};
    CHECK(to_string(t1, false) == "11:59:59 pm");
    CHECK(to_string(t2, false) == "12:59:59 pm");
    CHECK(to_string(t3, false) == "12:59:59 am");
    CHECK(to_string(t4, false) == "02:02:59 am");
    CHECK(to_string(t1, true) == "23:59:59");
    CHECK(to_string(t3, true) == "00:59:59");
}

TEST_CASE("Add time") 
{
    Time t1{23, 59, 59};
    Time t2{23,59, 59};
    Time t1_new{00, 00, 04}; //New time after operation
    Time t2_new{00, 00, 04};
    Time t3{};
    Time t4{};
    t3=t1+5; //Operation
    t4=t2+86405; //Add one day and five seconds
    CHECK(t3==t1_new);
    CHECK(t4==t2_new);
}

TEST_CASE("Subtract time") 
{
    Time t1{00, 00, 00};
    Time t2{12, 20, 30};
    Time t1_new{23, 59, 59};
    Time t2_new{12, 20, 25};
    Time t3{};
    Time t4{};
    t3=t1-1;
    t4=t2-86405; //Substract one day and five seconds
    CHECK(t3==t1_new);
    CHECK(t4==t2_new);
}

TEST_CASE("Add second Pre fix") 
{
    Time t1{23, 59, 59};
    Time t1_new{0, 0, 0};
    ++t1;
    CHECK(t1==t1_new);
}

TEST_CASE("Add second Post fix") 
{
    Time t1{23, 59, 59};
    Time t1_new{23, 59, 59};
    t1++;
    CHECK(t1==t1_new);
}

TEST_CASE("Subtract second Pre fix") 
{
    Time t1{0, 0, 0};
    Time t1_new{23, 59, 59};
    --t1;
    CHECK(t1==t1_new);
}

TEST_CASE("Subtract second Post fix") 
{
    Time t1{0, 0, 0};
    Time t1_new{0, 0, 0};
    t1--;
    CHECK(t1==t1_new);
}

TEST_CASE("Comparison") 
{
    Time t1{23, 59, 59};
    Time t2{23, 59, 58};
    CHECK(!(t1==t2));
    CHECK(t1!=t2);
    CHECK(!(t1<t2));
    CHECK(t1>t2);
    CHECK(!(t1<=t2));
    CHECK(t1>=t2);
 
}

TEST_CASE("Output") 
{
    Time t1{12, 14, 45};
    Time t2{12, 02, 13};
    stringstream ss1;
    stringstream ss2;
    ss1<<t1; 
    ss2<<t2;
    CHECK(ss1.str()=="12:14:45");
    CHECK(ss2.str()=="12:02:13");
}

TEST_CASE("Input") 
{
    Time t1{};
    Time t2{};
    stringstream ss1{"25:14:45"};
    stringstream ss2{"22:02:13"};
    Time t1_new{25, 14, 45};
    Time t2_new{22, 02, 13};
    ss1>>t1; 
    ss2>>t2;
    CHECK(t1==t1_new);
    CHECK(ss1.fail());
    CHECK(t2==t2_new);
    CHECK_FALSE(ss2.fail());
}
