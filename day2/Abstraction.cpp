//Focuses on Data Hiding 


#include<bits/stdc++.h>
using namespace std;
class car{
    public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    //destructor
    virtual ~car(){}; 
};
//virtual void so basically says that the method have only been declared here not define the child class will define this function / method

class SportsCar : public car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
    //constructor for the class sportCar

        SportsCar(string b ,string m)
            {
                this->brand = b;
                this->model = m;
                isEngineOn = false;
                currentSpeed = 0;
                currentGear  = 0;
            }

        void startEngine()
            {
                isEngineOn = true;
                cout<<brand<<" "<<model<<" Engine starts with a roar !"<<endl;
            }

        void shiftGear(int gear )
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! cannot shift Gear !"<<endl;
                        return;
                    }
                if(gear >5)
                    {
                        cout<<brand<<" "<<model<<" cannot shift gear to "<<gear<<" , can only shift to 5 and can reverse "<<endl;
                        return;
                    }
                currentGear = gear;
                cout<<brand<<" "<<model<<" Shifted to Gear "<<currentGear<<endl;
            }

        void accelerate()
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! cannot Accelerate !"<<endl;
                        return;
                    }
                currentSpeed +=20;
                cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<" km/hr" <<endl;
            }

        void brake()
            {
                if(!isEngineOn)
                    {
                        cout<<brand<<" "<<model<<" : Engine is off ! no need to brake !"<<endl;
                        return;
                    }
                currentSpeed-=20;
                if(currentSpeed<0)
                    currentSpeed=0;
                cout<<brand<<" "<<model<< " : Braking! Speed is now "<<currentSpeed<<" km/hr"<<endl;
            }
        void stopEngine(){
            if(!isEngineOn)
                {
                    cout<<brand<<" "<<model<<" : Engine is already off!"<<endl;
                        return;
                }
            isEngineOn = false;
            currentGear = 0;
            currentSpeed= 0;
            cout<<brand<<" "<<model<<" : Engine truned off!"<<endl;
        }
};

int main()
{
    //parent class - > class name  = new keyword child class constructor call

    car *new_car = new SportsCar("Ford","Mustang");
    new_car->startEngine();
    new_car -> shiftGear(35);
    new_car -> accelerate();
    new_car -> brake();
    new_car -> stopEngine();
    return 0;
}





/* 
    problem:
    so once the gear is set to more than 5 or less than 0 then rest of the function call shouldn't be executed because shifting gear to wrong number won't start the car isn't it?

 */ 




