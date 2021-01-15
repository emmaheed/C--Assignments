#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <type_traits>

using namespace std;
int main() {

    // Define datatypes
    string word{};  // Gets every word in the textfile  
    int no_words{}; // Integer that counts number of word
    string sw{}; // To find the shortest word
    string lw{}; // To find the longest word
    float av{}; // Average length
    int size{}; // Word size

    ifstream ifs{"textfil.txt"}; // Reads the textfile
    while (ifs >> word) { // Gets every word out of the file
        no_words++; // For every loop, add 1 to count
        size += word.size(); // Adds number of characters to count
        if (word.size() < sw.size() or sw.size()==0) { // If current word is shorter than shortest word
                sw=word;
        }  
        if (word.size() > lw.size() or lw.size()==0) { // If current word is longer than the longest word
                lw=word;
        } 
    }
    
    if (word.size() == 0){
        cout << "ERROR: Empty textfile" << endl;
    }
    else {

        av=size/no_words; // Average number of character per word
        
        // Outputs 
        cout << "There are "<< no_words << " words in the file." 
            << endl;
        cout << "The shortest word was \""<< sw << "\" with " 
            << sw.size() << " character(s)." << endl;
        cout << "The longest word was \""<< lw << "\" with " 
            << lw.size() << " character(s)." << endl;       
        cout << "The average length was " << setprecision(2) << fixed 
            << av << " character(s)." << endl;
    }
}