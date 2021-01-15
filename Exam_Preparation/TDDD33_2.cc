#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cerr << "Error: solution file argument missing" << endl;
        return 1;
    }

    ifstream ifs{argv[1]};

    if (!ifs) {
        cerr << "Error: solution file could not be opened" << endl;
        return 2;
    }

    cout << "Please enter given answer:" << endl;

    string given_answer;
    cin >> given_answer;
    if (given_answer.size() > 13) {
        cout << "WARNING: too many questions answered." << endl;
        given_answer = given_answer.substr(0,13);
    }
    else if (given_answer.size() < 13) {
        cout << "WARNING: too few questions answered." << endl;
        given_answer +=  "0000000000000";
        given_answer = given_answer.substr(0,13);
    }

    int i{};
    char correct_answer;
    int score{};
    while (ifs >> correct_answer) {
    if (tolower(given_answer.at(i)) == tolower(correct_answer)) {
        ++score;    
    }
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    i++;
    }
    
    cout << score << " point(s)" << endl;

}