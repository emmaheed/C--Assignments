#include <iostream>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>

const std::map< int, const std::vector<char> > scores{
  { 1, {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'} },
  { 2, {'D', 'G'} },
  { 3, {'B', 'C', 'M', 'P'} },
  { 4, {'F', 'H', 'V', 'W', 'Y'} },
  { 5, {'K'} },
  { 8, {'J', 'X'} },
  { 10,{'Q', 'Z'} }
};

int score(std::map<char, int> const& char_to_value,
          std::string const& word)
{
  int sum{0};
  for_each(word.cbegin(), word.cend(),
           [&char_to_value,&sum](char c)->void
           {
             sum += char_to_value.at(toupper(c));
           });
  return sum;
}

int main()
{
  std::map<char, int> char_to_value;
  for ( auto && p : scores )
  {
    int value{p.first};
    for ( auto && c : p.second )
    {
      char_to_value[c] = value;
    }
  }

  std::string word;

  std::cout << "Enter words: " << std::endl;
  while ( std::cin >> word )
  {
    std::cout << '"' << word << '"'
              << " gives " << score(char_to_value, word) << " points."
              << std::endl;
  }
  return 0;
}