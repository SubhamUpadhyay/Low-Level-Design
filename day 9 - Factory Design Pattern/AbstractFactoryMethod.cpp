#include <bits/stdc++.h>
using namespace std;
class burger
{
public:
    virtual void preapre() = 0;
    virtual ~burger(){};
};


//Normal Burger & Garlic Bread
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

class garlicBread:public burger{
    public:
        void preapre() override{
            cout<<"Singh Burger : Garlic bread"<<endl;
        }
};





//Normal Wheat Burger & Wheat Garlic Bread
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
class wheatGarlicBread : public burger{
    public:
    void preapre() override{
        cout<<"King Burger : Garlic Bread"<<endl;
    }
};




class factories{
    public:
    virtual burger* createBurger(string type_) = 0;
    virtual burger* createGarlicBread(string type_) = 0;
    virtual ~factories(){};
};

class singhBurger : public factories{
    public:
        burger* createBurger(string burger_type) override
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

        burger* createGarlicBread(string garlic_bread_type) override
            {
                if(garlic_bread_type == "normal")
                    return new garlicBread();
                else
                    {
                        cout<<endl<<garlic_bread_type<<" not available !";
                        return nullptr;
                    }
                
            }
};


class kingBurger : public factories{
    public:
        burger* createBurger(string burger_type) override
            {   
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

        burger* createGarlicBread(string garlic_bread_type) override
            {
                if(garlic_bread_type == "normal")
                    return new wheatGarlicBread();
                else
                    {
                        cout<<endl<<garlic_bread_type<<" not available !";
                        return nullptr;
                    }
                
            }
};


int main()
    {
        factories *king_burger = new kingBurger();
        burger *burger_ty;
            burger_ty = king_burger->createBurger("normal");
            burger_ty->preapre();

            burger_ty = king_burger->createGarlicBread("alskdf");
            burger_ty->preapre();
    }