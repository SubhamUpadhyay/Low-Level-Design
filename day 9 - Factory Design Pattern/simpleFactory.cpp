#include <bits/stdc++.h>
using namespace std;

class burger
{
public:
    virtual void preapre() = 0;
    virtual ~burger(){};
};
class normalBurger : public burger
{
public:
    void preapre() override
    {
        cout << "Normal Burger" << endl;
    }
};
class standardBurger : public burger
{
public:
    void preapre() override
    {
        cout << "Standard Burger" << endl;
    }
};
class premiumBurger : public burger
{
public:
    void preapre() override
    {
        cout << "Premium Burger" << endl;
    }
};

class burgerFactory
{
    public:
        burger* preapreBurger(string burger_type)
            {
                if(burger_type=="normal")
                    {
                        return new normalBurger();
                    }

                else if(burger_type == "standard")
                    {
                        return new standardBurger();
                    }
                else if(burger_type == "premium")
                    {
                        return new premiumBurger();
                    }
                else
                    {
                        cout<<endl<<burger_type<<" Burger cannot be preapre at a moment !"<<endl;
                        return nullptr;
                    }
            }
};
int main()
{
    burgerFactory *obj1 = new burgerFactory();
    burger *which_burger = obj1->preapreBurger("abc");
    which_burger->preapre();    
    return 0;
}