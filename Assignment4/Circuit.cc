#include "Circuit.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

//Constructor
Component::Component(std::string const & name, 
    Connection & a, Connection & b):name{name}, a{a}, b{b} {}

//The new charge at points connected to a battery for a simulation
void Battery::update(double const & t) {
    a.charge = voltage;
    b.charge = 0.0; 
}

//The new charge at points connected to a resistor for simulation. Charge taken from the most positive point
void Resistor::update(double const & t) {
    double Pd{get_potential()};
    double voltage_to_move{(Pd/resistance)*t};
    Connection* greatest;
    Connection* smallest;
    
    if (a.charge > b.charge) {
        greatest = &a;
        smallest = &b;
    }
    else { 
        greatest = &b;
        smallest = &a;
    }
    greatest->charge -= voltage_to_move;
    smallest->charge += voltage_to_move;
}

//The new charge at points connected to a capacitor and its new stored charge for a simulation
void Capacitor::update(double const & t) {
    double Pd{get_potential()};
    double voltage_to_move{capacitance*(Pd-s)*t};
    Connection* greatest;
    Connection* smallest;
    
    if (a.charge > b.charge) {
        greatest = &a;
        smallest = &b;
    }
    else { 
        greatest = &b;
        smallest = &a;
    }
    greatest->charge -= voltage_to_move;
    smallest->charge += voltage_to_move;  
    s += voltage_to_move;
}

//Get potential difference between connection points for a resitor or capacitor
double Component::get_potential() const {
    return abs(b.charge-a.charge);
}

//Get potential difference between conncetion points for a battery 
double Battery::get_potential() const {
    return voltage;
}

//Get current for a battery 
double Battery::get_current() const {
    return 0;
}

//Get current for a resistor
double Resistor::get_current() const {
    return get_potential()/resistance;
}

//Get current for a capacitor
double Capacitor::get_current() const {
    return capacitance*(get_potential() - s); //C(V-L)
}

//Get the name of a component
string Component::get_name() const {
    return name;
} 




