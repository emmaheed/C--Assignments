int days_in_month() const
  {
    static constexpr const array<int, 13> days
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month < 1 || month > 12)
      return 0;
    
    if ( month == 2 && is_leap_year() )
      return 29;
    
    return days.at(month);
  }

  void next_date()
  {
    ++day;
    if ( day > days_in_month() )
    {
      day = 1;
      ++month;

      if (month > 12)
      {
        month = 1;
        ++year;
      }
    }
  }
  
  int year;
  int month;
  int day;
};

ostream& operator<<(ostream & os, Date const& d)
{
  return os << d.year << "-"
            << d.month << "-"
            << d.day;
}



const int DAYS_LATER{10000};

int main()
{
  int y,m,d;
  char c;
  bool good_date{false};

  cout << "Enter a date: ";
  
  while ( ! good_date )
    try
    {
      cin >> y >> c >> m >> c >> d;
      Date date{y, m, d};
      good_date = true;
  
      for ( int i{0}; i < DAYS_LATER; ++i )
      {
        date.next_date();
      }
      
      cout << DAYS_LATER << " days later: " << date;
    }
    catch (exception& e)
    {
      cerr << "Invalid date, enter another date: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  
  cout << endl;
  
  return 0;
}