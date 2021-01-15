//Remember getline() One word at a time  

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

bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
    return (a.second > b.second);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Error: No arguments given" << '\n'
             << "Usage: a.out FILE" << endl;
        return 1;
    }
    
    ifstream ifs{argv[1]};
    
    if (!ifs) {
        cerr << "Error: No file named " << "\"" << argv[1] << "\"" << '\n'
             << "Usage: a.out FILE" << endl; 
        return 1;
    }
   
    map <string, int> m{};
    string line;

    while (getline(ifs, line)) {
        stringstream ss{line};
        int question{};
        string player;
        string correct; 
        int score{};
        int score_no_bonus{};

        ss >> question >> player >> correct >> score >> score_no_bonus; 
        m[player] += score;
    }

    vector<pair<string, int>> v_p;
    move(m.begin(), m.end(), back_inserter(v_p));
    sort(v_p.begin(), v_p.end(), sortbysec);
    cout << "1st place: " << v_p[0].first << " with " << v_p[0].second << " total points" << endl;
    cout << "2nd place: " << v_p[1].first << " with " << v_p[1].second << " total points" << endl;
    cout << "3rd place: " << v_p[2].first << " with " << v_p[2].second << " total points" << endl;
}