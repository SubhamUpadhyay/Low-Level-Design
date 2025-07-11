#include<bits/stdc++.h>
using namespace std;

class LaptopCharger
    {
        public:
            virtual void charge_the_laptop() = 0;
            ~LaptopCharger(){};

    };

class WallSocket{
    public:
        void wall_socket(){
            cout<<"Laptop is Charging"<<endl;
        }
};

class Adapter : public LaptopCharger{
    private:
        WallSocket *obj;
    public:
        Adapter(WallSocket *ws):obj(ws){};
        void charge_the_laptop()
            {
                obj->wall_socket();
            }
};


int main()
{
    WallSocket ws;
    Adapter *adpt = new Adapter(&ws);
    adpt->charge_the_laptop();
    return 0;
}