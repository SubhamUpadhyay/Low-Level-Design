#include <bits/stdc++.h>
using namespace std;
class Handler
{
protected:
    Handler *nextHandler;

public:
    Handler() : nextHandler(nullptr) {};
    void setHandler(Handler *next)
        {
            nextHandler = next;
        }
    virtual void dispense(int amt) = 0;
    ~Handler(){};
};
class FiveHunderdDispenser : public Handler
{
private:
    int count;

public:
    FiveHunderdDispenser() : count(20) {};
    void dispense(int amount) override
    {
        if(count ==0)
            {
                cout<<"cannot dispense "<<amount<<endl;
                return ;
            }

       else if(amount >= 500)
        {
            int num = min(amount/500,count);
            int reamining = amount - (num *500);
            count -= num;
            cout<<"Dispensing "<<num<<" notes of 500\n";
            if(reamining !=0 && nextHandler != nullptr)
                nextHandler->dispense(reamining);
            else if(reamining != 0)
                cout<<"Cannot Dispense Reamining amount !"<<reamining<<"\n";
            
        }
        else if(nextHandler != nullptr)
            {
                nextHandler -> dispense(amount);
            }
        else
            {
                cout<<"Cannot Dispense Amount !"<<amount<<endl;
            }
    };
};

class HundredRupeeDispenser : public Handler
{
private:
    int count;

public:
    HundredRupeeDispenser() : count(100) {};
    void dispense(int amount) override
    {
        if(amount %100 !=0)
            {
                cout<<"Cannot Dispense non-multiple of 100"<<endl;
                return ;
            }
        int num = min(amount/100 , count);
        int reamining = amount - (num *100);
        count-=num;
        cout<<"Dispensing "<<num<<" notes of 100\n";
        if(reamining !=0 && nextHandler != nullptr)
            {
                nextHandler->dispense(reamining);
            }
        else if(reamining != 0)
            {
                cout<<"Cannot Dispense Reamining Amount "<<reamining<<endl;
            }
    };
};




int main()
{
    Handler *fiveHundred = new FiveHunderdDispenser();
    Handler *hundred = new HundredRupeeDispenser();

    fiveHundred->setHandler(hundred);

    int amount = 4500;
    cout<<"Requesting amount "<<amount<<" rupees \n";
    fiveHundred->dispense(amount);

    cout<<"\n Requesting : 4600 rupees \n";
    fiveHundred->dispense(4600);

    cout<<"\n Requesting 4700 rupees\n";
    fiveHundred->dispense(4700);

    cout<<"\n Requesting 123 rupees -> invalid \n";
    fiveHundred->dispense(123);

    delete fiveHundred;
    delete hundred;
    return 0;
}