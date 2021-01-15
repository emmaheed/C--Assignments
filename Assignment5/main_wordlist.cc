#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <cctype>
using namespace std;

// Function to see if word is valid. Check if word has only letters, only one hyphen, more than 2 letters
bool is_valid(string & s) {
    return (all_of(s.begin(), s.end(), [](char c){ return isalpha(c) || c == '-' ; })
            && s.size() > 2 && s.find("--") != true); 
}
// Sort by second element in pair (number)
bool sortbysec(const pair<string, int> &a, const pair<string,int> &b) {
    return (a.second > b.second);
}

int main(int argc, char* argv[]) {
    // Check number of user input
    if (argc < 2) {
        cout << "No arguments given" << '\n' 
             << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }

    if (argc < 3) {
        cout << "Second argument missing or invalid" << '\n' 
             << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }

    string file = argv[1];
    string type = argv[2];
    int ch;

    // Check type of user input
    if ((type != "-a") && (type != "-f") && (type != "-o")) {
        cout << "Second argument missing or invalid" << '\n' 
             << "Usage: a.out FILE [-a] [-f] [-o N]" << endl;
        return 1;
    }

    if (type == "-o") {
    try {
        ch = stoi(argv[3]);
    }
    catch(exception & e) {
        cerr << "Third argument wrong" << '\n' 
             << "Usage: a.out FILE [-a] [-f] [-o N]" <<endl;
        return 1;
    }
    }
    
    // Declarations
    string l_junk{"\"'(-"}; //Left junk
    string r_junk{")!?;,.:\"'-"}; //Right junk
    ifstream ifs{file};
    istream_iterator <string> iis{ifs};
    istream_iterator <string> eos{};
    vector <string> v{iis, eos}; 
    map <string, int> m{};
    vector <string> v_new{};
    vector<pair<string, int>> v_p{};
    vector<string>::iterator max{};
       
    transform(v.begin(), v.end(), v.begin(), [&l_junk, &r_junk](string s) { 
        // Remove junk
        auto first = s.find_first_not_of(l_junk);
        s = s.substr(first);
        int last = s.find_last_not_of(r_junk);
        s = s.substr(0, last + 1);  

        // Remove 's
        string s_junk = s.substr(s.size() - 2, s.size() - 1);
        if(s_junk == "'s") {
            s = s.substr(0, s.size() - 2);
        }
        return s;
    });

    for_each(v.begin(), v.end(), [&m, &v_new, &type](string s) {
        // Transform to lower case letters. Put in map
        if(is_valid(s)) {
            transform(s.begin(), s.end(), s.begin(), [](char c) { return tolower(c);});
            if (type == "-a" || type == "-f")
                m[s]++; 
            v_new.push_back(s);
        }
    }); 

    // Sort and print
    if (type == "-a" || type == "-f") {
        max = max_element(v_new.begin(), v_new.end(), [](string const a,string const b) {
            return b.size() > a.size();
        });
        move(m.begin(), m.end(), back_inserter(v_p));
        if (type == "-a") {
            for_each(v_p.begin(), v_p.end(), [&v_p,&max](pair <string, int> p) {
                cout.width(max -> size());
                cout << left << p.first << "  " << left << p.second << endl;
            });
        }
        else {
            sort(v_p.begin(), v_p.end(), sortbysec);
            for_each(v_p.begin(), v_p.end(), [&v_p,&max](pair <string, int> p) {
                cout.width(max -> size()); 
                cout << right << p.first << "  " << right << p.second << endl;
            });
        }
    }   

    // Print words 
    else if (type == "-o") {
        int i{};
        for_each(v_new.begin(), v_new.end(), [&v_new,&ch,&i](string s) {
            i += (s.size() + 1);
            if (ch <= i) {
                cout << endl;
                i = 0;
            } 
            cout << s << " ";
        });
        cout << endl;
    }
}