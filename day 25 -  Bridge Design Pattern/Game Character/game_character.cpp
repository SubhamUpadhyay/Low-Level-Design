#include<bits/stdc++.h>
using namespace std;

//.......................................Abstraction...................................................................
class Skills{
    public:
    virtual void skill() = 0;
    ~Skills(){};
};
class HighJump : public Skills{
    public:
    void skill() override{
        cout<<"\n You Obtained the skill : high jump !";
    }
};

class LongJump : public Skills{
    public :
        void skill() override{
            cout<<"\n You Obtained the skill : Long Jump\n";
        };
};

class Power : public Skills{
    public:
        void skill() override{
            cout<<"\n You Obtained the Power Skill . Your power have been doubled:";
        };
};

//...................................................Implementation.............................................................
class Character{
    protected:
    Skills *skilled;
    public:
        Character(Skills *e):skilled(e){};
        virtual void character() = 0;
};

class CharacterRobin : public Character{
    public:
        CharacterRobin(Skills *e):Character(e){};
        void character() override{
            cout<<"\n Character Selected Robin \n";
            skilled->skill();

        };
};


int main()
{
    LongJump *lj = new LongJump();
    Character *c1 = new CharacterRobin(lj);
    c1->character();
    delete lj, c1;
    return 0;
}