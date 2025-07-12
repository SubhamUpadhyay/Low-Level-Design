#include<bits/stdc++.h>
using namespace std;

//............................................. Implementation Layer .......................................
class IEngine{
    public:
    virtual void start() = 0;
    ~IEngine(){};
};
class ElectricEngine : public IEngine{
    public:
    void start() override{
        cout<<"\n Car started Silently \n";
    };
};

class DisealEngine : public IEngine{
    public:
    void start() override{
        cout<<"\n Car started with Roar !\n";
    };

};

class HybridEngine : public IEngine{
    public:
    void start() override{
        cout<<"\n Car started in Eco Friendly Mode !\n";
    };
};

//................................................. Abstraction Layer ...........................................................


class Car{
    protected:
        IEngine *engine;
    public:
        Car(IEngine *eng):engine(eng){};
        virtual void drive() = 0;
        virtual ~Car() {};
};

class Tesla : public Car{
    public:
        Tesla(IEngine *e):Car(e){};
        void drive() override{
            cout<<"Tesla ready to drive";
            engine->start();
        };
};
class Toyota : public Car{
    public:
        Toyota(IEngine *e):Car(e){};
        void drive() override{
            cout<<"Tesla ready to drive";
            engine->start();
        };
};
class Hyundai : public Car{
    public:
        Hyundai(IEngine *e):Car(e){};
        void drive() override{
            cout<<"Tesla ready to drive";
            engine->start();
        };
};



int main()
{
    IEngine *electric = new ElectricEngine();
    IEngine *diseal = new DisealEngine();
    IEngine *hybrid = new HybridEngine();

    Car *c1 = new Tesla(electric);
    Car *c2 = new Toyota(diseal);
    Car *c3 = new Hyundai(hybrid);

    c1->drive();
    c2->drive();
    c3->drive();

    delete electric;
    delete diseal;
    delete hybrid;
    delete c1, c2 , c3;
    return 0;
}