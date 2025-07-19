#pragma once
#include "Mediator.hpp"
#include "ConcreteColleague.hpp"
#include <vector>

class ConcreteMediator : public Mediator {
    vector<ConcreteColleague*> colleagues;

public:
    void addColleague(ConcreteColleague* c) {
        colleagues.push_back(c);
    }

    void sendMessage(const string& message, Colleague* sender) override {
        for (auto* c : colleagues) {
            if (c != sender) {
                c->receive(message);
            }
        }
    }
};
