#include <bits/stdc++.h>
using namespace std;

// ------------ Implementation Layer (Skills) ------------
class Skills {
public:
    virtual void skill() = 0;
    virtual ~Skills() {}
};

class HighJump : public Skills {
public:
    void skill() override {
        cout << "\nYou Obtained the skill: High Jump!";
    }
};

class LongJump : public Skills {
public:
    void skill() override {
        cout << "\nYou Obtained the skill: Long Jump!";
    }
};

class Power : public Skills {
public:
    void skill() override {
        cout << "\nYou Obtained the Power Skill. Your power has doubled!";
    }
};

// ------------ Abstraction Layer (Character) ------------
class Character {
protected:
    Skills* skilled;
public:
    Character(Skills* e) : skilled(e) {}
    virtual void character() = 0;
    virtual ~Character() {}
};

class CharacterRobin : public Character {
public:
    CharacterRobin(Skills* e) : Character(e) {}
    void character() override {
        cout << "\nCharacter Selected: Robin";
        skilled->skill();
    }
};

class CharacterKnight : public Character {
public:
    CharacterKnight(Skills* e) : Character(e) {}
    void character() override {
        cout << "\nCharacter Selected: Knight";
        skilled->skill();
    }
};

// ------------ Client Code ------------
int main() {
    Skills* jump = new LongJump();
    Skills* power = new Power();

    Character* c1 = new CharacterRobin(jump);
    Character* c2 = new CharacterKnight(power);

    c1->character();  // Robin with Long Jump
    c2->character();  // Knight with Power

    delete c1;
    delete c2;
    delete jump;
    delete power;

    return 0;
}
