#include<bits/stdc++.h>
using namespace std;
class parent{
    public:
    virtual void print(string s)
        {
            cout<<"Parent Class :"<<s;
        }
};

class child : public parent {
    public:
    void print(string s) override{
        cout<<"Child Class :"<<s;
    }
};

class client{
    private:
        parent *parent_;
    public:
        client(parent *p)
            {
                parent_ = p;
            }

        void printMessage()
            {
                parent_ ->print("Hello");
            }
};

int main()
    {
        parent *p1 = new parent{};
        child *c1 = new child{};
        client *cl1 = new client{c1};

        cl1->printMessage();

        return 0;
    }