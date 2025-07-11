#include <iostream>
#include <string>
using namespace std;

// Interface
class character {
public:
    virtual string getAbilities() const = 0;
    virtual ~character() {}
};

// Concrete Component
class Mario : public character {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

// Abstract Decorator
class characterDecorator : public character {
protected:
    character* chr;  // wrapped object
public:
    characterDecorator(character* chr) : chr(chr) {}
};

// Concrete Decorator: HeightUp
class heightUp : public characterDecorator {
public:
    heightUp(character* c) : characterDecorator(c) {}
    string getAbilities() const override {
        return chr->getAbilities() + " with HeightUp";
    }
};

// Concrete Decorator: FirePower
class firePower : public characterDecorator {
public:
    firePower(character* c) : characterDecorator(c) {}
    string getAbilities() const override {
        return chr->getAbilities() + " with FirePower";
    }
};

// Concrete Decorator: Shield
class shield : public characterDecorator {
public:
    shield(character* c) : characterDecorator(c) {}
    string getAbilities() const override {
        return chr->getAbilities() + " with Shield";
    }
};

// Main function to demonstrate
int main() {
    character* mario = new Mario();
    cout << "Basic: " << mario->getAbilities() << endl;

    mario = new heightUp(mario);
    mario = new firePower(mario);
    mario = new shield(mario);

    cout << "Powered-up: " << mario->getAbilities() << endl;

    delete mario;  // only deletes the outermost wrapper
    return 0;
}
