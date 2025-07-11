#include<bits/stdc++.h>
using namespace std;
class coffeeMachine{
    public:
        void makeCoffee()
            {
                cout<<"Making coffee"<<endl;
            }
};

class Button{
    private:
        coffeeMachine *machine;
    public:
        Button(coffeeMachine *obj):machine(obj){};
        void press()
            {
                machine->makeCoffee();
            }
};

int main()
{
    coffeeMachine obj1;
    Button coffeeButton(&obj1);
    coffeeButton.press();
    return 0;
}

//problems

/*


    ❗Problems:
Button is hardcoded to call makeCoffee(). You can’t easily change its behavior without editing the Button class.

No way to queue, undo, or log actions.

Violates Open/Closed Principle (open for extension, closed for modification).


*/
