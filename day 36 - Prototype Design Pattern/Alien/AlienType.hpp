#pragma once
#include "Alien.hpp"

class AlienType : public Alien {
private:
    string name, planet, color, power;

public:
    AlienType(string planet, string color)
        : planet(planet), color(color), name("Unknown"), power("None") {}

    AlienType(const AlienType& other)
        : name(other.name), planet(other.planet), color(other.color), power(other.power) {}

  
    Alien* clone() override {
        return new AlienType(*this);  // Triggers copy constructor
    }

    void setMissing(string name, string power) override {
        this->name = name;
        this->power = power;
    }

    void print() override {
        cout << "..................................Alien Info..................................\n";
        cout << "Name   : " << name << "\n";
        cout << "Planet : " << planet << "\n";
        cout << "Color  : " << color << "\n";
        cout << "Power  : " << power << "\n";
        cout << "..............................................................................\n\n\n\n";
    }
};
