#include <iostream>
#include <string>
using namespace std;

//---------------------------------------------------------------
// 🧵 SCENARIO:
// Let's say we run a Clothing Store.
// A plain T-shirt can be customized by adding features:
//    - Printed Design
//    - Hoodie
//    - Pocket
// Each customization wraps the original T-shirt.
//---------------------------------------------------------------

// Component Interface
class TShirt {
public:
    virtual string getDescription() const = 0;
    virtual int getCost() const = 0;
    virtual ~TShirt() {}
};

//---------------------------------------------------------------
// Concrete Component: Plain T-shirt
class PlainTShirt : public TShirt {
public:
    string getDescription() const override {
        return "Plain T-Shirt";
    }

    int getCost() const override {
        return 300;  // base price
    }
};

//---------------------------------------------------------------
// Abstract Decorator: acts as a wrapper for TShirt
class TShirtDecorator : public TShirt {
protected:
    TShirt* tshirt;  // wrapped component

public:
    TShirtDecorator(TShirt* tshirt) : tshirt(tshirt) {}
};

//---------------------------------------------------------------
// Concrete Decorator: adds Printed Design
class PrintedDesign : public TShirtDecorator {
public:
    PrintedDesign(TShirt* tshirt) : TShirtDecorator(tshirt) {}

    string getDescription() const override {
        // 👇 delegates to base + adds own feature
        return tshirt->getDescription() + ", Printed Design";
    }

    int getCost() const override {
        return tshirt->getCost() + 150;  // adds extra cost
    }
};

//---------------------------------------------------------------
// Concrete Decorator: adds Hoodie
class Hoodie : public TShirtDecorator {
public:
    Hoodie(TShirt* tshirt) : TShirtDecorator(tshirt) {}

    string getDescription() const override {
        return tshirt->getDescription() + ", Hoodie";
    }

    int getCost() const override {
        return tshirt->getCost() + 200;
    }
};

//---------------------------------------------------------------
// Concrete Decorator: adds Pocket
class Pocket : public TShirtDecorator {
public:
    Pocket(TShirt* tshirt) : TShirtDecorator(tshirt) {}

    string getDescription() const override {
        return tshirt->getDescription() + ", Pocket";
    }

    int getCost() const override {
        return tshirt->getCost() + 50;
    }
};

//---------------------------------------------------------------
int main() {
    // 👕 Start with a plain T-shirt
    TShirt* tshirt = new PlainTShirt();

    // 🧵 Add a printed design
    tshirt = new PrintedDesign(tshirt);

    // 🧥 Add a hoodie
    tshirt = new Hoodie(tshirt);

    // 🎯 Add a pocket
    tshirt = new Pocket(tshirt);

    // 🧾 Final Output
    cout << "Final T-Shirt: " << tshirt->getDescription() << endl;
    cout << "Total Cost: Rs." << tshirt->getCost() << endl;

    // 🧹 Clean-up
    delete tshirt;  // only deletes the outermost decorator
                    // In real code, you'd make decorators own their component and delete them in destructor
    return 0;
}

//---------------------------------------------------------------
// 🧠 Concept Summary:
// - Instead of making 100 subclasses for every combination (e.g. TShirtWithHoodieAndPrintAndPocket),
//   we add decorators that wrap and extend functionality dynamically.
// - Decorators follow "has-a" relation (composition), not "is-a" (inheritance chain only).
// - It's flexible and follows Open/Closed principle.
// - ❗ When deleting, we only delete the outermost wrapper. For complete cleanup,
//   either use smart pointers or manage memory properly.
//---------------------------------------------------------------
