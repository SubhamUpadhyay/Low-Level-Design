#include <iostream>
using namespace std;

// ------------ Implementation Layer ------------
class Engine {
public:
    virtual void start() = 0;
    virtual ~Engine() {}
};

class ElectricEngine : public Engine {
public:
    void start() override {
        cout << "Starting electric engine silently\n";
    }
};

class DieselEngine : public Engine {
public:
    void start() override {
        cout << "Starting diesel engine with rumble\n";
    }
};

class HybridEngine : public Engine {
public:
    void start() override {
        cout << "Starting hybrid engine with eco-mode\n";
    }
};

// ------------ Abstraction Layer ------------
class Car {
protected:
    Engine* engine;
public:
    Car(Engine* e) : engine(e) {}
    virtual void drive() = 0;
    virtual ~Car() {}
};

class Toyota : public Car {
public:
    Toyota(Engine* e) : Car(e) {}

    void drive() override {
        cout << "Toyota ready to drive. ";
        engine->start();
    }
};

class Tesla : public Car {
public:
    Tesla(Engine* e) : Car(e) {}

    void drive() override {
        cout << "Tesla ready to drive. ";
        engine->start();
    }
};

class Hyundai : public Car {
public:
    Hyundai(Engine* e) : Car(e) {}

    void drive() override {
        cout << "Hyundai ready to drive. ";
        engine->start();
    }
};


int main() {
    Engine* electric = new ElectricEngine();
    Engine* diesel = new DieselEngine();
    Engine* hybrid = new HybridEngine();

    Car* car1 = new Tesla(electric);
    Car* car2 = new Toyota(diesel);
    Car* car3 = new Hyundai(hybrid);

    car1->drive();  
    car2->drive();  
    car3->drive();  

    delete car1;
    delete car2;
    delete car3;
    delete electric;
    delete diesel;
    delete hybrid;

    return 0;
}
