#ifndef TIME_H
#define TIME_H
#include <string>

struct Time {
    int HH; 
    int MM; 
    int SS;
    };

bool is_valid(Time const& t);
std::string to_string(Time t, bool b=false);
Time operator+(Time t, int const N);
Time operator-(Time t, int const N);
Time& operator++(Time& t);
Time operator++(Time& t, int);
Time& operator--(Time& t);
Time operator--(Time& t, int);
bool operator==(Time const& t1, Time const& t2);
bool operator!=(Time const& t1, Time const& t2);
bool operator<(Time const& t1, Time const& t2);
bool operator>(Time const& t1, Time const& t2);
bool operator<=(Time const& t1, Time const& t2);
bool operator>=(Time const& t1, Time const& t2);
std::ostream & operator<<(std::ostream & os, Time & t);
std::istream & operator>>(std::istream & is, Time & t); 
#endif
