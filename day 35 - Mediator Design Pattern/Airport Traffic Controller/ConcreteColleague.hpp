#pragma once
#include "Colleague.hpp"    
#include <iostream>

class ConcreteColleague : public Colleague{
    private:
        string name;
    public:
        ConcreteColleague(Mediator *m , const string &n):Colleague(m),name(n){};
        void receive(const string &messages) override{
            cout<<"\n "<<name<<" received : "<<messages<<endl;
        }

        const string& getName() const{
            return name;
        };
};