#include<bits/stdc++.h>
using namespace std;
class Command{
    public:
        virtual void execute() = 0;
        virtual ~Command(){};
};

class CoffeeMachine{
    public:
        void makeCoffee()
            {
                cout<<"making coffee ..."<<endl;
            }
};

class MakeCoffeeCommand:public Command{
    private:
        CoffeeMachine *machine;
    public:
        MakeCoffeeCommand(CoffeeMachine *obj):machine(obj){};
        void execute() override{
            machine->makeCoffee();
        };
};

//Invoker (Button);
class Button{
    private:
        Command *cmd;
    public:
    Button(Command *obj):cmd(obj){};
    void press()   
        {
            cmd->execute();
        }
};

int main(){
    CoffeeMachine myMachine;
    MakeCoffeeCommand makeCoffee(&myMachine);
    Button coffeeButton(&makeCoffee);
    coffeeButton.press();
    return 0;
};