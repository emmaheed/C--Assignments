#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    // Define datatypes
    int x{};
    float y{};
    char z{};
    string s{};

    // Question 1
    cout << "Enter one integer:" << endl;
    cin >> x; 
    cin.ignore(1000, '\n'); // Ignores remaining input
    cout << "You entered the number: ";
    cout << x << endl;

    // Question 2
    cout << "Enter four integers:" << endl; 
    cin >> x; 
    cout << "You entered the numbers: ";
    cout << x <<" ";
    cin >> x; 
    cout << x <<" ";
    cin >> x; 
    cout << x <<" ";
    cin >> x; 
    cin.ignore(1000, '\n');
    cout << x << endl;

    // Question 3
    cout << "Enter one integer and one real number:" << endl;
    cin >> x; 
    cin >> y; 
    cin.ignore(1000, '\n');
    cout << "The real is: " ;
    cout << setfill(' ') << setw(11) << setprecision(3)<< fixed // 3 decimals
         << y << endl; // Total of 11 characters, starting with spaces
    cout << "The integer is: " ;
    cout << setfill(' ') << setw(8) << x << endl;

    // Question 4
    cout << "Enter one real and one integer number:" << endl;
    cin >> y;
    cin >> x; 
    cin.ignore(1000, '\n');
    cout << "The real is: ";
    cout << setfill('.') << setw(11) << setprecision(3)<< fixed 
         << y << endl; // Total of 11 characters, starting with dots
    cout << "The integer is: ";
    cout << setfill('.') << setw(8) << x << endl;

    // Question 5
    cout << "Enter a character:" << endl;
    cin >> z; 
    cin.ignore(1000, '\n');
    cout << "You entered: ";
    cout << z << endl;

    // Question 6
    cout << "Enter a word:" << endl;
    cin >> s; 
    cin.ignore(1000, '\n');
    cout << "The word '" << s << "' has " << s.size() 
         << " character(s)." << endl;

    // Question 7
    cout << "Enter an integer and a word:" << endl;
    cin >> x;
    cin >> s; 
    cin.ignore(1000, '\n');
    cout << "You entered '"<< x <<"' and '"<< s <<"'."<< endl;

    // Question 8
    cout << "Enter a character and a word:" << endl;
    cin >> z;
    cin >> s; 
    cin.ignore(1000, '\n');
    cout << "You entered the string \""<< s 
         <<"\" and the character '"<< z <<"'."<<endl;

    // Question 9
    cout << "Enter a word and a real number:" << endl;
    cin >> s;
    cin >> y; 
    cin.ignore(1000, '\n');
    cout << "You entered \""<< s <<"\" and \""<< setprecision(3)  
         << fixed << y <<"\"."<<endl; 

    // Question 10
    cout << "Enter a text-line:" << endl;
    getline(cin, s); 
    cout << "You entered: \""<< s << "\"" <<  endl;

    // Question 11
    cout << "Enter a second line of text:" << endl;
    getline(cin, s); 
    cout << "You entered: '"<< s << "\"" <<  endl;

    // Question 12
    cout << "Enter three words:" << endl;
    cin >> s; 
    cout << "You entered: '" ;
    cout << s <<" ";
    cin >> s; 
    cout << s <<" ";
    cin >> s; 
    cin.ignore(1000, '\n');
    cout << s <<"'"<< endl;

} 

