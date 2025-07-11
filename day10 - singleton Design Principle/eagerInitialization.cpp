#include<bits/stdc++.h>
using namespace std;
class singleton{
    private:
    static singleton* that_address;

    //lock for thread safety 
    static mutex mtx;
    singleton()
    {
        cout<<endl<<"Object Created !"<<endl;
    }

    public:
    static singleton* getInstance()
        {
            return that_address;
        }
};


//decleartion of static member outside the class

// *singleton::that_address=nullptr;  this is an static definiton and the single singletion is the class 
singleton *singleton::that_address= new singleton(); 
int main()
{
    singleton *obj1 = singleton::getInstance();
    singleton *obj2 = singleton::getInstance();


    cout<<obj1<<" --------------------------"<<obj2;

    return 0;
}