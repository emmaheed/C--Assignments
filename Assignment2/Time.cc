#include "Time.h"
#include <iostream>
#include <string>
#include <stdlib.h> 
#include <sstream> 
#include <iomanip>
using namespace std;

//Check if the time is valid
bool is_valid(Time const& t) {
    return t.HH <= 23 && t.HH >= 0 && t.MM <= 59 
        && t.MM >= 0 && t.SS <= 59 && t.SS >= 0;
}

//Check if the time is am or pm and return a time string
string to_string(Time t, bool b) {
    stringstream ss;
    if (b==false) {
        if (t.HH>=12) {
            if (t.HH>12) {
                t.HH=t.HH-12;}
            ss << setfill('0') << setw(2) << t.HH << ":" << setw(2) 
            << t.MM << ":" << setw(2) << t.SS << " pm";    
        }
        else {
            if (t.HH == 0) {
                t.HH = 12;}
            ss << setfill('0') << setw(2) << t.HH << ":" << setw(2) 
            << t.MM << ":" << setw(2) << t.SS << " am";
        }
    }

    else {
        ss << setfill('0') << setw(2) << t.HH << ":" << setw(2) 
            << t.MM << ":" << setw(2) << t.SS;   
    }
    return ss.str();
}

//Adding seconds 
Time operator+(Time t, int const N) {
    int tot_time;
    tot_time=t.HH*3600+t.MM*60+t.SS+N;
    t.HH=tot_time/3600;
    t.MM=(tot_time%3600)/60;
    t.SS=(tot_time%3600)%60;
    t.HH=t.HH%24; //Needed if hours are over 23
    return t; 
}

//Substract seconds
Time operator-(Time t, int const N) {
    int tot_time;
    int n;      
    tot_time=t.HH*3600+t.MM*60+t.SS-N;
    if (tot_time <0) {                  
        n=tot_time/(-86400); //Calculate how many days to substract            
        tot_time=86400*(1+n)+tot_time;    
    }
    t.HH=tot_time/3600;
    t.MM=(tot_time%3600)/60;
    t.SS=(tot_time%3600)%60;
    t.HH=t.HH%24;
    return t;
}

//Pre-fix, Add a second
Time& operator++(Time & t) {
    Time tmp{t};
    t=tmp+1; 
    return t; 
}

//Post-fix, Add a second
Time operator++(Time & t, int) {
    Time tmp{t};
    tmp=t+1;  
    return tmp; 
}

//Pre-fix, Substract a second
Time& operator--(Time & t) {
    Time tmp{t};
    t=tmp-1;
    return t; 
}

//Post-fix, Substract a second
Time operator--(Time & t, int) {
    Time tmp{t};
    tmp=t-1;
    return tmp; 
}

//Comparison ==
bool operator==(Time const& t1, Time const& t2){
    return t1.HH==t2.HH && t1.MM==t2.MM && t1.SS==t2.SS;
}

//Comparison !=
bool operator!=(Time const& t1, Time const& t2) {
    return !(t1==t2);
}

//Comparison <
bool operator<(Time const& t1, Time const& t2) {
    return (t1.HH<t2.HH) or (t1.HH==t2.HH && t1.MM<t2.MM) or (t1.HH==t2.HH 
           && t1.MM==t2.MM && t1.SS<t2.SS);
}

//Comparison >
bool operator>(Time const& t1, Time const& t2) {
    return !(t1<t2);
}

//Comparison <=
bool operator<=(Time const& t1, Time const& t2) {
    return t1==t2 or t1<t2; 
}

//Comparison >=
bool operator>=(Time const& t1, Time const& t2) {
    return t1==t2 or t1>t2; 
}

//Output
ostream & operator<<(ostream & os, Time & t) {
    os << setfill('0') << setw(2) << t.HH << ":" << setw(2) 
           << t.MM << ":" << setw(2) << t.SS ;
    return os;
}

//input
istream & operator>>(istream & is, Time & t) {
    is >> t.HH;
    is.ignore(1, '\n');
    is >> t.MM;
    is.ignore(1, '\n');
    is >> t.SS;
    
    if (!is_valid(t)) {
        is.setstate(ios_base::failbit); //Set the fail-flag
    }
    return is;
}
