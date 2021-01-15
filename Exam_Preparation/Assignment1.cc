#include <iostream>
#include <iomanip>
using namespace std;

int main() {
//Define datatypes 
int x{};
int y{};
int z{};

cout << "Welcome to dose track!" << endl;

cout << "What is the total amount of medicine (in gram)?" << endl;
cin >> x;

cout << "Over how many hours do you want to take the medicine?" << endl;
cin >> y;

z=x-((x/y)*y);

cout << "The dosage is:";
for (int t{}; t < y; t++) {
    if(t < z) {
        cout << (x/y)+1 << " ";
    }
    else {
        cout << (x/y) << " ";
    }    
}
cout << endl;

}