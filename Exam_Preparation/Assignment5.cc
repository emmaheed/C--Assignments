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

int main() {
    cout << "$. Enter the sentence to translate, one per line (finish by Ctrl-D):" << endl;

    istream_iterator <string> iis{cin};
    istream_iterator <string> eos{};
    vector <string> v{iis,eos};

    string vowel{"aeiouy"};
    string word_ending{"ay"};
    string ad_after_40_char{"..."};

    transform(begin(v), end(v), begin(v), 
        [&vowel,&word_ending](string s) {
        auto first = s.find_first_of(vowel);
       
        if (first == 0) {
            return s + 'y' + word_ending;
        }
        else {
            return s.substr(first, s.size() - 1) 
                + s.substr(0, first) + word_ending;;
        } 
    });

    ostream_iterator<string> oos{cout, " "};
    int n{40};
    copy_if(begin(v), end(v), oos, [&n](string s) {
            n -= s.size();
            if (--n <= 0) return false;
            return true;
            });

    if (n < 0) {
        cout << "..." << endl;
    }
    //After the 40th output character end the output with... 
    //if a word starts with at vowel 
    //if a word starts with a constant 
} 