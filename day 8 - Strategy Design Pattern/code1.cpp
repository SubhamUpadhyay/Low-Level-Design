#include<bits/stdc++.h>
using namespace std;
//design the strategy for talkable
class talkable{
    public:
    virtual void talk()=0;
    virtual ~talkable(){};
};


//concrete classes for talk
class simpleTalk:public talkable{
    public:
        void talk() override{
            cout<<endl<<"Nomal Talk";
        }    
};

class noTalk:public talkable{
    public:
        void talk() override{
            cout<<endl<<"No talk ..";
        }
};



//design the strategy pattern for the walkable
class walkable{
    public:
    virtual void walk() = 0;
    virtual ~walkable(){};
};


//concrete classes for walk
class simpleWalk : public walkable{
    public:
    void walk() override{
        cout<<endl<<"Simple Walk";

    }
};

class noWalk:public walkable{
    public:
    void walk() override{
        cout<<endl<<"No walk";
    }
};

//strategy Design Pattern for the Flyable
class flyable{
    public:
    virtual void fly() = 0;
    virtual ~flyable(){};    
};


//concerete class for fly
class simpleFly : public flyable{
    public:
    void fly() override{
        cout<<endl<<"Normal Fly";
    }
};

class noFly : public flyable{
    public:
    void fly() override{
        cout<<endl<<"No fly";
    }
};


class robot{
    private:
        talkable *t;
        walkable *w;
        flyable *f;
    public:
        robot(talkable *t ,walkable *w , flyable *f)
        {
            this->t = t;
            this->w = w;
            this->f = f;
        }

        void talk(){
            t->talk();
        };
        void walk(){
            w->walk();
        };
        void fly(){
            f->fly();
        };

        virtual void projection() = 0;
};





class companionRobot:public robot{
    public:
    companionRobot(talkable *t , walkable *w, flyable *f)
        :robot(t,w,f){};
    void projection() override{
        cout<<endl<<"Companion Robot";
    }
};


class workingRobot:public robot{
    public:
    workingRobot(talkable *t, walkable *w, flyable *f)
        :robot(t,w,f){};
    void projection() override{
        cout<<endl<<"Working Robot";
    }
};

int main()
{

    robot *robot1 = new companionRobot(new simpleTalk{},new simpleWalk{},new noFly{});
    robot1->projection();
    robot1->talk();
    robot1->walk();
    robot1->fly();
   
    cout<<"\n\n\n\n";

    robot *robot2  = new workingRobot(new noTalk{}, new noWalk{},new simpleFly{});
    robot2->projection();
    robot2 -> talk();
    robot2 -> walk();
    robot2 -> fly();
    return 0;
}
