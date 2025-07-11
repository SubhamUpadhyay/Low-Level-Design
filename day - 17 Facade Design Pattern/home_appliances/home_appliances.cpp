#include <bits/stdc++.h>
using namespace std;

class AC
{
public:
    void RunAc()
    {
        cout << "ac is turn ON !" << endl;
    }
};

class TV
{
public:
    void RunTV()
    {
        cout << "TV is turned ON !" << endl;
    }
};

class Oven
{
public:
    void RunOven()
    {
        cout << "Oven is turned ON !" << endl;
    }
};

class Facade
{
private:
    AC *ac;
    TV *tv;
    Oven *oven;

public:
    Facade(AC *a, TV *b, Oven *c) : ac(a), tv(b), oven(c) {};


    void Runac()
        {
            ac->RunAc();
        }
    void runtv()
        {
            tv->RunTV();
        }
    void runoven()
        {
            oven->RunOven();
        }

    
    void RunAll()
    {
        ac->RunAc();
        tv->RunTV();
        oven->RunOven();
    }
};

int main()
{
    AC a;
    TV b;
    Oven c;
    unique_ptr<Facade>facad = make_unique<Facade>(&a,&b,&c);
    facad -> RunAll();


    /*
        auto facad = make_unique<Facade>(&a , &b , &c);
        you don't need to manually delte the obj unlike in Facade *facad = new Facade(&a , &b , &c );
    */
    return 0;
}