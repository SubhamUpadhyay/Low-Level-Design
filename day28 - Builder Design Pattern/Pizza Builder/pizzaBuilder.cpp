#include <bits/stdc++.h>
using namespace std;

class Pizza
{
private:
    string base;
    string sauce;
    string topping;
    Pizza() {};

    friend class PizzaBuilder;

public:
    void showPizza()
    {
        cout << "Pizza with " << base << " base ,  " << sauce << " sauce , " << topping << " topping.\n";
    }
};

class PizzaBuilder
{
private:
    // Pizza *p --> cannot create the object of Pizza using the new keyword
    Pizza p;

public:
    // set base , sauce and topping
    PizzaBuilder &setBase(const string &b)
    {
        p.base = b;
        return *this;
    }
    PizzaBuilder &setSauce(const string &b)
    {
        p.sauce = b;
        return *this;
    }
    PizzaBuilder &setTopping(const string &b)
    {
        p.topping = b;
        return *this;
    }
    Pizza build()
    {
        return p;
    }
};

int main()
{
    Pizza myPizza = PizzaBuilder()
                        .setBase("Thin Crust")
                        .setSauce("Tomato")
                        .setTopping("Cheese")
                        .build();  //-> build is called terminating method
    myPizza.showPizza();
    return 0;
}