#include<bits/stdc++.h>
using namespace std;
class PowerSupply{
    public:
    void ProvidePower()
        {
            cout<<"Power Provided"<<endl;
        }
};

class CPU{
    public:
        void initialize()
            {
                cout<<"CPU Intialized !"<<endl;
            }
};

class CoolingSystem{
    public:
        void startFans()
            {
                cout<<"Fans Started !"<<endl;
            }
};

class Memory{
    public:
        void selfTest()
            {
                cout<<"Memory Initializaton Successful !"<<endl;
            }
};

class Hardware{
    public:
        void spinUp()
            {
                cout<<"Hardware Initialization Successful !"<<endl;
            }
};
class OperatingSystem{
    public:
        void load()
            {
                cout<<"Operating System Started ! "<<endl;
            }
};

class BIOS{
    public:
        void boot(CPU *a , Memory *b)
            {
                a->initialize();
                b->selfTest();
            }
};

class Facade{
    private:
        PowerSupply ps;
        CPU cpu;
        CoolingSystem cls;
        Memory mm;
        Hardware hw;
        OperatingSystem os;
        BIOS bios;
    public:
        void startComputer()
            {
                cout<<endl<<"Computer Starting >>>>"<<endl;
                ps.ProvidePower();
                bios.boot(&cpu , &mm);
                cls.startFans();
                hw.spinUp();
                os.load();
                cout<<endl<<"Computer Boot UP successful ! <<<<"<<endl;
            }
};
int main()
    {
        Facade facade;
        facade.startComputer();
        return 0;
    }