#include <iostream>
#include "ConcreteMediator.hpp"
#include "ConcreteColleague.hpp"

using namespace std;

int main() {
    ConcreteMediator* mediator = new ConcreteMediator();

    ConcreteColleague* c1 = new ConcreteColleague(mediator, "Alice");
    ConcreteColleague* c2 = new ConcreteColleague(mediator, "Bob");
    ConcreteColleague* c3 = new ConcreteColleague(mediator, "Charlie");

    mediator->addColleague(c1);
    mediator->addColleague(c2);
    mediator->addColleague(c3);

    c1->send("Hello Everyone!");
    c2->send("Hi Alice");

    delete c1;
    delete c2;
    delete c3;
    delete mediator;

    return 0;
}
