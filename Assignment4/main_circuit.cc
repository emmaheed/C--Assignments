#include "Circuit.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Simulation function
void simulate(vector<Component*> & net, int const & iterations, int const & lines, 
    double const & t) {
    int k;
    k = iterations/lines;
    cout << setprecision(2) << fixed;
    
    //Print out the first row with names of the components 
    for (int m{}; m < net.size(); ++m) { 
        cout << setfill(' ') << setw(16) << net.at(m) -> get_name();
    }
    cout << endl;

    //Print out the second row to create columns for volt and current
    for (int m{}; m < net.size(); ++m) {
        cout << setfill(' ') << setw(8) << "Volt" << setfill(' ') << setw(8) << "Curr" ;
    }
    cout << endl;
    
    //Print out the volt and current for every component 
    for(int j{}; j <= iterations; ++j) {
        for(int i{}; i < net.size(); ++i) {
            net.at(i) -> update(t);   
        }
        if(j == k) { 
            for(int n{}; n < net.size(); ++n) {
                cout << setfill(' ') << setw(8) << net.at(n) -> get_potential();
                cout << setfill(' ') << setw(8) << net.at(n) -> get_current();    
            }  
            cout << endl;   
            k += (iterations/lines);   
        }     
    }    
}

//Delete vectors from memory 
void deallocate_components(vector<Component*> net)  {
    for (int i{};i < net.size();i++) {
        delete (net[i]);
    }
    net.clear();
}

//Main program, write input as: ./a.out int int double double
int main(int argc, char* argv[]) {

    int it; //First input: Number of iterations
    int li; //Second input: Number of printed lines
    double ti; //Third input: Time units for a simulation
    double volt; //Forth input: Volt for the battery 

    //Find any wrong input 
    try{
        it=stoi(argv[1]);
    }
    catch(exception & e) {
        cerr<<"Första argumentet var fel"<<endl;
        return 1;
    }
    try{
        li=stoi(argv[2]);
    }
    catch(exception & e) {
        cerr<<"Andra argumentet var fel"<<endl;
        return 2;
    }
    try{
        ti=stod(argv[3]);
    }
    catch(exception & e) {
        cerr<<"Tredje argumentet var fel"<<endl;
        return 3;
    }
    try{
        volt=stoi(argv[4]);
    }
    catch(exception & e) {
        cerr<<"Fjärde argumentet var fel"<<endl;
        return 4;
    }

    //Create circuit one
    {
        vector<Component*> net1;
        Connection p1,n1,R124,R23;
        net1.push_back(new Battery("Bat", p1, n1, volt));
        net1.push_back(new Resistor("R1", p1, R124, 6.0));
        net1.push_back(new Resistor("R2", R124, R23, 4.0));
        net1.push_back(new Resistor("R3", R23, n1, 8.0));
        net1.push_back(new Resistor("R4", R124, n1, 12.0));
        simulate(net1, it, li, ti);
        deallocate_components(net1);
    }

    //Create circuit two
    {
        vector<Component*> net2;
        Connection p2,n2,l2,r2;
        net2.push_back(new Battery("Bat", p2, n2, volt));
        net2.push_back(new Resistor("R1", p2, l2, 150));
        net2.push_back(new Resistor("R2", p2, r2, 50));
        net2.push_back(new Resistor("R3", l2, r2, 100));
        net2.push_back(new Resistor("R4", l2, n2, 300));
        net2.push_back(new Resistor("R5", r2, n2, 250));
        simulate(net2, it, li, ti);
        deallocate_components(net2);
    }

    //Create circuit three
    {
        vector<Component*> net3;
        Connection p3, n3, l3, r3;
        net3.push_back(new Battery("Bat", p3, n3, volt));
        net3.push_back(new Resistor("R1", p3, l3, 150));
        net3.push_back(new Resistor("R2", p3, r3, 50));
        net3.push_back(new Capacitor("C3", l3, r3, 1));
        net3.push_back(new Resistor("R4", l3, n3, 300));
        net3.push_back(new Capacitor("C5", r3, n3, 0.75));
        simulate(net3, it, li, ti);
        deallocate_components(net3);
    }

}

