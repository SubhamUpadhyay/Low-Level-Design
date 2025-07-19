#pragma once
#include <string>
#include "Mediator.hpp" 

class Colleague{
    protected:
        Mediator *mediator;
    public:
        Colleague(Mediator *m):mediator(m){};
        virtual void receive(const string &messages) = 0;
        void send(const string&messages)
            {
                mediator->sendMessage(messages,this);
            }

            virtual ~Colleague(){};

};