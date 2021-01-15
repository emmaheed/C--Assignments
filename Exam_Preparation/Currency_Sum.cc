#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <iterator>
#include <map>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[]) {

    if ( argc != 2 )
    {
        cerr << "Usage: " << argv[0] << " FILE" << endl;
        return 1;   
    }
    
    ifstream ifs{argv[1]};
    if ( ! ifs )
    {
        cerr << "File '" << argv[1] << "' could not be opened." << endl;
        return 1;
    }

    string file;
    string currency{};
    map <string, double> m{};
    double sum;
   
    while (getline(ifs, file)) {
        stringstream ss{file};
        double rate{};
        
        ss >> currency >> rate;
        m[currency] += rate;   
    }
    
    cout << "Enter amounts (finish by Ctrl-D):" << endl;

    string line; 
   
    while ( getline(cin, line) ) {
    istringstream iss(line);

    double value;
    if ( iss >> value )
    {
      if ( iss >> currency )
        sum += value * m.at(currency);
      else
        sum += value;
    }
    }

    cout << "Total amount in SEK: "
       << setprecision(2) << fixed << sum << endl;
      
}

