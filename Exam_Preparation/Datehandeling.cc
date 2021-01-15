#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date
{
  int year;
  int month;
  int day;
};

// note: do your class version require parameters? Why not?
bool is_leap_year(int year)
{
  if ( year % 400 == 0 )
    return true;
  if ( year % 100 == 0 )
    return false;
  return year % 4 == 0;
}

// note: do your class version require parameters? Why not?
int days_in_month(int year, int month)
{
  static constexpr const std::array<int, 13> days
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  if (month < 1 || month > 12)
    return 0;
  
  if ( month == 2 && is_leap_year( year ) )
    return 29;
    
  return days.at(month);
}

Date create_date(int year, int month, int day)
{
  if ( month < 1 || month > 12 )
  {
    throw std::domain_error{"Month " + std::to_string(month) + " doesn't exist!"};
  }
  
  if (  day < 1 || day > days_in_month( year, month ) )
  {
    throw std::domain_error{"Day " + std::to_string(day) + " invalid"};
  }
  
  return {year, month, day};
}

std::ostream& operator<<(std::ostream& os, struct Date const& d)
{
  return os << setfill('0') << setw(2) << d.year << "-"
            << setw(2) << d.month << "-"
            << setw(2) << d.day;
}

string to_string(int number) {
    stringstream ss; 
    ss << number; 
    return ss.str();
}  

Date next_date(Date & d) {
    if (d.day == days_in_month(d.year, d.month)) {
        d.day = 1;
        if (d.month == 12) {
            d.month = 1;
            d.year++;
        }
        else { 
            d.month += 1;
        }   
    }
    else {    
        d.day++;
    }
    return d;
}

bool is_valid(int year, int month, int day) {
    return (0 < day) && (day <= days_in_month(year, month)) && (0 < month < 12);
}

int main() {

int year{};
int month{};
int day{};  

cout << "Enter a date:" << endl;

cin >> year;
cin.ignore(1, '-');
cin >> month;
cin.ignore(1, '-');
cin >> day; 

while (!is_valid(year, month, day)) {
    cout << "Invalid date, enter another date:" << endl;
    cin >> year;
    cin.ignore(1, '-');
    cin >> month;
    cin.ignore(1, '-');
    cin >> day; 
}

Date d{create_date(year, month, day)};
int N{};
while(N < 10000) {
    next_date(d);
    N++;
}

cout << "10000 days later: " << d << endl;

}