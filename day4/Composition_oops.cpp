#include<bits/stdc++.h>
using namespace std;
class cls1{

    public:
        void fun1(){
            cout<<"This is cls1";
        }

};

class cls2{
    public:
        cls1 *objx;
        void fun2()
            {
                objx = new cls1{};
                objx->fun1();
            }
};
int main()
{

        cls2 *obj2 = new cls2{};
        obj2->fun2();
    return 0;
}