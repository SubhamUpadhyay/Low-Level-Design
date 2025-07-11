#include<bits/stdc++.h>
using namespace std;
class PreapreBeverage{
    public:
        void makeBeverage(int sugarQuantity,string name)
            {
                boilWater();
                addIngedriant();
                pourIntoCup(name);
                addSugar(sugarQuantity);
            }
        void boilWater()
            {
                cout<<"Boiling the Water"<<endl;
            }
        virtual void addIngedriant() = 0;
        void pourIntoCup(string name)
            {
                cout<<"Poured "<<name<<" into the cup"<<endl;
            }
        void addSugar(int spoon)
            {
                cout<<"Addeed "<<spoon<<" spoon of sugar"<<endl;
            }
};

class PreapreTea:public PreapreBeverage{
    public:
        void addIngedriant() override{
            cout<<"Added Tea leaves"<<endl;
            
        };   
        
};
class PreapreCoffee:public PreapreBeverage{
    public:
        void addIngedriant() override{
            cout<<"Added Coffee Powder"<<endl;
        };
        
};
int main()
    {
        PreapreBeverage *tea = new PreapreTea;
        PreapreBeverage *coffee = new PreapreCoffee;
        cout<<"Making Tea ......"<<endl;
        tea->makeBeverage(2,"Tea");

        cout<<"\n\n\n\nMaking Coffee";
        coffee->makeBeverage(3,"Coffee");

        return 0;
    }