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
        cout << "Singh Burger : Normal Burger" << endl;
    }
};
class standardBurger : public burger
{
public:
    void preapre() override
    {
        cout << "Singh Burger : Standard Burger" << endl;
    }
};
class premiumBurger : public burger
{
public:
    void preapre() override
    {
        cout << "Singh Burger : Premium Burger" << endl;
    }
};
class normalWheatBurger : public burger
{
public:
    void preapre() override
    {
        cout << "King Burger : Normal Burger" << endl;
    }
};
class standardWheatBurger : public burger
{
public:
    void preapre() override
    {
        cout << "King Burger : Standard Burger" << endl;
    }
};
class premiumWheatBurger : public burger
{
public:
    void preapre() override
    {
        cout << "King Burger : Premium Burger" << endl;
    }
};


class factories{
    public:
        virtual burger* createBurger(string type) = 0;
        virtual ~factories(){};
};

class singhBurger : public factories{
    public:
        burger* createBurger(string burger_type) override{
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

class kingBurger : public factories{
    public:
        burger* createBurger(string burger_type) override{
                if(burger_type=="normal")
                    {
                        return new normalWheatBurger();
                    }

                else if(burger_type == "standard")
                    {
                        return new standardWheatBurger();
                    }
                else if(burger_type == "premium")
                    {
                        return new premiumWheatBurger();
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
        factories *singh_burger = new singhBurger();
        factories *king_burger = new kingBurger();
        burger *burger_name ;
        burger_name = king_burger->createBurger("premium");
        burger_name->preapre();
        burger_name = singh_burger->createBurger("standard");
        burger_name->preapre();
        return 0;
    }