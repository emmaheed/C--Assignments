#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <string>

struct Connection {
    double charge{0};
};

class Component {
    public:
        Component(std::string const & name, Connection & a, Connection & b);
        virtual ~Component() = default;
        virtual void update(double const & t) = 0; //Get new charge at connection points 
        virtual double get_current() const = 0; //Get current over every component  
        virtual double get_potential() const; //Potential difference between connection points
        std::string get_name() const;

    protected:
        std::string name;
        Connection & a;
        Connection & b; 
};

class Battery : public Component {
    public:
        Battery(std::string const & name, Connection & a, Connection & b, 
        double const voltage)
            :Component(name, a, b), voltage{voltage}{};
        ~Battery() = default;
        void update(double const & t) override;
        double get_current() const override; 
        double get_potential() const override;
    private:
        double const voltage{};
};

class Capacitor : public Component {
    public:
        Capacitor(std::string const & name, Connection & a, Connection & b, 
        double const capacitance)
            :Component(name, a, b),capacitance{capacitance}, s{}{}; //Create a capacitor with a stored charge 
        ~Capacitor() = default;
        void update(double const & t) override;
        double get_current() const override; 
    
    private:
        double const capacitance{};
        double s; // Stored charge in the capacitor. Zero initially then increases 
};

class Resistor : public Component {
    public:
        Resistor(std::string const & name, Connection & a, Connection & b, 
        double const resistance)
            :Component(name, a, b),resistance{resistance}{};
        ~Resistor() = default;
        void update(double const & t) override;
        double get_current() const override;

    private:
        double const resistance{};
};

#endif
