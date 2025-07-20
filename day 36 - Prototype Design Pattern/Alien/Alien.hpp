#pragma once
#include <iostream>
#include <string>
using namespace std;

class Alien {
public:
    virtual Alien* clone() = 0;
    virtual void setMissing(string name, string power) = 0;
    virtual void print() = 0;
    virtual ~Alien() {}  
};
