#include<bits/stdc++.h>
using namespace std;

class Earth{};
class Animal : public Earth{};
class Dog : public Animal{};
class c1{
    public:
    virtual Animal* fun1()
        {
            cout<<"c1.fun1()"<<endl;
            return new Animal;
        }
};
class c2 : public c1{
    public:
        Dog* fun1() override{
            cout<<"C2.fun1()"<<endl;
            return new Dog();
        }
};
int main(){
    c1 *obj1 = new c1{};
    Animal *a = obj1 ->fun1();
    delete a;
    delete obj1;
    return 0;
};

