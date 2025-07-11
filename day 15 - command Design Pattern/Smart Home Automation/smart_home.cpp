#include<bits/stdc++.h>
using namespace std;
//command Interface 
class Command{
    public:
        virtual void execute() = 0;
        ~Command(){};
};
//Recievers
class LightBulb{
    private:
        bool isOn = false;
    public:


        void turnOn()
            {
                if(!isOn)
                    {
                        cout<<"Light Bulb is Already On . "<<endl;

                    }
                else
                    {
                        isOn = true;
                        cout<<" Light Bulb Turned On"<<endl;
                    }
            }
        void turnOff()
            {
                if(isOn)
                    {
                        cout<<"Light Bulb is Already Off! "<<endl;
                    }
                else
                    {
                        isOn = false;
                        cout<<"Light Bulb Turned Off !"<<endl;
                    }
            }
};
class Fan {
    bool isOn = false;
public:
    void turnOn() {
        if (isOn)
            cout << "Fan is already ON."<<endl;
        else {
            isOn = true;
            cout << "Fan Turned ON"<<endl;
        }
    }
    void turnOff() {
        if (!isOn)
            cout << "Fan is already OFF."<<endl;
        else {
            isOn = false;
            cout << "Fan Turned OFF"<<endl;
        }
    }
};
class AC {
    bool isOn = false;
public:
    void turnOn() {
        if (isOn)
            cout << "AC is already ON."<<endl;
        else {
            isOn = true;
            cout << "AC Turned ON"<<endl;
        }
    }
    void turnOff() {
        if (!isOn)
            cout << "AC is already OFF."<<endl;
        else {
            isOn = false;
            cout << "AC Turned OFF"<<endl;
        }
    }
};


//Concerte On Command


class LightOnCommand:public Command{
    private:
        LightBulb *bulb;
    public:
        LightOnCommand(LightBulb *obj):bulb(obj){};
        void execute() override{
            bulb->turnOn();
        }
};
class FanOnCommand:public Command{
    private:
        Fan *fan;
    public:
        FanOnCommand(Fan *obj):fan(obj){};
        void execute() override{
            fan->turnOn();
        }
};
class AcOnCommand:public Command{
    private:
        AC *ac;
    public:
        AcOnCommand(AC *obj):ac(obj){};
        void execute() override{
            ac->turnOn();
        }
};

// Concrete OFF Commands
class LightOffCommand : public Command {
    LightBulb* bulb;
public:
    LightOffCommand(LightBulb* obj) : bulb(obj) {}
    void execute() override {
        bulb->turnOff();
    }
};
class FanOffCommand : public Command {
    Fan* fan;
public:
    FanOffCommand(Fan* obj) : fan(obj) {}
    void execute() override {
        fan->turnOff();
    }
};
class AcOffCommand : public Command {
    AC* ac;
public:
    AcOffCommand(AC* obj) : ac(obj) {}
    void execute() override {
        ac->turnOff();
    }
};


//Invoker
class Remote{
    private:
        Command *cmd;
    public:
        Remote(Command *obj):cmd(obj){};
        void pressButton()  
            {
                cmd->execute();
            }
};



int main()
{
     LightBulb bulb;
    Fan fan;
    AC ac;

    LightOnCommand lightOn(&bulb);
    LightOffCommand lightOff(&bulb);

    FanOnCommand fanOn(&fan);
    FanOffCommand fanOff(&fan);

    AcOnCommand acOn(&ac);
    AcOffCommand acOff(&ac);

    Remote remote1(&fanOn);
    Remote remote2(&fanOff);

    remote1.pressButton();  
    remote1.pressButton();  
    remote2.pressButton(); 
    remote2.pressButton();  

    return 0;
}