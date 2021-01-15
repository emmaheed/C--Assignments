#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    // Define datatypes
    float fp{}; // First price
    float lp{}; // Last price
    float st{}; // Stride
    float tax{}; // Tax percent
    float i{}; // For for loop

    cout << "Enter first price: " << endl;
    cin >> fp; 
    cin.ignore(1000, '\n');
    
    while (fp < 0) {
        cout << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << "Enter first price: " << endl;
        cin >> fp; 
        cin.ignore(1000, '\n');
        }
   
    cout << "Enter last price: " << endl;
    cin >> lp; 
    cin.ignore(1000, '\n');
    
    while(lp<0 or lp<=fp){
        cout << "ERROR: Last price must be larger than first price and at least 0 (zero) SEK" << endl;
        cout << "Enter last price: " << endl;
        cin >> lp; 
        cin.ignore(1000, '\n');
    }

    cout << "Enter stride: " << endl;
    cin >> st; 
    cin.ignore(1000, '\n');
    
    while (st < 0.01) {
        cout << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride: " << endl;
        cin >> st; 
        cin.ignore(1000, '\n');
    }

    cout << "Enter tax percent: " << endl;
    cin >> tax; 
    cin.ignore(1000, '\n');
    while (tax < 0) {
        cout << "ERROR: tax must be at least 0 (zero) " << endl;
        cout << "Enter tax: " << endl;
        cin >> tax; 
        cin.ignore(1000, '\n');
    }

    // Table heading
    cout << setfill(' ') << setw(10) << "Price" ;
    cout << setfill(' ') << setw(10) << "Tax" ;
    cout << setfill(' ') << setw(20) << "Price with tax" << endl;
    cout << setfill('-') << setw(40) << "-"<< endl;


    // Table content
    for (i=fp; i <= lp; i=i+st) { // Loops from the first price to last with stride
        cout << setfill(' ') << setw(10) << setprecision(2)<< fixed << i ;
        cout << setfill(' ') << setw(10) << setprecision(2)<< fixed 
            << (tax/100)*i ;
        cout << setfill(' ') << setw(20) << setprecision(2)<< fixed 
            << i+(tax/100)*i << endl;  
    }    



}