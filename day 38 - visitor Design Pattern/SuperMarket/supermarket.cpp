#include <iostream>
#include <vector>
using namespace std;

class Grocery;
class Electronics;
class Clothing;

class IVisitor {
public:
    virtual void visit(Grocery* g) = 0;
    virtual void visit(Electronics* e) = 0;
    virtual void visit(Clothing* c) = 0;
    virtual ~IVisitor() {}
};

class Item {
public:
    virtual void accept(IVisitor* visitor) = 0;
    virtual ~Item() {}
};

class Grocery : public Item {
    double price;
public:
    Grocery(double p) : price(p) {}
    void accept(IVisitor* visitor) {
        visitor->visit(this);
    }
    double getPrice() const { return price; }
};

class Electronics : public Item {
    double price;
public:
    Electronics(double p) : price(p) {}
    void accept(IVisitor* visitor) {
        visitor->visit(this);
    }
    double getPrice() const { return price; }
};

class Clothing : public Item {
    double price;
public:
    Clothing(double p) : price(p) {}
    void accept(IVisitor* visitor) {
        visitor->visit(this);
    }
    double getPrice() const { return price; }
};

class DiscountVisitor : public IVisitor {
public:
    void visit(Grocery* g) {
        cout<<"\nGrocery\nAcutal Price Rs :"<<g->getPrice()<<"\n";
        cout << "Grocery price after Discount: Rs : " << g->getPrice() * 0.95 << endl;
    }
    void visit(Electronics* e) {
        cout<<"\nElectronics\nAcutal Price Rs :"<<e->getPrice()<<"\n";
        cout << "Electronics price after Discount: Rs : " << e->getPrice() * 0.90 << endl;
    }
    void visit(Clothing* c) {
        cout<<"\nClothing\nAcutal Price Rs :"<<c->getPrice()<<"\n";
        cout << "Clothing price after Discount: Rs : " << c->getPrice() * 0.85 << endl;
    }
};

int main() {
    vector<Item*> cart;
    cart.push_back(new Grocery(250));
    cart.push_back(new Electronics(30000));
    cart.push_back(new Clothing(4000));

    DiscountVisitor visitor;

    for (auto item : cart) {
        item->accept(&visitor);
    }

    for (auto item : cart) {
        delete item;
    }

    return 0;
}
