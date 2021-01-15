#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Logfilename {
public:
    Logfilename():file_name(), end_fix() {};
    string name(int N) const {
       return "\"" + file_name + to_string(N) + "." + end_fix + "\"";
    };
    string name() const {
       return "\"" + file_name + "." + end_fix + "\"";
    };
    void rotate(int N) {
        cout << "The following commands will rotate the files:" << endl;
        
        for(int i{N}; i > 0; --i) {
            if (i > 1) { 
                cout << "mv " << name(i-1) << " " << name(i) << endl; 
            }
            else {
                cout << "mv " << name() << " " << name(N) << endl;
            }
        }

    };

    friend istream& operator>>(istream& is, Logfilename& f);
private:
string file_name;
string end_fix;
};

istream& operator>>(istream& is, Logfilename& f)
{
  getline(is, f.file_name, '.');
  return cin >> f.end_fix;
}

int main() {
cout << "What is the file name?" << endl;
Logfilename f{};
cin >> f;
cout << "What is the new highest numbered file?" << endl;
int N{};
cin >> N;
f.rotate(N); 

}